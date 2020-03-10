---
description: >-
  This page will demonstrate how to setup the circuit for the Keyes CO2 and air
  quality sensor and serial print the sensor values.
---

# The CO2 and air quality sensor

### Objectives:

* The aim of this activity is to measure the amount of CO2 in the environment and measure the air quality based on the ambient temperature.
* Connect the circuit for the CCS811 sensor.
* Write the code \(and upload on the Arduino Uno board\) to serial print the CO2, ambient temperature and volatile organic compounds. 

![](../.gitbook/assets/image%20%284%29.png)

### What do you need ?

* Arduino Uno Board. 
* male-to-male jumper cables. 
* USB power cable for the Uno.
* keyestudio CCS811 Carbon Dioxide Temperature Air Quality Sensor

### Setup the Circuit

![The circuit for the CO2 and air quality sensor](../.gitbook/assets/image%20%2814%29.png)

![Pin description of the CCS811 sensor](../.gitbook/assets/image%20%2817%29.png)

1. Insert the CO2 sensor of the breadboard.
2. Connect the GND pin of the sensor to one of the GND pins of the Arduino Uno.
3. Connect the VCC pin of the sensor to the 5V pin of the Uno.
4. Connect the SDA pin of the sensor to the Analog pin 4 \(A4\) of the Uno.
5. Connect the SCL pin of the sensor to the analog pin 5 \(A5\) of the Uno.
6. Connect the WAKE pin of the sensor to the other GND pin of the Uno.





