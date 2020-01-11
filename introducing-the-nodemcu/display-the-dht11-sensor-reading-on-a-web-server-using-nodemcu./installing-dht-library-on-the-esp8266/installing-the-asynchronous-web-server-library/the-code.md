# The Code

We’ll program the ESP8266 using Arduino IDE, so you must have the ESP8266 add-on installed in your Arduino IDE.

Open your Arduino IDE and follow the step-by-step explanation of the code:

1. The first thing that you need to is to include all the libraries at the beginning: 

```text
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
```

2. Setup your network credentials:

```text
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
```

3. Declare the GPIO pin that the DHT11 sensor is connected to. In our case we connected it to the GPIO 5 \(D1\).

```text
#define DHTPIN 5     // Digital pin connected to the DHT sensor
```

Now you have to select the DHT type that you will be using. In our case we are using the DHT11.

```text
#define DHTTYPE DHT1   // DHT 11 (AM2302)
```

Instantiate a DHTobject with the type and pin defined earlier.

```text
DHT dht(DHTPIN, DHTTYPE);
```



