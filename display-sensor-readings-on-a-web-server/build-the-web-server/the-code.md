# The Code

The first thing you will need to do is to include all the necessary libraries as follows:

```text
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
```

Declare the GPIO pin that is connected to the DS18B20 sensor. In our case we are connecting to GPIO 4 \(D1\):

```text
#define ONE_WIRE_BUS 4
```

Instantiate the instances needed to initialize the sensor:

```text
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
```

Setup your network credentials:

```text
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
```

Create an AsyncWebServer object on port 80:

```text
AsyncWebServer server(80);
```



