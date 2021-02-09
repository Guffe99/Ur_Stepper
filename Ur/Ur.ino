//Include Stepper Motor and LCD libraries
#include <Stepper.h>
#include <LiquidCrystal.h>

// Define pins
#define butt2Up 2
#define butt1Up 3
#define buzz 4
#define butt2Down 5
#define butt1Down 6
#define buttTime 7
#define pinD4 8
#define RS 9
#define bs 10
#define rs 11
#define ts 12
#define ls 13

// Hack some analog pins and stuff
#define pinPot A0
#define pinD5 A1
#define pinD6 A2
#define pinD7 A3
#define pinEnable A4

// Define variables
int speed = 5;
int buttonPrevious = HIGH;
float potvalue = 0;
int x = 0;

// Define LCD-monitor and stepper motor
Stepper motor = Stepper(315, ls, ts, rs, bs);
LiquidCrystal lcd(RS, pinEnable, pinD4, pinD5, pinD6, pinD7);

void setup()
{
  lcd.begin(16, 2);
  pinMode(butt1Down, INPUT);
  pinMode(butt2Down,INPUT);
  pinMode(butt1Up, INPUT);
  pinMode(butt2Up, INPUT);
  pinMode(buttTime, INPUT);
  pinMode(pinPot, INPUT);
  pinMode(ls, OUTPUT);
  pinMode(ts, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(bs, OUTPUT);

  Serial.begin(9600);

// Set the speed of the stepper motor
  motor.setSpeed(5);

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello GUSTAVO!");
  lcd.setCursor (0,1);
  lcd.print("From Nicher");
}

void loop()
{

  motor.setSpeed(speed);
  int steps = Serial.parseInt();
  motor.step(steps);
  // Serial.println(steps);
  if(pinpot == HIGH){
  	speed =+ 5;
  }


  // lcd.setCursor(0, 1);
  // // print the number of seconds since reset:
  // lcd.print(millis() / 1000);

}

int potValue = analogRead(pinpot);
int time = map(potValue, 0, 1023, 0, 119);
int min = floor(time/60);
int sek = time - 60*min;

// min = floor(t/60).
// sek   =
