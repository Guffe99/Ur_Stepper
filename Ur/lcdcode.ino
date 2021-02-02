/*
  The circuit:
 * LCD RS pin to digital pin 9
 * LCD Enable pin to analogpin A4
 * LCD D4 pin to digital pin 8
 * LCD D5 pin to analog pin A1
 * LCD D6 pin to analog pin A2
 * LCD D7 pin to analog pin A3
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, A4, 8, A1, A2, A3);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
 ''
