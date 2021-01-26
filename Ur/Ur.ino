#include <Stepper.h>
int butt = 2;
int pot = 0;
int ls = 13;
int ts = 12;
int rs = 11;
int bs = 10;
int speed = 5;

Stepper motor = Stepper(315, ls, ts, rs, bs);

void setup()
{

  pinMode(butt,INPUT);
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
