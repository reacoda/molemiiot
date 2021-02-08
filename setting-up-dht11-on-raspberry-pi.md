---
description: >-
  The following tutorial is meant to setup the DHT11 humidity and temperature
  sensor to work on the Raspberry Pi 3
---

# Setting up DHT11 on Raspberry Pi

![](.gitbook/assets/dht11sensor.jpg)

**Step 1**: The first thing that you will need to do is to wire the circuit for the DHT11 sensor with the Raspberry Pi. The VCC pin of the sensor will be connected to the 5V pin on the Raspberry Pi, GND will be connected to the GND of the Pi, lastly the DATA pin will be connected to GPIO 4 on the Raspberry Pi.

Step 2: The next following task is to install the dependencies. First you will need to install updates and upgrade as follows:

```text
sudo apt-get update && upgrade -y 
```

You need to install PIP before you can install the Adafruit\_DHT module:

```text
sudo apt-get install python3-dev python3-pip
sudo python3 -m pip install --upgrade pip setuptools wheel

sudo pip3 install Adafruit_DHT
```

**The python code will be as follows:**

```text
import Adafruit_DHT
import time
 
DHT_SENSOR = Adafruit_DHT.DHT11
DHT_PIN = 4
 
while True:
    humidity, temperature = Adafruit_DHT.read(DHT_SENSOR, DHT_PIN)
    if humidity is not None and temperature is not None:
        print("Temp={0:0.1f}C Humidity={1:0.1f}%".format(temperature, humidity))
    else:
        print("Sensor failure. Check wiring.");
    time.sleep(3);
```

  
  
****

