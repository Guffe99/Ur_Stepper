//Include Stepper Motor and LCD libraries
#include <Stepper.h>                           // Include libraries
#include <LiquidCrystal.h>
#define seconds() ((millis()-timeDiff-millisDiff)/1000)   // Define seconds() variable

// Define pins 2-13
const int buttGUp = 2;                                    // Button - Guest team point +1
const int buttHUp = 3;                                    // Button - Home team point +1
#define buzz 4                                            // Buzzer
const int buttGDown=5;                                    // Button - Guest team point -1
const int buttHDown=6;                                    // Button - Home team point -1
#define buttTime 7                                        // Time / stop button
#define pinD4 8                                           // Data pin 4
#define pinRS  9im                                        // Register Select
#define bs 10                                             // Bottom side of Stepper motor
#define rs 11                                             // Right side of Stepper motor
#define ts 12                                             // Top side of Stepper motor
#define ls 13                                             // Left side of Stepper motor

// Hack some analog pins and stuff
#define pinPot A0                           // Potentiometer pin
#define pinD5 A1                            // Data pin 5-7
#define pinD6 A2
#define pinD7 A3
#define pinEnable A4                        // Enable pin for LCD

// Define variables
float potvalue = 0;                         // Potentiometer value
int H = 0;                                  // Home team points
int G = 0;                                  // Guest team points
int T = 3;                                  // Time stage identifier
int val=0;                                  // Value used for buttTime
int old_val=0;                              // Old comparison value that works with val
int state=0;                                // buttTime state variable
int time;                                   // Potentiometer time set
int timeStop = 0;                           // Save current time in variable
int timeStart = 0;                          // Save start time
int timeDiff = 0;                           // Timestop - timestart
int timeDiff2 = 0;                          // Save current timeDiff in variable
int millisDiff = 0;                         // Time between program start and timer start
long timeMin;                               // Minutes left on counter
long timeSek;                               // Seconds left on counter

// Define LCD-monitor and stepper motor
int steps = time;                                                   // Number of steps
Stepper motor = Stepper(steps, ls, rs, ts, bs);                     // Define motor
LiquidCrystal lcd(pinRS, pinEnable, pinD4, pinD5, pinD6, pinD7);    

void setup(){
  pinMode(buttHDown, INPUT);
  pinMode(buttGDown,INPUT);
  pinMode(buttHUp, INPUT);
  pinMode(buttGUp, INPUT);
  pinMode(buttTime, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(pinPot, INPUT);
  pinMode(ls, OUTPUT);
  pinMode(ts, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(bs, OUTPUT);
  pinMode(pinRS, OUTPUT);
  pinMode(pinEnable, OUTPUT);
  pinMode(pinD4, OUTPUT);
  pinMode(pinD5, OUTPUT);
  pinMode(pinD6, OUTPUT);
  pinMode(pinD7, OUTPUT);
  lcd.begin(16, 2);

  digitalWrite(buzz, HIGH);
  Serial.begin(9600);

  // Set the speed of the stepper motor
  motor.setSpeed(1/time);

  // Set up the LCD's number of columns and rows:

  // Print a message to the LCD.
}
//Updates the LCD with the correct time and points
void refreshLCD()
  {
  lcd.setCursor(0,0);
  lcd.print("Tid:");

  if (T < 3){
    if (timeMin >= 100){
      lcd.setCursor (5,0);
    }

    if (timeMin < 100 && timeMin >= 10){
      lcd.setCursor (5,0);
      lcd.print(" ");
      lcd.setCursor (6,0);
    }

    if (timeMin < 10){
      lcd.setCursor (6,0);
      lcd.print(" ");
      lcd.setCursor (7,0);
    }

    lcd.print(timeMin);
    lcd.setCursor (8,0);
    lcd.print(":");

    if ((timeSek - 60 * timeMin) >= 10){
      lcd.setCursor (9,0);
    }

    if ((timeSek - 60 * timeMin) < 10){
      lcd.setCursor (9,0);
      lcd.print(0);
      lcd.setCursor (10,0);
    }
    lcd.print(timeSek - 60 * timeMin);
  }
  // If sentences removing unused numbers

  // H-part
  if (H <= 0) {
    H = 0;
  }
  if (0 <= H < 10) {
    lcd.setCursor(3,1);
    lcd.print("  ");
  }
  if (10 <= H < 100) {
    lcd.setCursor(4,1);
    lcd.print(" ");
  }

  // G-part
  if (G <= 0) {
    G = 0;
  }
  if (0 <= G < 10) {
    lcd.setCursor(9,1);
    lcd.print("  ");
  }
  if (10 <= G < 100) {
    lcd.setCursor(10,1);
    lcd.print(" ");
  }

  lcd.setCursor (0,1);
  lcd.print("H:");
  lcd.setCursor (2,1);
  lcd.print(H);
  lcd.setCursor (6,1);
  lcd.print("G:");
  lcd.setCursor (8,1);
  lcd.print(G);
  delay(40);
}

void loop(){
  refreshLCD();

  //Get the desired time in minutes from the potentiometer.
  //And calculate the seconds.
  int potValue = analogRead(pinPot);
  time = map(potValue, 0, 1023, 1, 120);
  int min = time;
  int sek = 60 * min;

  //As long as marker (T) is one the time is updated
  if (T == 2){
    timeSek = sek - seconds();
    timeMin = floor((sek-seconds())/60);
  }

  //Serial.println(timeMin);
  //Serial.println(timeSek - 60 * timeMin);
  //Serial.println(T);

  //When the time reaches "0:00", T gets changed and
  //the time doesn't update anymore. (To avoid underflow)
  if (timeMin < 1 && timeSek < 1 && T == 2){
    timeMin = 0;
    timeSek = 0;
    T = 1;
  }

  if (T == 1){
    refreshLCD();
    digitalWrite(buzz, LOW);
    delay(1000);
    digitalWrite(buzz, HIGH);
    T = 0;
  }

  //Serial.print(H);
  while (digitalRead(buttHUp  ) == HIGH) { if (digitalRead(buttHUp  ) == LOW) {H++; }}

  while (digitalRead(buttHDown) == HIGH) { if (digitalRead(buttHDown) == LOW) {H--; }}

  while (digitalRead(buttGUp  ) == HIGH) { if (digitalRead(buttGUp  ) == LOW) {G++; }}

  while (digitalRead(buttGDown) == HIGH) { if (digitalRead(buttGDown) == LOW) {G--; }}

  refreshLCD();
  digitalWrite(buzz, HIGH);

  val=digitalRead(buttTime);
  if( (val==HIGH) && (old_val==LOW)) {
    state=1-state;
  }

  old_val=val;

  if (state == 1) {
    motor.step(0);
    timeStart = millis();
    timeDiff = timeStart - timeStop;
    timeDiff2 = timeDiff;
    T = 2;
  }
  if (state == 0) {
    motor.step(time);
    timeStop = millis() - timeDiff2;

    if (T == 3){
      lcd.setCursor (8,0);
      lcd.print(":");
      lcd.setCursor (9,0);
      lcd.print("00");
      millisDiff = millis();
    }
    if (T == 3 && time >= 100){
      lcd.setCursor(5,0);
      lcd.print(time);
    }
    if (T == 3 && time < 100 && time >= 10){
      lcd.setCursor(6,0);
      lcd.print(time);
    }
    if (T == 3 && time > 10){
      lcd.setCursor(7,0);
      lcd.print(time);
    }
  }
}
