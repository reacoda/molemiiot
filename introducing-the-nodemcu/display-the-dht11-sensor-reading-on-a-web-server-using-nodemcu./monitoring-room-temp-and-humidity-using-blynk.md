---
description: >-
  This activity will take you through the steps and procedure you need to follow
  to display the temperature and humidity of the room using the DHT11 sensor,
  NodeMCU and the Blynk app.
---

# Monitoring Room Temp & Humidity using Blynk

### Objectives:

* Setup the circuit with the NodeMCU and the DHT11 sensor.
* Configure/setup the Arduino IDE by installing the DHT11 library.
* Setup the Blynk App on your smartphone to include the display widget for both temperature and humidity.
* Write the code that will read the temperature and humidity values from the DHT11 sensor.

#### Explaining the components

* The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin \(no analog input pins needed\).



### Setting up the circuit:

![Circuit setup for DHT11 temperature and humidity sensor](../../.gitbook/assets/dht11.PNG)

1. Inset the DHT11 sensor on the breadboard as shown above.
2. Connect the Vcc pin on the sensor to the 3v pinon the NodeMCU.
3. Connect the GND pin of the sensor to the GND pin of the NodeMCU.
4. Connect the data/signal pin of the sensor to the digital pin D2 on the NodeMCU.

#### Configuring the Blynk app.

1. On the Blynk app create a new project and name it "Monitor Room". You will receive the authentication key via e-mail.
2. On the "+" icon add the Gauge widget and call name it "Temp". Assign it a virtual pin V5 and setup the value from 0 to 100.
3. Add another Gauge widget and call it "Humidity". Assign it a virtual pin V6 and setup the value from 0 to 100.
4. 
 To read from the DHT sensor, we’ll use the [DHT library from Adafruit](https://github.com/adafruit/DHT-sensor-library). To use this library you also need to install the [Adafruit Unified Sensor library](https://github.com/adafruit/Adafruit_Sensor). Follow the next steps to install those libraries.

1.  Open your Arduino IDE and go to **Sketch** &gt; **Include Library** &gt; **Manage Libraries**. The Library Manager should open.
2.  Search for “**DHT**” on the Search box and install the DHT library from Adafruit.





