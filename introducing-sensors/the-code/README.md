# The Code

Constants are similar to variables in that they allow you to uniquely name things in the program, but unlike variables they cannot change. Name the analog input for easy reference, and create another named constant to hold the baseline temperature.

```text
const int sensorPin = A0; 
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

For every 2 degrees above this baseline, the LED will turn on. The temperature is being stored as a float, or floating-point number. This type of number has a decimal point, and is used for numbers that can be expressed as fractions.

In the setup you’re going to use a new command, Serial. begin\(\). This opens up a connection between the Arduino and the computer, so you can see the values from the analog input on your computer screen.

The argument 9600 is the speed at which the Arduino will communicate, 9600 bits per second. You will use the Arduino IDE’s serial monitor to view the information you choose to send from your microcontroller. When you open the IDE’s serial monitor verify that the baud rate is 9600.

```text
const int sensorPin = A0; 
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Next up is a for\(\) loop to set some pins as outputs. These are the pins that you attached LEDs to earlier. Instead of giving them unique names and typing out the pinMode\(\) function for each one, you can use a for\(\) loop to go through them all quickly. This is a handy trick if you have a large number of similar things you wish to iterate through in a program. Tell the for\(\) loop to run through pins 2 to 4 sequentially.

The function Serial.print\(\) sends information from the Arduino to a connected computer. You can see this information in your serial monitor. If you give Serial.print\(\) an argument in quotation marks, it will print out the text you typed. If you give it a variable as an argument, it will print out the value of that variable.

```text
const int sensorPin = A0; 
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); // open a serial port 
  for(int pinNumber = 2; pinNumber<5; pinNumber++){ 
  pinMode(pinNumber,OUTPUT);
  digitalWrite(pinNumber, LOW); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorVal = analogRead(sensorPin);
  Serial.print(“Sensor Value: “); 
  Serial.print(sensorVal);
   // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(“, Volts: “); 
  Serial.print(voltage);
  Serial.print(“, degrees C: “); 
  // convert the voltage to temperature in degrees 
  float temperature = (voltage - .5) * 100; 
  Serial.println(temperature);
  if(temperature < baselineTemp){ 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){ digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+6){ 
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH);
} 
delay(1); 

}
```

  
  
  
  


