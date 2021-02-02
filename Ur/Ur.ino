#include <Stepper.h>
#include <LiquidCrystal.h>

int butt1Down = 6;
int buttStart = 7;
int butt2Down = 5;
int butt1Up = 3;
int butt2Up = 2;
int pot = 0;
int ls = 13;
int ts = 12;
int rs = 11;
int bs = 10;
int speed = 5;
int RS = 9;
int Enable = A4;
int D4 = 8;
int D5 = A1;
int D6 = A2;
int D7 = A3;

Stepper motor = Stepper(315, ls, ts, rs, bs);
LiquidCrystal lcd(9, A4, 8, A1, A2, A3);

void setup()
{
  lcd.begin(16, 2);
  pinMode(butt1Down, INPUT);
  pinMode(butt2Down,INPUT);
  pinMode(butt1Up, INPUT);
  pinMode(butt2Up, INPUT);
  pinMode(buttStart, INPUT);
  pinMode(pot, INPUT);
  pinMode(ls, OUTPUT);
  pinMode(ts, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(bs, OUTPUT);

  while(!Serial);

  Serial.begin(9600);
  motor.setSpeed(5);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop()
{
  motor.setSpeed(speed);
  int steps = Serial.parseInt();
  motor.step(steps);
  Serial.println(steps);
  if(pot == HIGH){
  	speed =+ 5;
  }
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

}
