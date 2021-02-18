<<<<<<< current
//Include Stepper Motor and LCD libraries
#include <Stepper.h>
#include <LiquidCrystal.h>
#define seconds() (millis()/1000)

// Define pins
#define buzz 4
#define buttTime 7
#define pinRS 9
#define bs 10
#define rs 11
#define ts 12
#define ls 13
#define pinD4 8

// Hack some analog pins and stuff
#define pinPot A0
#define pinD5 A1
#define pinD6 A2
#define pinD7 A3
#define pinEnable A4

// Define variables
const int buttGUp = 2;
const int buttHUp = 3;
const int buttGDown=5;
const int buttHDown=6;
int speed = 5;
int buttonPrevHUp = LOW;
int buttonPrevHDown = LOW;
int buzzCheck = 0;

int buttonPrevGUp = LOW;
int buttonPrevGDown = LOW;
float potvalue = 0;
int H = 0;
int G = 100;
int T = 1;
int potValue = analogRead(pinPot);
int time = map(potValue, 0, 1023, 1, 120);


unsigned long timeMin;
unsigned long timeSek;

// Define LCD-monitor and stepper motor
int steps = time;
Stepper motor = Stepper(steps, ls, ts, rs, bs);
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

void loop(){
  refreshLCD();
  digitalWrite(buzz, HIGH);

  //Get the desired time in minutes from the potentiometer.
  //And calculate the seconds.
  int min = time;
  int sek = 60 * min;

  //As long as marker (T) is one the time is updated
  if (T == 1){  
    timeSek = sek - seconds();
    timeMin = floor((sek-seconds())/60);
  }

  //Serial.println(timeMin);
  //Serial.println(timeSek - 60 * timeMin);
  //Serial.println(T);

  //When the time reaches "0:00", T gets changed and
  //the time doesn't update anymore. (To avoid underflow)
  if (timeMin < 1 && timeSek < 1){
    timeMin = 0;
    timeSek = 0;
    T = 0;
  }

  //Serial.print(H);
  while (digitalRead(buttHUp  ) == HIGH) { if (digitalRead(buttHUp  ) == LOW) {H++; }}

  while (digitalRead(buttHDown) == HIGH) { if (digitalRead(buttHDown) == LOW) {H--; }}

  while (digitalRead(buttGUp  ) == HIGH) { if (digitalRead(buttGUp  ) == LOW) {G++; }}

  while (digitalRead(buttGDown) == HIGH) { if (digitalRead(buttGDown) == LOW) {G--; }}

  refreshLCD();
  digitalWrite(buzz, HIGH);

  int buttonstate = digitalRead(buttHDown);
  Serial.println(buttonstate);
  }
/*
  motor.setSpeed(speed);
  int steps = Serial.parseInt();
  motor.step(steps);
  // Serial.println(steps);
  // Fix dis
  if(pinPot == HIGH){
    speed =+ 5;
  }
  delay(5);

  if (sek == 0 && min == 0 && buzzCheck == 0){
    digitalWrite(buzz, LOW);
    delay(1000);
    digitalWrite(buzz, HIGH);}
    buzzCheck = 1;
  }*/
=======
//Include Stepper Motor and LCD libraries
#include <Stepper.h>
#include <LiquidCrystal.h>

// Define pins
#define buttGUp 2
#define buttHUp 3
#define buzz 4
#define buttGDown 5
#define buttHDown 6
#define buttTime 7
#define pinRS 9
#define bs 10
#define rs 11
#define ts 12
#define ls 13
#define pinD4 8

// Hack some analog pins and stuff
#define pinPot A0
#define pinD5 A1
#define pinD6 A2
#define pinD7 A3
#define pinEnable A4

// Define variables
int speed = 5;
int buttonPrevHUp = 0;
int buttonPrevHDown = 0;
int buzzCheck = 0;

int buttonPrevGUp = 0;
int buttonPrevGDown = 0;
float potvalue = 0;
int H = 4;
int G = 5;
int min = 0;
int sek = 0;

unsigned long time;
unsigned long timer;

// Define LCD-monitor and stepper motor
Stepper motor = Stepper(315, ls, ts, rs, bs);
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


  Serial.begin(9600);

  // Set the speed of the stepper motor
  motor.setSpeed(5);

  // Set up the LCD's number of columns and rows:

  // Print a message to the LCD.
}
void refreshLCD()
  {
  lcd.setCursor(0,0);
  lcd.print("Starttid: 45:00");
  lcd.setCursor (0,1);
  lcd.print("H:");
  lcd.setCursor (2,1);
  lcd.print(H);
  lcd.setCursor (6,1);
  lcd.print("G:");
  lcd.setCursor (8,1);
  lcd.print(G);
}


void loop(){

  refreshLCD();
  digitalWrite(buzz, HIGH);

  time = 30000;
  millis();
  timer = time - millis();
  Serial.println(timer);


  //Serial.print(H);
  if (digitalRead(buttHUp  ) == HIGH && buttonPrevHUp   == 0) {H++; delay(10); if (digitalRead(buttHUp  ) == LOW) {buttonPrevHUp   = 1;}}

  if (digitalRead(buttHDown) == HIGH && buttonPrevHDown == 0) {H--; delay(10); if (digitalRead(buttHDown) == LOW) {buttonPrevHDown = 1;}}

  if (digitalRead(buttGUp  ) == HIGH && buttonPrevGUp   == 0) {G++; delay(10); if (digitalRead(buttGUp  ) == LOW) {buttonPrevGUp   = 1;}}

  if (digitalRead(buttGDown) == HIGH && buttonPrevGDown == 0) {G--; delay(10); if (digitalRead(buttGDown) == LOW) {buttonPrevGDown = 1;}}

  refreshLCD();

  motor.setSpeed(speed);
  int steps = Serial.parseInt();
  motor.step(steps);
  // Serial.println(steps);
  // Fix dis
  if(pinPot == HIGH){
  	speed =+ 5;
  }
  delay(5);

  if (sek == 0 && min == 0 && buzzCheck == 0){
    digitalWrite(buzz, LOW);
    delay(1000);
    digitalWrite(buzz, HIGH);}
    buzzCheck = 1;
  }



//int potValue = analogRead(pinPot);
//int time = map(potValue, 0, 1023, 0, 119);
//int min = floor(time/60);
//int sek = time - 60*min;

// min = floor(t/60).
// sek   =
>>>>>>> before discard
