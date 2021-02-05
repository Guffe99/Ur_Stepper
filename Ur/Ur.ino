buttTime#include <Stepper.h>
#include <LiquidCrystal.h>

// Define pins
#define butt2Up 2
#define butt1Up 3
#define buzz 4
#define butt2Down 5
#define butt1Down 6
#define buttTime 7
#define D4 8
#define RS 9
#define bs 10
#define rs 11
#define ts 12
#define ls 13

// Hack some analog pins and stuff
int pot = A0;
int D5 = A1;
int D6 = A2;
int D7 = A3;
int Enable = A4;

// Define variables
int speed = 5;
int buttonPrevious = HIGH;
float potvalue = 0;
int x = 0;

// Define LCD-monitor and stepper motor
Stepper motor = Stepper(315, ls, ts, rs, bs);
LiquidCrystal lcd(9, A4, 8, A1, A2, A3);

// LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2)

void setup()
{
  lcd.begin(16, 2);
  pinMode(butt1Down, INPUT);
  pinMode(butt2Down,INPUT);
  pinMode(butt1Up, INPUT);
  pinMode(butt2Up, INPUT);
  pinMode(buttTime, INPUT);
  pinMode(pot, INPUT);
  pinMode(ls, OUTPUT);
  pinMode(ts, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(bs, OUTPUT);
  pinMode(motor, OUTPUT);
  pinmode(lcd, OUTPUT);

  // while(!Serial);

  Serial.begin(9600);
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
  if(pot == HIGH){
  	speed =+ 5;
  print(time)
  }


  potValue = analogRead(pot);
  time = potValue/10.23



  // lcd.setCursor(0, 1);
  // // print the number of seconds since reset:
  // lcd.print(millis() / 1000);

}
