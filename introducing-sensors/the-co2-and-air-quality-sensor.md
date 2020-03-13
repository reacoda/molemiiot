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

![](../.gitbook/assets/image%20%285%29.png)

### What do you need ?

* Arduino Uno Board. 
* male-to-male jumper cables. 
* USB power cable for the Uno.
* keyestudio CCS811 Carbon Dioxide Temperature Air Quality Sensor

### Setup the Circuit

![The circuit for the CO2 and air quality sensor](../.gitbook/assets/image%20%2816%29.png)

![Pin description of the CCS811 sensor](../.gitbook/assets/image%20%2820%29.png)

1. Insert the CO2 sensor of the breadboard.
2. Connect the GND pin of the sensor to one of the GND pins of the Arduino Uno.
3. Connect the VCC pin of the sensor to the 5V pin of the Uno.
4. Connect the SDA pin of the sensor to the Analog pin 4 \(A4\) of the Uno.
5. Connect the SCL pin of the sensor to the analog pin 5 \(A5\) of the Uno.
6. Connect the WAKE pin of the sensor to the other GND pin of the Uno.

### The Code 

* Open your Arduino IDE software and configure the board and the port accordingly. 
* Download the [Adafruit CCS811 library](https://drive.google.com/drive/folders/1T175_657leBks22ww0Fwo_Txzmk026TR) and include it in your Arduino IDE.
* Add the following code to your IDE:

```text
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;

void setup() {
  Serial.begin(9600);
  Serial.println("CCS811 test");
  
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
  //calibrate temperature sensor
  while(!ccs.available());
  float temp = ccs.calculateTemperature();
  ccs.setTempOffset(temp - 25.0);
}

void loop() {
  if(ccs.available()){
    float temp = ccs.calculateTemperature();
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.print(ccs.getTVOC());
      Serial.print("ppb   Temp:");
      Serial.println(temp);
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}
```

Open the serial port. Blow on the sensor and see how the sensor values changes.





