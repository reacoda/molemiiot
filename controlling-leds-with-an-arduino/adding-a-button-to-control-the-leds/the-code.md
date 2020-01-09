# The Code

Start by adding a new variable to the start of the program:

```text
int button = 12; // switch is on pin 12

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Now, in the setup function, add a new line to declare the switch as an input. I’ve also added a single line to start the traffic lights in the green stage. Without this initial setting, they would be turned off.

```text
int button = 12; // switch is on pin 12

void setup() {
  // put your setup code here, to run once:
  
  pinMode(button, INPUT);
  digitalWrite(green, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

In the loop function add the following:  


```text
int button = 12; // switch is on pin 12

void setup() {
  // put your setup code here, to run once:
  
  pinMode(button, INPUT);
  digitalWrite(green, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(button) == HIGH){
        delay(15); // software debounce
        if (digitalRead(button) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            changeLights();
            delay(15000); // wait for 15 seconds
        }
    }
}
```



