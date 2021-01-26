#include <stepper.h>
#include <LiquidCrystal.h>

int butt1Down = 6;
int butt2Down = 5;
int butt1Up = 3;
int butt2Up = 2;
int pot = 0;
int ls = 13;
int ts = 12;
int rs = 11;
int bs = 10;
int speed = 5;

Stepper motor = Stepper(315, ls, ts, rs, bs);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2)
  pinMode(butt1Down, INPUT)
  pinMode(butt2Down,INPUT);
  pinMode(butt1Up, INPUT)
  pinMode(butt2Up, INPUT)
  pinMode(pot, INPUT);
  pinMode(ls, OUTPUT);
  pinMode(ts, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(bs, OUTPUT);

  while(!Serial);

  Serial.begin(9600);
  motor.setSpeed(5);
}

void loop()
{
  motor.setSpeed(speed);
  int steps = Serial.parseInt();
  motor.step(steps);
  Serial.println(steps);
  if(butt == HIGH){
  	speed =+ 5;
  }

}
