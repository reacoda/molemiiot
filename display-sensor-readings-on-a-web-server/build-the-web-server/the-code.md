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

Using the following, read the temperature:

```text
String readDSTemperatureC() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);

  if(tempC == -127.00){
    Serial.println("Failed to read from DS18B20 sensor");
    return "--";
  } else {
    Serial.print("Temperature Celsius: ");
    Serial.println(tempC); 
  }
  return String(tempC);
}
```

In case the sensor is not able to get a valid reading, it returns -127. So, we have an if statement that returns two dashes \(–-\) in case the sensor fails to get the readings.

```text
if(tempC == -127.00){
  Serial.println("Failed to read from DS18B20 sensor");
  return "--";
```

The reaDSTemperatureF\(\) function works in a similar way but returns the readings in Fahrenheit degrees.

The readings are returned as string type. To convert a float to a string, use the String\(\) function.

```text
return String(tempC);
```

The next step is building the web page. The HTML and CSS needed to build the web page are saved on the index\_html variable.

In the HTML text we have TEMPERATUREC and TEMPERATUREF between **%** signs. This is a placeholder for the temperature values.

This means that this **%TEMPERATUREC%** text is like a variable that will be replaced by the actual temperature value from the sensor. The placeholders on the HTML text should go between **%** signs.

#### Processor 

The next will be to create a processor function that will replace the placeholders in our HTML text with the actual temperature values.

```text
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATUREC"){
    return readDSTemperatureC();
  }
  else if(var == "TEMPERATUREF"){
    return readDSTemperatureF();
  }
  return String();
}
```

When the web page is requested, we check if the HTML has any placeholders. If it finds the %TEMPERATUREC% placeholder, we return the temperature in Celsius by calling the readDSTemperatureC\(\) function created previously.

```text
if(var == "TEMPERATUREC"){
  return readDSTemperatureC();
}
```

If the placeholder is %TEMPERATUREF%, we return the temperature in Fahrenheit.

```text
else if(var == "TEMPERATUREF"){
  return readDSTemperatureF();
}
```

In the setup function, initialise the serial monitor for debugging:

```text
Serial.begin(115200);
```

Initialise the DS18B20 temperature sensor:

```text
sensors.begin();
```

Write the code to connect to the Network and print the IP address:

```text
WiFi.begin(ssid, password);
Serial.println("Connecting to WiFi");
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println();
  
// Print ESP8266 Local IP Address
Serial.println(WiFi.localIP());
```

Lastly, you need to copy the code below. It serves the purpose of handling the web:

```text
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html, processor);
});
server.on("/temperaturec", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDSTemperatureC().c_str());
});
server.on("/temperaturef", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDSTemperatureF().c_str());
});
```

When we make a request on the root URL, we send the HTML text that is stored in the index\_html variable. We also need to pass the processor function, that will replace all the placeholders with the right values.



