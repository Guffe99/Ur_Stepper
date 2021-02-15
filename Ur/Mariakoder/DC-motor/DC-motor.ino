int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int switchPin = 7;
int potPin = A0;
void setup()
{
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(enablePin, OUTPUT);
pinMode(switchPin, INPUT_PULLUP);
Serial.begin(9600);
}
void loop()
{
int speed = analogRead(potPin) / 4;
boolean reverse = digitalRead(switchPin);
setMotor(speed, reverse);
Serial.print(speed);
Serial.print(",");
Serial.print(reverse);
}
void setMotor(int speed, boolean reverse)
{
analogWrite(enablePin, speed);
digitalWrite(in1Pin, ! reverse);
digitalWrite(in2Pin, reverse);
}
