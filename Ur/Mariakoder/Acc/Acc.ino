#define MOTOR 11
int acc = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  for (acc = 0 ; acc <= 255; acc +=5) {
  analogWrite(MOTOR, acc);
  }
}
