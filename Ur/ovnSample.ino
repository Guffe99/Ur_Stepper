/*//Nichlas Overgaard Laugesen, Maria Mose Nielsen, Gustav Strøm Ottesen.

// Til denne kode benyttes et library der kan downloades under Manage Libraries i 'Værtøjer'-knappen i toppen af arduino programmet.
// Bibloteket hedder "LiquidCrystal I2C"

// Include the libraries:
#include <LiquidCrystal_I2C.h> // Library for LCD

// Define the diodes
#define RLED 6
#define GLED 5

// Define the other components
const int button = 7; // Knap

int FAN     =  3;    // The cooling fan
int RawTemp    = A0;    // The Thermometer
int TEMPAI;          // Temperature Even More Perfect than it Already Is / Temperature sensors target temperature.
int Halo    =  4;    // The Halogenic lamp
int Tempflag =  0;   // Flag for determining if button is on or of when being pressed
int buttonPrevious = HIGH;  // Flag for determining the previous state of the button
float potValue = 0;  // Value of potentiometer
float pot = A1;
int x = 0;

float TempC = 0;
float TempF = 0;

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, example code used to check address of LCD. Turns out the address is the standard 0x27.
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // set LCD to (0x27,16, 02) for 16x2 sized LCD.

void setup() {
  // Initiate LCD, Temp, Fan, Diodes, Halogenic lamp, Button:
  lcd.init();
  lcd.backlight();
  pinMode(RawTemp,   INPUT);
  pinMode(FAN,   OUTPUT);
  pinMode(RLED,  OUTPUT);
  pinMode(GLED,  OUTPUT);
  pinMode(Halo,  OUTPUT);
  pinMode(button, INPUT);

  digitalWrite((FAN, RLED, GLED, Halo, button), LOW); //Turns everything off just in case.
  Serial.begin(9600);
}

void loop() {
Serial.println(TempC);

int TempC = (analogRead(RawTemp) * 5.0 /1024.0) * 100.0;
int TempF = (((analogRead(RawTemp) * 5.0 / 1024.0) * 100.0) * 9.0 / 5.0) + 32.0;

  if (x == 1) {
    lcd.setCursor (0, 1);
    lcd.print     ("  TEMP:      F");
    lcd.setCursor (8,1);
    lcd.print     (TempF);
    lcd.setCursor (11,1);
    lcd.print     (" ");
    lcd.setCursor (12,1);
    lcd.print     ((char)223);
    lcd.setCursor (0, 0);       // Set the cursor on the first column and first row.
    lcd.print("TEMPAI:      F");         // Print function: get_Temp() with the 'Temp' pin.
    lcd.setCursor (12,0);
    lcd.print((char)223);
    lcd.setCursor (8, 0);       // Print function: get_Temp() with the 'Temp' pin.
    lcd.print((int)((TEMPAI* 9.0 / 5.0) + 32.0));
  }
  if (x == 0) {
    lcd.setCursor (0,1);
    lcd.print     ("  TEMP:");
    lcd.setCursor (9,1);
    lcd.print     (TempC);
    lcd.setCursor (8,1);
    lcd.print(" ");
    lcd.setCursor (13,1);
    lcd.print     ("C        ");
    lcd.setCursor (12,1);
    lcd.print     ((char)223);
    lcd.setCursor (0, 0);       // Set the cursor on the first column and first row.
    lcd.print("TEMPAI:      C ");
    lcd.setCursor (12, 0);       // Print function: get_Temp() with the 'Temp' pin.
    lcd.print((char)223);
    lcd.setCursor (9,0);
    lcd.print(TEMPAI);
  }

  if (TempC < TEMPAI) {  // Check if temperature is under TEMPAI.
    digitalWrite(Halo, HIGH);     // If true, then turn on the lamp,
    digitalWrite(FAN , HIGH);     // Turn on fan,
  }

  else {  // When the temperature raises above TEMPAI this happens instead:
    digitalWrite(Halo,  LOW);           // The halogenic lamp turns of since the temperature has been reached
    digitalWrite(FAN , HIGH);           // The Fan Keeps being on i guess. (This line could probably be removed)
  }

  if (TempC < TEMPAI * 0.95) {   // LED LOOP
    digitalWrite(RLED,  HIGH);             // Turn on red LED to indicate the heating of the oven
    digitalWrite(GLED,   LOW);             // Turn off the green LED.
  }
  else {
    digitalWrite(RLED,   LOW);             // The red LED turns off,
    digitalWrite(GLED,  HIGH);             // The green LED... you guessed it, turns on to indicate the reached temperature.
  }

  int buttonSwitch = digitalRead(button);                            //Button switch code keeps track of on/off states.
  while (digitalRead(button) == HIGH && buttonPrevious == 0) {
    x = 1;
    delay(10);
    if (digitalRead(button) == LOW) {
      buttonPrevious = 1;
    }
  }

  while (digitalRead(button) == HIGH && buttonPrevious == 1) {
    x = 0;
    delay(10);
    if (digitalRead(button) == LOW) {
      buttonPrevious = 0;
    }
  }

  potValue = analogRead(pot);
  TEMPAI = potValue / 10.23 * 0.71 + 10;
}
//01.12.2020 08.57
Du har sendt 1. december 2020
Fix resten: //Nichlas Overgaard Laugesen, Maria Mose Nielsen, Gustav Strøm Ottesen.

// Til denne kode benyttes et library der kan downloades under Manage Libraries i 'Værtøjer'-knappen i toppen af arduino programmet.
// Bibloteket hedder "LiquidCrystal I2C"

// Include the libraries:
#include <LiquidCrystal_I2C.h> // Library for LCD

// Define the diodes
#define RLED 6
#define GLED 5

// Define components
const int button = 7;                                     // Button
int FAN     =  3;                                         // The cooling fan
int RawTemp    = A0;                                      // The Thermometer
int TEMPAI;                                               // Temperature Even More Perfect than it Already Is / Temperature sensors target temperature.
int Halo    =  4;                                         // The Halogenic lamp
int Tempflag =  0;                                        // Flag for determining if button is on or of when being pressed
int buttonPrevious = HIGH;                                // Flag for determining the previous state of the button
float potValue = 0;                                       // Value of potentiometer
float pot = A1;
int x = 0;                                                // Value for determining buttonState

float TempC = 0;                                          // Temperature floats
float TempF = 0;

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, example code used to check address of LCD. Turns out the address is the standard 0x27.
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);   // set LCD to (0x27,16, 02) for 16x2 sized LCD.

void setup() {
  // Initiate LCD, Temp, Fan, Diodes, Halogenic lamp, Button:
  lcd.init();
  lcd.backlight();
  pinMode(RawTemp,   INPUT);
  pinMode(FAN,   OUTPUT);
  pinMode(RLED,  OUTPUT);
  pinMode(GLED,  OUTPUT);
  pinMode(Halo,  OUTPUT);
  pinMode(button, INPUT);

  digitalWrite((FAN, RLED, GLED, Halo, button), LOW);     // Turns everything off just in case, before the conditions apply
  Serial.begin(9600);
}

void loop() {

int TempC = (analogRead(RawTemp) * 5.0 /1024.0) * 100.0;                           // Extract celsius from millivolt value
int TempF = (((analogRead(RawTemp) * 5.0 / 1024.0) * 100.0) * 9.0 / 5.0) + 32.0;   // Extract fahranheit temperature from the millivolt value
// Cursor movement and print text below
  if (x == 1) {                                           // Conditions for fahrenheit-buttonState
    lcd.setCursor (0, 1);
    lcd.print     ("  TEMP:      F");
    lcd.setCursor (8,1);
    lcd.print     (TempF);                                // Fahrenheit temperature prints on the second row
    lcd.setCursor (11,1);
    lcd.print     (" ");
    lcd.setCursor (12,1);
    lcd.print     ((char)223);
    lcd.setCursor (0, 0);
    lcd.print("TEMPAI:      F");
    lcd.setCursor (12,0);
    lcd.print((char)223);
    lcd.setCursor (8, 0);
    lcd.print((int)((TEMPAI* 9.0 / 5.0) + 32.0));         // Print Tempai in fahrenheit
  }
  if (x == 0) {                                           // Conditions celsius-temperature
    lcd.setCursor (0,1);
    lcd.print     ("  TEMP:");
    lcd.setCursor (9,1);
    lcd.print     (TempC);                                // Temperature in celsius, printed on the second line, 10th row
    lcd.setCursor (8,1);
    lcd.print(" ");
    lcd.setCursor (13,1);
    lcd.print     ("C        ");
    lcd.setCursor (12,1);
    lcd.print     ((char)223);
    lcd.setCursor (0, 0);
    lcd.print("TEMPAI:      C ");
    lcd.setCursor (12, 0);
    lcd.print((char)223);
    lcd.setCursor (9,0);
    lcd.print(TEMPAI);                                    // Temperature in celsius, printed on teh first line, 10th row
  }

  if (TempC < TEMPAI) {                    // Check if temperature is under TEMPAI.
    digitalWrite(Halo, HIGH);              // If true, then turn on the lamp,
    digitalWrite(FAN , HIGH);              // Turn on fan,
  }

  else {  // When the temperature raises above TEMPAI this happens instead:
    digitalWrite(Halo,  LOW);              // The halogenic lamp turns of since the temperature has been reached
    digitalWrite(FAN , HIGH);              // The Fan Keeps being on i guess. (This line could probably be removed)
  }

  if (TempC < TEMPAI * 0.95) {             // LED LOOP
    digitalWrite(RLED,  HIGH);             // Turn on red LED to indicate the heating of the oven
    digitalWrite(GLED,   LOW);             // Turn off the green LED.
  }
  else {
    digitalWrite(RLED,   LOW);             // The red LED turns off,
    digitalWrite(GLED,  HIGH);             // The green LED... you guessed it, turns on to indicate the reached temperature.
  }

  int buttonSwitch = digitalRead(button);                            //Button switch code keeps track of on/off states.
  while (digitalRead(button) == HIGH && buttonPrevious == 0) {
    x = 1;
    delay(10);
    if (digitalRead(button) == LOW) {
      buttonPrevious = 1;
    }
  }

  while (digitalRead(button) == HIGH && buttonPrevious == 1) {
    x = 0;
    delay(10);
    if (digitalRead(button) == LOW) {
      buttonPrevious = 0;
    }
  }

  potValue = analogRead(pot);
  TEMPAI = potValue / 10.23 * 0.71 + 10;
}*/
