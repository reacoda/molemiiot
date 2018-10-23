/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Arduino_SW01.h>
#include <xCore.h>
#include <Arduino_OD01.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "088b73ec8c284de1913be1e16792babc";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tshimologong-General";
char pass[] = "letsinnovate";

const int DELAY_TIME = 20000;
xSW01 SW01;
xOD01 OD01;
/**************************** SYSTEM DEFINES *********************************/
#define RED 12
#define GREEN 13
#define BLUE 5
int t1;

BlynkTimer timer;
void requestTime() {
  Blynk.sendInternal("rtc", "sync");
}
/***************************** Sketch Code ***********************************/

BLYNK_WRITE(InternalPinRTC) {
  long t = param.asLong();
  Serial.print("Unix time: ");
  Serial.print(t);
  Serial.println();
}

// Toggle LED
void ledBlynk()
{
  digitalWrite(RED, !digitalRead(RED));
}


// Enable/disable blinking using virtual pin 1
BLYNK_WRITE(V2)
{
  if (param.asInt()) {
    timer.enable(t1);
  } else {
    timer.disable(t1);
    digitalWrite(RED, LOW);
  }
}

// Change blink interval using virtual pin 8
BLYNK_WRITE(V8)
{
  long interval = param.asLong();
  boolean wasEnabled = timer.isEnabled(t1);
  timer.deleteTimer(t1);
  t1 = timer.setInterval(interval, ledBlynk);
  if (!wasEnabled) {
    timer.disable(t1);
  }
}



void sendSensor()
{
  float temperature = SW01.getTempC();
  float humidity = SW01.getHumidity();
  float altitude = SW01.getAltitude(101325);
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from Xinabox SW01 sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, temperature);
  Blynk.virtualWrite(V6, humidity);
  Blynk.virtualWrite(V4, altitude);
}


void setup()
{
  // Debug console
  Serial.begin(9600);
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
  tempC = 0;

   // Read and calculate data from SW01 sensor
  SW01.poll();

  // Display the recoreded data over the Serial Monitor   
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  Blynk.begin(auth, ssid, pass);

  // Small delay between sensor reads
  delay(DELAY_TIME);

    // set ports as digital (on/off) OUTPUTs, the digitalWrite(...) statement is used to set digital ports on or off
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

   // Configure LED and timer
  pinMode(RED, OUTPUT);
  t1 = timer.setInterval(500L, ledBlynk);
  timer.disable(t1);

  // Connect to WIFI
   // Setup a function to be called every second
  timer.setInterval(2000L, sendSensor);
  timer.setInterval(10000L, requestTime);
}

void loop()
{
  // Create a variable to store the data read from SW01 
  float temperature, pressure, altitude, humidity;
  temperature = pressure = altitude = humidity = 0;

  // request the sensor to read data
  SW01.poll();

   OD01.print("Molemi-SmartFarm ");
   OD01.println("");
  // Request SW01 to get the temperature measurement 
  // Temperature  request is degrees celcuis  
  temperature = SW01.getTempC();
  humidity = SW01.getHumidity();
  altitude = SW01.getAltitude(101325);
  
  // Display the temperature on the OLED display OD01   
  OD01.print("Temperature: ");
  OD01.print(temperature);
  OD01.println(" C");

 // Display the Humidity on the OLED OD01   
  OD01.print("Humidity: ");
  OD01.print(humidity);
  OD01.println(" %");

   // Display the Altitude on OLED OD01   
  OD01.print("Altitude: ");
  OD01.print(altitude);
  OD01.println(" m");
  
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
  Blynk.run();
  timer.run();
}

