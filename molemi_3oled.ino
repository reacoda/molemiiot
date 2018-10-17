#include <Arduino_SW01.h>

#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <SSD1306init.h>

#include <xCore.h>
#include <xVersion.h>

#include <Arduino_OD01.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <SSD1306init.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>





/*****************************************************************************
    This Sketch is an example for the XinaBox CW01 ESP8266 Board
    It demonstrates how to connect to a WiFi access point
    You can buy these devices on our store!
     -----> https://xinabox.cc/CW01/
    Currently Supported on the following ☒CHIPs:
    - CW01
*****************************************************************************/

/************************** Library Includes ********************************/

/************************* WiFi Access Point *********************************/
// Replace the contents between inverted commas with your WiFi details.
// YOUR_SSID is the name of your WiFi access point.
// YOUR_SECRET_PASSWORD is your WiFi access point password.
const char* WIFI_SSID = "Tshimologong-General";
const char* WIFI_PASS = "letsinnovate";

const int DELAY_TIME = 6000;
xSW01 SW01;
xOD01 OD01;
/**************************** SYSTEM DEFINES *********************************/
#define RED 12
#define GREEN 13
#define BLUE 5

/***************************** Sketch Code ***********************************/
void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  // Set the I2C Pins for CW01
  #ifdef ESP8266
    Wire.pins(2, 14);
    Wire.setClockStretchLimit(15000);
  #endif

// Start the I2C Comunication
  Wire.begin();

   // Start the OLED Display OD01
  OD01.begin();

   // Display Example Name on OD01
  OD01.println("SW01 Temperature");

  // send command to clear the display
  OD01.clear();

  
  // Start the  SW01 Sensor
  SW01.begin();
  
  Serial.println("================================");
  Serial.println("    XINABOX SW01 Temperature    ");
  Serial.println("================================");
  
  //Delay for sensor to normalise
  delay(5000);

  // Create a variable to store the data read from SW01  
  float tempC;
  float tempF;
  tempC = tempF = 0;
  
  // Read and calculate data from SW01 sensor
  SW01.poll();
  
  // Request SW01 to get the temperature measurement and store in
  // the temperature variable   
  tempC = SW01.getTempC(); // Temperature in Celcuis
  tempF = SW01.getTempF(); // Temperature in Farenheit
  
  // Display the recoreded data over the Serial Monitor   
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println(" F"); 

    // Small delay between sensor reads
  delay(DELAY_TIME);
  
  // set ports as digital (on/off) OUTPUTs, the digitalWrite(...) statement is used to set digital ports on or off
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Connect to WIFI
  WIFI_connect();  
}

void loop() {

// Create a variable to store the data read from SW01 
  float temperature, pressure;
  temperature = pressure = 0;

  // request the sensor to read data
  SW01.poll();

   OD01.print("Molemi-SmartFarm ");
   OD01.println("");
  // Request SW01 to get the temperature measurement 
  // Temperature  request is degrees celcuis  
  temperature = SW01.getTempC();
  
  // Display the temperature on the OLED display OD01   
  OD01.print("Temperature: ");
  OD01.print(temperature);
  OD01.println(" C");

  // Request SW01 to get the temperature measurement 
  // Temperature  request is farenheit  
  temperature = SW01.getTempF();
  
  // Display the temperature on the OLED display OD01   
  OD01.print("Temperature: ");
  OD01.print(temperature);
  OD01.println(" F");

  // Request SW01 to get the pressure measurement 
  // Pressure request is in pascals 
  // This is the converter to kilo pascals
  pressure = SW01.getPressure();

  // Display the pressure on the OLED display OD01   
  OD01.print("Pressure: ");
  // Display a convertered kPa value
  OD01.print(pressure/1000);
  OD01.println(" kPa");  
  
  // delay between sensor reads
  delay(DELAY_TIME);  
  
  // send command to clear the display
  OD01.clear();
  
  // turn the RED LED on by writing a logic HIGH to the port
  digitalWrite(RED, HIGH);
  delay(50);
  // turn the RED LED off by writing a logic LOW to the port
  digitalWrite(RED, LOW);
  delay(950);  
}


// connect to WiFi network
void WIFI_connect() {
  
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(GREEN, LOW);
    
    // Connect to WiFi access point.
    Serial.println(); Serial.println();
    Serial.print("Connecting to : ");
    Serial.print(WIFI_SSID);
    Serial.println(" ...");

    // Start ESP8266 STA mode
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // check connection status
    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(RED, HIGH);
      delay(250);
      digitalWrite(RED, LOW);
      delay(250);
      Serial.print(".");
    }

    // if connected, show the IP address of the ESP8266
    if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(GREEN, HIGH);
      Serial.println();
      Serial.println("Connection established!");
      Serial.print("IP address:\t");
      Serial.println(WiFi.localIP());
    }
    
  }
}
