---
description: >-
  These are the classes/lessons for the "Made in Workshop" training workshops.
  We will be controlling the Centurion gate motors with a 2-channel relay. This
  will close or open the gate.
---

# Controlling a Centurion gate Motor with NodeMCU a 2-channel relay

For this activity we will be controlling the Centurion gate motor with a 2-channel relay. We will be using the Arduino-based nodeMCU and the Blynk mobile app to control the relay. The Blynk app will have two buttons. One will be to open and the other will be to close the gate. 

**The Outcomes of this workshop/Tutorial**

* 
#### What will you need ?

* NodeMCU dev kit 
* 2-channel relay 
* An android smartphone with the Blynk app installed.
* male-to-female jumper cables
* a desktop computer/laptop with the Arduino IDE installed 
* A 12V DC motor 
* 
Circuit setup is as follows:  
  

![](../../.gitbook/assets/image.png)



![](../../.gitbook/assets/centuriongatemotor.PNG)

1. Connect one male-to-female jumper cable from the D0 pin on the NodeMCU to the "IN1" PIN on the relay board.  Also connect the D1 PIN to the "IN2" PIN.
2. Connect the GND pin of the relay module to the GND pin of the NodeMCU. Then connect the VCC pin of the of the relay module to the 5V pin \(the relay needs a power supply of 5V. A nodeMCU only gives an output voltage of 3 - 3.3V so you will need to use an Arduino Uno or a 5V power supply.
3. Connect the both of the wires of the motor into the COM of each of the relay modules. 
4. For the DC motor, connect the positive terminal of the power supply to both the Normally Open \(NO\) pin of the two relay modules. Then connect the negative terminal of the power supply to the two Normally Closed \(NC\) pins of both the relays.

Credit: [https://www.youtube.com/watch?v=BQOji4i4PEc](https://www.youtube.com/watch?v=BQOji4i4PEc)



If this is the first time working with the NodeMCU, you will need to install the ESP8266 board on the Arduino IDE as demonstrated here: 

1.  The first thing you will need to do is install the Blynk app on your smartphone and create a New Project. Once you have created it, you will receive the authentication code via the e-mail address that you you signed up with.  

![Create a New Project](../../.gitbook/assets/createblynkappname.png)

![Authentication key generated](../../.gitbook/assets/createblynkapp.png)

Add two buttons for the two relays one labelled "Open Gate" the other "Close Gate":

![](../../.gitbook/assets/screenshot_20200214-184846.png)

After adding the buttons, click on the "OPEN GATE" one and then change the logic from 0-1 to 1-0 because the output of the NodeMCU is active LOW. Under the PIN tab, assign it the digital pin D0.

Do the same with the "CLOSE GATE" button and assign the digital pin D1 to it.

 

![Configuring the OPEN GATE button](../../.gitbook/assets/screenshot_20200215-103136.png)



![Configuring the &quot;CLOSE GATE&quot; button ](../../.gitbook/assets/screenshot_20200215-103136%20%281%29.png)





2. The second thing you will need to do is to add the is include the example code for blynk using the nodeMCU board. 

click on **File &gt; Examples &gt; Blynk &gt; Boards\_WiFi &gt; NodeMCU** 

This will be the code that you get:

![The example code for Blynk NodeMCU](../../.gitbook/assets/blynk_nodemcu.PNG)

```text
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

```



