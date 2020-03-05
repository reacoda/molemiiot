# Introduction to Arduino

One of the micro-controllers that will be used for the the Sustainable Farming Methods workshop will be the Arduino board. We will be using two variations namely the Arduino Uno and the NodeMCU.  
  
The Uno will be used for introducing the basic concepts and programming methods while the NodeMCU will be used to connect the sensors for the IoT section of the workshop.  
  
We will be using the Arduino board as it is open-source and affordable.

#### What is an Arduino ?

![Arduino Uno \(arduino.cc\)](../.gitbook/assets/arduino-uno.png)

An Arduino board is an open-source micro-controller that is used to read inputs - temperature and humidity on a sensor, pressing/toggling a button and it is able to give out outputs - turning a motor and switching on an LED \(read [full introduction here](https://www.arduino.cc/en/Guide/Introduction)\).

### Getting Started

In order to start using the board, one needs to setup the Arduino IDE on their desktop by using the [getting started user guide](https://www.arduino.cc/en/Guide/HomePage).

#### The Arduino Anatomy

![The anatomy of the Arduino board \(arduino.cc\)](../.gitbook/assets/boardanatomy.svg)

1. **Digital pins** Use these pins with digitalRead\(\), digitalWrite\(\), and analogWrite\(\). analogWrite\(\) works only on the pins with the PWM symbol.
2. **Pin 13 LED** The only actuator built-in to your board. Besides being a handy target for your first blink sketch, this LED is very useful for debugging.
3.  **Power LED** Indicates that your Uno is receiving power. Useful for debugging.
4. **ATmega microcontroller** The heart of your board.
5.  **Analog in** Use these pins with analogRead\(\).
6.  **GND and 5V pins** Use these pins to provide +5V power and ground to your circuits.
7.  **Power connector** This is how you power your Genuino when it’s not plugged into a USB port for power. Can accept voltages between 7-12V.
8.  **TX and RX LEDs** These LEDs indicate communication between your Genuino and your computer. Expect them to flicker rapidly during sketch upload as well as during serial communication. Useful for debugging.
9.  **USB port** Used for powering your Uno, uploading your sketches, and for communicating with your sketch \(via Serial. println\(\) etc.\).
10.  **Reset button** Resets the ATmega microcontroller. 

For more details on the different parts of the Arduino please visit the [Arduino foundations page](https://www.arduino.cc/en/Tutorial/Foundations).

### Reference:

1. Arduino get started page \([https://www.arduino.cc/en/Guide/HomePage](https://www.arduino.cc/en/Guide/HomePage)\).
2. Arduino Board Anatomy page \( [https://www.arduino.cc/en/Guide/BoardAnatomy](https://www.arduino.cc/en/Guide/BoardAnatomy) \)
3. Arduino Foundations Page \( [https://www.arduino.cc/en/Tutorial/Foundations](https://www.arduino.cc/en/Tutorial/Foundations) \)



####  

