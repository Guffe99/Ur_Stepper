#define BUZZER 4

void setup() {
  // put your setup code here, to run once:
pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (sek == 0 && min == 0){
  digitalWrite(BUZZER,HIGH);
  delay(1000);
  digitalWrite(BUZZER,LOW);}
}
