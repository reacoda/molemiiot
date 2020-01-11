---
description: >-
  In this activity we will be writing the code to display the sensor reading
  from DS18B20 and displaying them on the serial port via the Arduino IDE
---

# Displaying the sensor readings on the serial port

#### The Code 

Upload the following code on the Arduino IDE 

```text
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 4;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(5000);
}
```

**Explaining the Code:**

The first you need to is to include the two libraries: OneWire and DallasTemperature:

```text
#include <OneWire.h>
#include <DallasTemperature.h>
```

Next you need to declare the GPIO pin that the DS18B20 is connected to:

```text
// GPIO where the DS18B20 is connected to
const int oneWireBus = 4;
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
```

Then in the setup section you initialise the serial monitor at a baud rate of 115200 

```text
Serial.begin(115200);
```

Initialise the DS18B20 sensor:

```text
sensors.begin();
```

To receive the temperature readings you need to call the **requestTemperatures\(\)** method as follows:

```text
sensors.requestTemperatures(); 
```

To get the temperature in the metric unit Celsius add the following method:

```text
float temperatureC = sensors.getTempCByIndex(0);
```

If you prefer to get it in Fahrenheit, use the following method:

```text
float temperatureF = sensors.getTempFByIndex(0);
```

The final step is to print the temperature readings in the serial monitor. The readings will be requested every 5 seconds:

```text
Serial.print(temperatureC);
Serial.println("ºC");
Serial.print(temperatureF);
Serial.println("ºF");

delay(5000);
```

Upload the code and open the serial monitor to see the temperature readings.

