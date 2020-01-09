# Explaining the Code

The voltage will be a value between 0 and 5 volts, and it will have a fractional part \(for example, it might be 2.5 volts\), so you’ll need to store it inside a float. Create a variable named voltage to hold this number. Divide sensorVal by 1024.0 and multiply by 5.0. The new number represents the voltage on the pin. 

Just like with the sensor value, you’ll print this out to the serial monitor.

every 10 millivolts of change from the sensor are equivalent to a temperature change of 1 degree Celsius. It also indicates that the sensor can read temperatures below 0 degrees. Because of this, you’ll need to create an offset for values below freezing \(0 degrees\). If you take the voltage, subtract 0.5, and multiply by 100, you get the accurate temperature in degrees Celsius. Store this new number in a floating point variable called temperature.

Now that you have the real temperature, print that out to the serial monitor too. Since the temperature variable is the last thing you’re going to be printing out in this loop, you’re going to use a slightly different command: Serial.println\(\). This command will create a new line in the serial monitor after it sends the value. This helps make things easier to read in when they are being printed out.  
  


