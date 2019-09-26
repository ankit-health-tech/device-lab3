# Data Logger (and using cool sensors!)

*A lab report by Ankit Malhan*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

The readings on the serial monitor range from 0 to 1023

**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

The ADC of the Arduino is 10ADC which implies it can read 2^10 analog signals

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

[Video of the setup](https://i.imgur.com/qlabXIA.mp4)
<br>
[Circuit Diagram]<br><img src="https://i.imgur.com/sfw5Cop.jpg" height="50%" width="50%"><br>

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[View Code Used](https://github.com/ankit-health-tech/device-lab3/blob/master/acceldemo.ino)

**Take a picture of your screen working insert it here!**
[Picture of results]<br><img src="https://i.imgur.com/gHJn83g.jpg" height="50%" width="50%"><br>

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
