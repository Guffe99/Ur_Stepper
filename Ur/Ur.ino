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


// Define LCD-monitor and stepper motor
Stepper motor = Stepper(315, ls, ts, rs, bs);
LiquidCrystal lcd(pinRS, pinEnable, pinD4, pinD5, pinD6, pinD7);

void setup()
{
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


void loop()
{
  refreshLCD();
  digitalWrite(buzz, HIGH);


  if (digitalRead(buttHUp) == HIGH && buttonPrevHUp == 0) {
    H++;
    refreshLCD();
    delay(10);
    if (digitalRead(buttHUp) == LOW) {
      buttonPrevHUp = 1;
    }
  }

  if (digitalRead(buttHDown) == HIGH && buttonPrevHDown == 0) {
    H--;
    delay(10);
    if (digitalRead(buttHDown) == LOW) {
      buttonPrevHDown = 1;
    }

  }

  if (digitalRead(buttGUp) == HIGH && buttonPrevGUp == 0) {
    G++;
    delay(10);
    if (digitalRead(buttGUp) == LOW) {
      buttonPrevGUp = 1;
    }
  }

  if (digitalRead(buttGDown) == HIGH && buttonPrevGDown == 0) {
    G--;
    delay(10);
    if (digitalRead(buttGDown) == LOW) {
      buttonPrevGDown = 1;
    }
  }

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
