# Lab #1 - overview:
1. Create a [GitHub account](https://github.com) or use the [Cornell GitHub](https://github.coecis.cornell.edu/) with your NetID unless you already have an account you want to use for this class.
1. Familiarize yourself with the [UNIX Commands](https://www.tjhsst.edu/~dhyatt/superap/unixcmd.html). This [UNIX cheatsheet](https://ubuntudanmark.dk/filer/fwunixref.pdf) might also help.
1. Connect to your [Interaction Engine(IxE) / Raspberry Pi](#connect-to-your-interaction-engine)
1. Run the [ChatBot Example](#setup-and-run-the-chatbot-example)
1. Modify the ChatBot to make it your own. 
1. Record someone else trying out your ChatBot.
1. [Submitting the forked GitHub link](#submitting-the-code)

## Connect to class WiFi
For this first assignment to work, please connect your laptop to our class WiFi.

__if__ you are sitting in the __front__ half of the class => connect to DeviceFarm-5G

__if__ you are sitting in the __back__ half of the class => connect to DeviceFarm-5G-2

We will share the password for these networks in class.

---
## Instruction on how to connect to your home WiFi or computer can be found [here](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Other-ways-to-connect-IxE-to-your-computer).
---
## Connect to your Interaction Engine

Replace **[00]** with your interaction engine number on your SD card.

### If your laptop is on eduroam or RedRover and your IxE is on DeviceFarm in **BLOOMBERG**
For SSH use:
```
ssh pi@interactive-device-design-2.tech.cornell.edu -p 122[00]  
```

Connect to the Website
```
interactive-device-design-2.tech.cornell.edu:280[00]
```

### If your laptop is on eduroam or RedRover and your IxE is on DeviceFarm in **TATA**
For SSH use:
```
ssh pi@interactive-device-design-1.tech.cornell.edu -p 122[00]  
```

Connect to the Website
```
interactive-device-design-1.tech.cornell.edu:280[00]
```

### If your laptop is on DeviceFarm, The House, or your own WiFi network:

For SSH use:
```
ssh pi@ixe[00].local  
```

Connect to the Website
```
ixe[00].local:8000
```

Instructions to get the pi running on your local network are here, please try them out and help us debug them: https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Other-ways-to-connect-IxE-to-your-computer.

--- 

This is a copy of the [original resources](https://github.com/nikmart/interaction-engine/wiki/Log-on-to-your-Interaction-Engine).
In this tutorial, we will ssh into the system so that we can control the computer via Terminal or PuTTy on Windows.

**_In this example we often use `ixe[00].local`. This ONLY works if you are connected locally. if you are connected remotely or through the device arm WiFi, please replace the addresses with the ones explained in [If your laptop is on eduroam or RedRover and your IxE is on DeviceFarm](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Lab-%231#if-your-laptop-is-on-eduroam-or-redrover-and-your-ixe-is-on-devicefarm)._**


### 1. Verify IxE is online
TL,DR
1. `ping` + `ixe[00].local` (change the last digits, and remove the brackets to match yours)
2. Is it running? If yes, cool. `control + C` and move on to step 2.

LONGER VERSION

First, `ping` the system to make sure it is online. (If not, [troubleshoot](Getting-an-IxE-based-Pi-on-your-Wi-Fi#troubleshooting) to get it online). Remember your IxE will be named something like `ixe##` where the number corresponds to the number on the SD card (ex: ixe01, ixe04, ixe11). You can use `control + C` to exit the ping (this looks like `^C` in the terminal).

```shell
nik@DN51sk9s:~$ ping ixe05.local
PING ixe05.local (192.168.2.2): 56 data bytes
64 bytes from 192.168.2.2: icmp_seq=0 ttl=64 time=0.467 ms
64 bytes from 192.168.2.2: icmp_seq=1 ttl=64 time=0.471 ms
64 bytes from 192.168.2.2: icmp_seq=2 ttl=64 time=0.550 ms
64 bytes from 192.168.2.2: icmp_seq=3 ttl=64 time=0.670 ms
64 bytes from 192.168.2.2: icmp_seq=4 ttl=64 time=0.720 ms
^C
--- ixe05.local ping statistics ---
5 packets transmitted, 5 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 0.467/0.576/0.720/0.103 ms
```

### 2.  SSH into the IxE.
Log in to your Pi using the command `ssh pi@ixe[00].local` with the password: `raspberry`

When you first log in it will ask you if you want to continue connecting. Say `yes`

```shell
ssh pi@ixe00.local
The authenticity of host 'ixe00.local (fe80::1216:6c33:ec58:34a5%en0)' can't be established.
ECDSA key fingerprint is SHA256:Y9S4oMH2H70fz3K/L42Kw39k+zkpyfr0DmGdzBx7SKk.
Are you sure you want to continue connecting (yes/no)? yes
```
After you say yes, type the password `raspberry` and hit Enter. You should see this:

```shell
i@ixe00.local's password:
Linux ixe00 4.9.59-v7+ #1047 SMP Sun Oct 29 12:19:23 GMT 2017 armv7l

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Jan 17 10:42:03 2018

SSH is enabled and the default password for the 'pi' user has not been changed.
This is a security risk - please login as the 'pi' user and type 'passwd' to set a new password.

pi@ixe00:~ $ 
```

Once you are signed in, your terminal will now be the terminal for the IxE. You can tell this by looking at the user and hostname at the beginning of each line, which should now look like:

```shell
pi@ixe05 ~ $
```





## Setup and run the ChatBot Example
Welcome to the simple-ChatBot wiki!
### Installation
Clone(download) the repository from GitHub to the IxE. 
1. Go to the home folder with ```cd ~```
1. Frok the github project you are trying to download, by clicking the fork button on the top right side.
1. Copy the link to your forked version of the project.(for more information on forking look [here](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Forking-a-GitHub-project)). 
1. Clone the git repository with
```
git clone https://github.com/**_YOURUSERNAME_**/simple-ChatBot simple-ChatBot
```
1. Change directory into the downloaded folder with ```cd simple-ChatBot```
1. Let ```npm``` install the required node packages with ```npm install```
At this point, you will have downloaded the main program and all required packages to run it. 

### Start-Up
Now we need to start the server and connect to it with a browser.
We start the server by typing ```node chatServer.js```
In a browser go to ```ixe[00].local:8000``` (replace the [00] with the number associated with that interaction engine).
Once loaded, you should see a text field and the first greeting from the ChatBot.

#### Debugging
If the previous steps did not work there are a few things you can easily check/debug:
First, verify that the server is running. The command line window from your ixe[00] should say
```shell 
pi@ixe[00]:~/simple-ChatBot $node chatServer.js 
listening on *:8000
a new user connected
```
If that is not the case, verify that you are in the right folder and have done all the necessary steps to installing the additional packages. One way to verify that is by typing ```pwd``` to see if you really are working in the correct directory. The answer that pops-up should be something like ```/home/pi/simple-ChatBot```. Verify that you have all files in the folder with ```ls ```. The item list should be 
```shell 
pi@ixe[00]:~/test/simple-ChatBot $ ls
chatServer.js  license.txt  node_modules  package.json  package-lock.json  public  README.txt
```
If files are missing or you are not in the correct folder change to the correct folder location and try to re-run the instructions from the tutorial.
  
Second, make sure that you are connected to the same network as the interaction engine. This type of server is typically only routed/addressable locally i.e. when you are on the same network.

## Understanding the code

### chatServer.js (The RPi code)
The chatServer.js code is written in javascript. It is run on the IxE using [node.js](https://en.wikipedia.org/wiki/Node.js). This code handles the different client interactions and manages the network connections. 


### index.html and index.js (The browser code)
Index.html is written in HTML, but with javascript embedded. The index.js code acts as a library for the functions called in `index.html`, and is written in javascript. These files are served from the IxE when node.js is running `chatServer.js`. Both index.html and `index.js` run on the web browser.

#### Annotated code tours

* [chatServer.js](chatServer.js,-annotated)
* [index.js](index.js,-annotated)

## Make the ChatBot your own

Now, please modify the `chatServer.js` file to make your own chatbot. It might, for example, act like [WoeBot](https://woebot.io) and find out what is bringing a person down. Or! Maybe it helps people fall asleep like [Insomnobot](http://insomnobot3000.com). You have a finite amount of time, so narrow the purpose of the chatbot so that it does not have to have [Turing-complete](https://en.wikipedia.org/wiki/Turing_completeness) conversational ability.

### Editing the Code ###
To change how your chatbot behaves, you will need to edit the code. To edit the code files, you can use `nano` a command line text editor.

To edit your `chatServer.js` code, make sure you are in the `simple-Chatbot/` directory and then open the code file using the command:

```shell
nano chatServer.js
```

The files should then open up on your screen. You can move around the file using your arrow keys. Note: `nano` is a very simple editor. There is no mouse-click support. You will need to move around the file using just up, down, left, and right.

Let's edit the name of your chatbot first.

Move to the line of code that says:

```shell
socket.emit('answer',"Hey, Hello I am \"___*-\" a simple chat bot example."); //We start with the introduction;
```

Then move your cursor to the `\"___*-\"`, delete it using backspace, and type in the name you would like to call your chatbot.

Once you change the name, you will want to save your file then exit.

Notice on the bottom of the terminal window that there is some text showing things like `^G Get Help` and `^O Write Out`. These are the commands that you can use in `nano`. The `^` character stands for `Ctrl`. So to `Write Out` (which means to save the file), you would type `Ctrl` and `O`. When you click this, you will see that a bar comes up and says `File Name to Write: chatServer.js`. This is the file name you are saving to. In this case, we want the same name, so we can just hit the `Enter` key. You will then see a message on the bottom that tells you how many lines were written, something like `[ Wrote 116 lines ]`.

To exit the `nano` editor, type `^X` or `Ctrl` + `X`. This will then return you to the terminal console. You should then be able to re-run your chatbot using `node chatServer.js` and you should see that your chatbot now has the name you gave it.

*Pro-tip:* In `nano` if you just hit `^X` without saving, it should ask you if you want to `Save modified buffer?  (Answering "No" will DISCARD changes.)`. You can then type `y` `Y` or `Yes` then hit `Enter` and it will save and exit.

`nano` is a general purpose text editor, so you can use it for any type of text file like the `.js`, `.html`, and `.css` files in this project.

## Record someone trying out your ChatBot

Using a phone or other video device, record someone trying out your ChatBot. (This does not need to be an advertisement for your ChatBot; it is okay if the person is confused or asks questions or doesn't like it. We like the drama.) Post the video to your assignment on Slack!

## Submitting the Code
Please submit your code by submitting a link to your forked GitHub project on your personal homework slack channel.

Instructions on how to fork then clone a project **OR** rebase a cloned project can be found [here](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Forking-a-GitHub-project).