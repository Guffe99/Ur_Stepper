#define RED 9
#define GREEN 5
#define BLUE 6
int fadeValue1 = 0;
int fadeValue2 = 0;
int fadeValue3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  for (fadeValue1 = 0 ; fadeValue1 <= 255; fadeValue1 += 5) {
  analogWrite(RED, fadeValue1);
  delay(30);
    for (fadeValue2 = 0 ; fadeValue2 <= 255; fadeValue2 += 5) {
    analogWrite(GREEN, fadeValue2);
    delay(30);
      for (fadeValue3 = 0 ; fadeValue3 <= 255; fadeValue3 += 5) {
      analogWrite(BLUE, fadeValue3);
      delay(30);
      }
    }
  }
}
  /*
  for (fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
  analogWrite(RED, fadeValue);
  delay(30);
  }
  for (fadeValue = 255 ; fadeValue >= 0 ; fadeValue -= 5) {
  analogWrite(RED, fadeValue);
  delay(30);
  }
  for (fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(GREEN, fadeValue);
    delay(30);
  }
  for (fadeValue = 255 ; fadeValue >= 0 ; fadeValue -= 5) {
  analogWrite(GREEN, fadeValue);
  delay(30);
  }
  for (fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(BLUE, fadeValue);
    delay(30);
  }
  for (fadeValue = 255 ; fadeValue >= 0 ; fadeValue -= 5) {
  analogWrite(BLUE, fadeValue);
  delay(30);
  }
}
*/
