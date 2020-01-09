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

  
  


