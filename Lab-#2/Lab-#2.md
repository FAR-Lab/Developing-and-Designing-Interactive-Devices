In this Lab, we will use the Interaction Engine for an interactive webcam application.

## Overview
1. Set up Arduino connection
* Connect Arduino.
* Flash sample `Blink.ino` program.
* Check that Arduino is running program.
2. HelloYou test
* Flash helloYou firmware to Arduino.
* Run the node program.
* Test the functionality with a remote browser.
3. Distant Pictures 
* [Fork](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Forking-a-GitHub-project) the [distant-picture](https://github.com/FAR-Lab/distant-pictures) example project.
* Plug the webcam into the Pi.
* Run the node program.
* Test the functionality with the remote browser.
4. Make it your own
5. Submit

## Detailed steps

### 1. Set up Arduino connection
* You will need to power the Raspberry Pi with the AC adapter because you will need the USB cable from the class kit to connect the Pi to the Arduino.
* Physically connect Arduino to the Pi using the USB cable.

<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/pi+arduino.JPG" width="400px">

* Flash the sample `Blink.ino` program to make sure the connection to the Arduino is sound. _(We will go into more detail on how to program the Arduino, compile code, etc. in the next lab.)_
  * Login into your Raspberry Pi.
  * In the `~/sketchbook/blink` directory, type `make upload` to flash the pre-compiled `Blink.ino` code to the Arduino
```
pi@ixeXX:~ $ cd sketchbook/blink
pi@ixeXX:~/sketchbook/blink $ ls
blink.ino  build-uno  makefile
pi@ixeXX:~/sketchbook/blink $ make upload
```
 The Arduino LEDs should flash rapidly while the code is being flashed onto the Arduino, and then the red onboard LED should blink on and off at a 10 Hz rate.
  * Problems? Try [checking the port assigned to the Arduino.](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Check-port-of-Arduino-board).
  * Curious how things work? Try [looking at the `Blink.ino` code](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Blink.ino,--Annotated)

### 2. HelloYou test

We have demonstrated this example in class. We will have a button connected to an Arduino attached to the IxE via a USB cable change the background color of our webpage. Then we can use a button on the webpage to turn an LED on the Arduino on and off.
* Set up the Arduino button circuit (We will also go deeper into the electronics in the next lab.)
On your breadboard, make this [basic button circuit](#basic-button-circuit) connected to `pin 2` of the Arduino. (The LED is built in on the board and connected to `pin 13`.)
<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/button_circuit.png" width="200px">
<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/metroCircuit.png" width="400px"> 
<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/realCircuit.jpg" width="400px">

* Flash the pre-compiled `HelloYou.ino` code onto the Arduino. 
```
pi@ixeXX:~ $ cd ~/sketchbook/helloYouSketch/
pi@ixeXX:~/sketchbook/helloYouSketch $ make upload
```
Now that the Arduino code is uploaded, you should see your LED is off (because it isn't running the Blink sketch anymore).

* Run the HelloYou webserver.
```
pi@ixeXX:~/sketchbook/helloYouSketch $ cd
pi@ixeXX:~ $ cd helloYou/
pi@ixeXX:~/helloYou $ ls
helloYouSketch.ino  package.json  public  README.md  server.js
pi@ixeXX:~/helloYou $ node server.js /dev/ttyUSB0
listening on *:8000
```
* Test the functionality with remote browser.

If everything is working, you should see a message in the terminal that the webserver is listening on port 8000.

Now, you can go to your web browser and type your `http://ixe[hostnumber]:8000` in the address bar.

* Look at the `server.js`, `public/client.js` and `public/index.html` code to understand what parts of the code do various things. 

### 3. Distant Pictures

The Distant Pictures lab is based on HelloYou, but has a web camera added. We make use of the 'node-webcam' from [[https://www.npmjs.com/package/node-webcam]] to add the camera functionality.

* Fork the 'distant-picture' example project
On your IxE, [fork](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Forking-a-GitHub-project) and git clone the [distant-picture](https://github.com/FAR-Lab/distant-pictures) example project.

`pi@ixeXX:~ $ git clone https://github.com/**_YourUserName_**/distant-pictures.git`

In the `distant-pictures` directory, install the basic components for the node server by executing `npm install` 
```
pi@ixeXX:~ $ cd distant-pictures
pi@ixeXX:~/distant-pictures $ npm install
up to date in 7.778s
```
* We are using the helloYou Arduino circuit and code, so no adjustment is necessary on the Arduino side. Keep it plugged into the USB port of the Pi.
* Plug in the web camera to another USB port of the Raspberry Pi.
* Try pictureServer with node.js
```
pi@ixeXX:~/distant-pictures $ node pictureServer.js /dev/ttyUSB0
listening on *:8000
```
If everything is working, you should see a message in the terminal that the webserver is listening on port 8000.

Just like in the previous section, you can now go to the browser to control the Arduino and webcam. 
<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/distantPicture.png" width="400px">

To shut down the server, type `control + C` in the terminal.

```shell
ledOFF
ledON
^C
pi@ixeXX ~/distant-pictures $
```
* What changed

Compare `helloYou/server.js` and `distant-pictures/pictureServer.js`. What elements had to be added or changed to enable the web camera? (Hint: It might be good to know that there is a UNIX command called `diff` that compares files.)

* Peephole

Now, edit the `pictureServer.js` code for a Peephole device. When a person presses the doorbell (here, the button on your Arduino), the application should snap a photo of the person in front of the doorbell, and post it to a remote webpage. 

Please submit the code for the Peephole as part of your turn-in.

### 4.  Make it your own

Now, extend the functionality of this basic setup. 

* Your own distributed camera app

As in the previous lab, modify the template for the lab to make it your own. You can do this just through text, better html and reframing the point of view, or you can incorporate technical improvements from the next part of the assignment...

* Try a new node library/package

Find, install, and try out a node-based library and try to incorporate into your lab. 

Document your successes and failures (totally okay!) for your Slack lab#2 turn-in. This will help the class community figure out cool new tools and capabilities. A good source for possible library ideas is your assignment #2.

Here is an example of how to try this. Following the directions on the `https://www.npmjs.com/package/nyan-cat` package, for example:
```
pi@ixeXX:~/test $ sudo npm install -g nyancat
```

Some ideas, in case you are stuck:

On Linux, `node-webcam` uses `fswebcam`. https://www.npmjs.com/package/node-webcam shows other commands available using node-webcam, and typing `man fswebcam` describes a variety of image capture options. Try out some modifications, and show us the screen capture of the resulting webpage.

Another package to try: `gm`. GM is GraphicsMagick and ImageMagick for node. https://www.npmjs.com/package/gm 


### 5. Submit the lab

1. Upload a video of your version of the camera lab to your personal Slack channel and cross post to #lab2. **Make sure you've included the TAs: David Goedicke and Andrea Cuadra** and please shoot the video in **Horizontal/Landsacape** format.
1. Include a link to your forked code for the camera lab
1. Include brief description of what you did and why
1. Also, if it was separate from your lab project, post a summary of your npm experiment and post to #lab2