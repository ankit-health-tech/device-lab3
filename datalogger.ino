/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/
//Pressure based clear, read write on EEPROM

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
const int EEPROMSIZE=1024;


int fsrAnalogPin = 0;
int tensvalue = 0;
int unitsvalue = 0;
byte value;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  
}

void loop() {

  Serial.println("CLEARING EEPROM");
  printthis("CLEARING EEPROM");
  for (int i = 0; i < EEPROMSIZE; i++) {
    EEPROM.write(i, 0);
  }
  delay(2000);
  Serial.println("CLEARED!");
  printthis("CLEARED!");
  delay(1000);
  
  Serial.println("WRITING TO EEPROM");
  printthis("WRITING TO EEPROM");
  delay(1000);
  int fsrReading = analogRead(fsrAnalogPin);
  tensvalue = (fsrReading-fsrReading%10)/10;
  unitsvalue = (fsrReading-10*tensvalue);
  EEPROM.write(0,tensvalue);
  EEPROM.write(1,unitsvalue);
  Serial.println("Written!");
  Serial.println(fsrReading);
  printthis("Wrote!");
  printthis(fsrReading);
  delay(1000);

  Serial.println("Reading from EEPROM");
  printthis("READING FROM EEPROM");
  delay(1000);
  printthis("Values are");
  for (int i = 0; i < 10; i++) {
    value = EEPROM.read(i);
    Serial.print(value);
    String val = String(value);
    printthis(val);
    delay(1000);
  }
  delay(2000);
  printthis("THE END");
  delay(5000);
  
}

void printthis(String x){
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(x);
  display.display();      // Show initial text
  delay(100);
}



