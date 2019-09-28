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

Observed values from 0 to 1000. Theoretically I believe it should be from 0-1023<br>
[Video of the setup](https://i.imgur.com/Z4QRXV3.mp4)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

With incremental pressure applied it appears to be logarithmic

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes, by transferring 0-1023 (1024 values) to buckets of voltages 0-255 in Red, Blue and Green. The logic and code can be chosen to suit our need.

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

I'm currently using the 10k resistor and have received reasonable volatge figures. However the datasheet suggests using a higher resistance resistor.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

FSR and Photocell seem highly sensitive to stimulus (pressure/bend/light) and show a more logarithmic relationship with change in stimulus. For Softpot, theoretically it should be linear, my experience has been similar as well, a rough guess would be a polynomial like function in response to stimulus. Flex sensor exhibits a polynomial function too. I found bending as a stimulus difficult to assess.

***Additional - Modify the example code for the OLED display to read content from the A0 input

[View Code here](https://github.com/ankit-health-tech/device-lab3/blob/master/softpot_OLED.ino)

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[View Code Used](https://github.com/ankit-health-tech/device-lab3/blob/master/acceldemo.ino)

**Take a picture of your screen working insert it here!**
[Picture of results]<br><img src="https://i.imgur.com/gHJn83g.jpg" height="50%" width="50%"><br>

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes it is of relevance. Each state in the code has a defined function, State 0: Clears Memory, State 1: Reads it, State 2: Writes on the memory. If we follow the order, 0->1->2, we will never get to read the new content written in Step 2. A particular order is crucial to get the desired result.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

For individual states, majority of the code is in the setup since these are essential like functional entities called in by the loop in the main Switchstate code. Hence for the main switchstate code we have code in a loop that continuously calls upon individual state codes to run once and then return to the main loop code.

**c. How many byte-sized data samples can you store on the Atmega328?**

1024 byte sized data points.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

Analog data varies from 0-1023, whereas 1 byte ranges from 0-255. In such a scenario there is some loss of quality and the Analog data can be divided into smaller indentifiable entities. I2C does not work with analog data, it transfer 1byte of data at a time.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

Using EEPROM Put feature you can split data across bytes by defining the address logic.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

[View Code here](https://github.com/ankit-health-tech/device-lab3/blob/master/softpot_OLED.ino)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
