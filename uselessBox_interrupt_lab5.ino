// Useless Box Lab 5
//
// This example uses an interrupt on pin 2 to detect changes to the toggle
// switch position atop a useless box.
//
// If we see a voltage change on pin 2 the registered interrupt handler ToggleSwitch() is called.
//    A HIGH value on pin 2 means we should activate the servo to open the useless 
//    box and return the switch to the "off" position.
//    A LOW value on pin 2 means the switch is off and we should return to our 
//    inital (closed box) state.
//

#include <Servo.h> 

// Sweeper is a simple wrapper class for Servo that toggles a servo between two predetermined positions.
class Sweeper
{
  
private:
   Servo servo;
   static const int closedPos = 0;
   static const int openPos = 180;

public: 
  // constructor
  Sweeper() {}

  // Tell us the pin number is the servo control wire attached to.
  // Attach will set the pin to OUTPUT for pwm control of a servo.
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }

  // reset the servo position to our initial state
  void Reset()
  {
    servo.write(closedPos);
  }

  // set the servo to its "open box" position.  this should move the attached
  // servo arm enough to open the box and trigger the toggle switch back to off,
  // which will tell our servo to return to its initial postion.
  void Activate()
  {
    servo.write(openPos);
  }
};

Sweeper myServo;

//volatile bool switchChanged = false;  // this flag is used to send switch state info to the serial port
volatile int previousSwitchState = LOW;

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Useless Box Lab 5");
  
  myServo.Attach(10);
  myServo.Reset();

  pinMode(2, INPUT); 

  // this line causes the ToggleSwitch() interrupt service routine to be called if the state of pin 2 changes
  attachInterrupt(digitalPinToInterrupt(2), ToggleSwitch, CHANGE);
}

// this is called when the input on pin 2 changes (LOW to HIGH *or* HIGH to LOW)
void ToggleSwitch()
{
  int switchState = digitalRead(2);
    
  if (switchState != previousSwitchState)
  {
    //switchChanged = true; // look for this flag in loop() in order to send state info to the serial port.
    if (switchState == HIGH)
      myServo.Activate();
    else
      myServo.Reset();

    previousSwitchState = switchState;  // remember that the switch state has changed
  } 
}
  
void loop()
{ 
  // Interrupt service routines should be small and fast, since other interrupts cannot be serviced while the 
  // processor is in the middle of handling an interrupt. Because of this it is bad form to write to the serial port
  // inside an interrupt handler.  Insted we can set a flag inside ToggleSwitch() telling us the switch
  // state has changed, which we notice here in the main loop.  This allows us to log the swtich state change 
  // to the serial port here in the main loop.
  //  
  //if (switchChanged)
  //{
  //  switchChanged = false;
  //
  //  int switchState = digitalRead(2);
  //  if (switchState == HIGH)
  //    Serial.println("switch state is HIGH.  calling myServo.Activate() to open useless box");
  //  else
  //    Serial.println("switch state is LOW.   calling myServo.Reset() to close useless box");
  //}
}
