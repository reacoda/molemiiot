# The Code

For us to be able to work with the NodeMCU, we need to be able to upload the code without using the serial port. This is called Over The Air.

OTA \(Over The Air\) update is the process of uploading a new code to the ESP8266 module using WiFi connection instead of serial communication.

This is done by following the instructions below:

1. Connect your NodeMCU dev board to the computer using a USB cable.
2. Select the board and the port number as follows: 

![Choosing the port \(randomnerdtutorial.com\)](../../.gitbook/assets/image%20%281%29.png)

 3\) Open the BasicOTA.ino example: **File** &gt; **Examples** &gt; **Arduino OTA** &gt; **BasicOTA.ino** or copy the following sketch to your Arduino IDE.

The code will be as follows:  


```text
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
}
```

4\) Click the "Upload" button 

The full code is as follows:

```text
/*

  Blynk Flow Sensor Water Meter- Calculates Total Water Consumption.

*/


#define BLYNK_PRINT Serial           // Uncomment for debugging 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <ESP8266mDNS.h>  // For OTA with ESP8266
#include <WiFiUdp.h>  // For OTA
#include <ArduinoOTA.h>  // For OTA

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "07DQbnsxODMhV3t0HC4QFZ5ZeHKIoFF6";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tshimologong-General";
char pass[] = "letsinnovate";

#define PULSE_PIN D2  //gpio4
#define FLOW_CALIBRATION 8.2 
#define VPIN_TOTAL_LITERS       V1
#define VPIN_FLOW_RATE          V2
#define VPIN_FLOW_MILLI_LITERS  V3
#define VPIN_RESET              V4

      
#define OTA_HOSTNAME "Test Flow Sensor Water Meter"


BlynkTimer timer;

volatile long pulseCount = 0;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
float totalLitres;
float totalLitresold;
unsigned long oldTime;


BLYNK_CONNECTED() { // runs once at device startup, once connected to server.

  Blynk.syncVirtual(VPIN_TOTAL_LITERS); //gets last know value of V1 virtual pin

}


// Restores last know value of V1 virtual pin which we got it from blynk server
BLYNK_WRITE(VPIN_TOTAL_LITERS)
{
  totalLitresold = param.asFloat();

}


BLYNK_WRITE(VPIN_RESET) {  // reset all data with button in PUSH mode on virtual pin V4
  int resetdata = param.asInt();
  if (resetdata == 0) {
    Serial.println("Clearing Data");
    Blynk.virtualWrite(VPIN_TOTAL_LITERS, 0);
    Blynk.virtualWrite(VPIN_FLOW_RATE, 0);
    flowRate = 0;
    flowMilliLitres = 0;
    totalMilliLitres = 0;
    totalLitres = 0;
    totalLitresold = 0;
  }
}



void pulseCounter()
{
  pulseCount++;
}

void flow()
{

  if ((millis() - oldTime) > 1000)   // Only process counters once per second
  {
    detachInterrupt(PULSE_PIN);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / FLOW_CALIBRATION;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    totalLitres = totalLitresold + totalMilliLitres * 0.001;
    unsigned int frac;

    // Print the flow rate for this second in liters / minute
    Serial.print("flowrate: ");
    Serial.print(int(flowRate));  // Print the integer part of the variable

    Serial.print(".");             // Print the decimal point
    frac = (flowRate - int(flowRate)) * 10; // Determine the fractional part. The 10 multiplier gives us 1 decimal place.
    Serial.print(frac, DEC) ;      // Print the fractional part of the variable
    Serial.print("L/min");

    Serial.print("  Current Liquid Flowing: ");  // Print the number of liters flowed in this second
    Serial.print(flowMilliLitres);
    Serial.print("mL/Sec");

    Serial.print("  Output Liquid Quantity: ");  // Print the cumulative total of liters flowed since starting
    Serial.print(totalLitres);
    Serial.println("L");

    pulseCount = 0;  // Reset the pulse counter so we can start incrementing again

    attachInterrupt(PULSE_PIN, pulseCounter, FALLING);    // Enable the interrupt again now that we've finished sending output
  }

}


void sendtoBlynk()  // In this function we are sending values to blynk server
{
  Blynk.virtualWrite(VPIN_TOTAL_LITERS, totalLitres);          // Total water consumption in liters (L)
  Blynk.virtualWrite(VPIN_FLOW_RATE, flowRate);            // Displays the flow rate for this second in liters / minute (L/min)
  //  Blynk.virtualWrite(VPIN_FLOW_RATE, flowMilliLitres);  // Displays the number of liters flowed in second (mL/Sec)

}

void setup()
{
  Serial.begin(57600);
  Blynk.begin(auth, ssid, pass);
  ArduinoOTA.setHostname(OTA_HOSTNAME);  // For OTA - Use your own device identifying name
  ArduinoOTA.begin();  // For OTA

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  totalLitresold = 0;

  pinMode(PULSE_PIN, INPUT);  // Initialization of the variable "PULSE_PIN" as INPUT (D2 pin)

  attachInterrupt(PULSE_PIN, pulseCounter, FALLING);

  timer.setInterval(10000L, sendtoBlynk); // send values blynk server every 10 sec

}


void loop()
{

  Blynk.run();
  ArduinoOTA.handle();  // For OTA
  timer.run();
  flow();

}

```

