# The Code

The default code when you startup the Arduino IDE looks like this:   


```text
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Include the code to control the LEDs. Start by defining variables so that we can address the lights by name rather than a number. 

```text
int redLED = 10;
int yellowLED = 9;
int greenLED = 8;

void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Next, let’s add the setup function, where’ll we configure the red, yellow and green LEDs to be outputs. Since you have created variables to represent the pin numbers, you can now refer to the pins by name instead.

```text
int redLED = 10;
int yellowLED = 9;
int greenLED = 8;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Finally, write the code that will turn the LEDs on for a certain period of time and then switch them off for another certain period of time:

```text
int redLED = 10;
int yellowLED = 9;
int greenLED = 8;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // green off, yellow on for 3 seconds
  
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(3000);
  
  // turn off yellow, then turn red on for 5 seconds
  
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(5000);

  // red and yellow on for 2 seconds (red is already on though)
  
  digitalWrite(yellow, HIGH);
  delay(2000);
  
  // turn off red and yellow, then turn on green
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(3000);    

}
```

Verify and upload the code to your Arduino board using the icons shown below:

![Verify/Upload code \(Core Electronics, Australia\)](../.gitbook/assets/verifyuploadcode%20%281%29.png)



