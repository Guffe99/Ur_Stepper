// Dim an LED using a PWM pin
int PWMpin = 10;

  for (int i = 0; i <= 255; i++) {
    analogWrite(PWMpin, i);
    delay(10);
  }
}
