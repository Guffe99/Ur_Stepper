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
int G = 0;

unsigned long timeMin;
unsigned long timeSek;

// Define LCD-monitor and stepper motor
Stepper motor = Stepper(120, ls, ts, rs, bs);
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

  int potValue = analogRead(pinPot);
  int time = map(potValue, 0, 1023, 1, 120);
  //int time2 = 60*time;
  int min = time;
  int sek = 60*min;

  timeSek = sek - seconds();
  timeMin = floor((sek-seconds())/60);
  // Serial.println(timeMin);
  // Serial.println(timeSek);

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
