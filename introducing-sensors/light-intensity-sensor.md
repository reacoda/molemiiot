---
description: >-
  in this activity we will be working with the BH1750FVI sensor module to
  measure the light intensity.
---

# Light Intensity Sensor

BH1750FVI digital light intensity module is a digital light intensity sensor integrated circuit used for two-wire serial bus interface. It uses the light intensity data collected by module to adjust the brightness of LCD and keyboard backlight. The module resolution can detect a wide range of light intensity changes.

![](../.gitbook/assets/image%20%289%29.png)

### Objectives:

* Setup the circuit to allow the Arduino Uno to communicate with the BH1750FVI sensor.
* Setup the Arduino IDE to be able to upload the code to the Arduino IDE.
* Write the code to be able to serial print the light intensity readings.

#### Setup the Circuit:

![](../.gitbook/assets/image%20%288%29.png)

1. Connect the GND pin of the sensor to the GND pin of the Arduino Uno.
2. Connect the V pin of the sensor to the 5v PIN of the Uno.
3. Connect the SDA pin of the sensor to the analog pin \(A4\) of the Uno.
4. Connect the SCL pin of the sensor to the analog pin \(A5\) of the Uno.



