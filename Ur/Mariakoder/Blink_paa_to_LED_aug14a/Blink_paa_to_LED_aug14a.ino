/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#define LED_PU 13
#define LED_PD 12
#define SW_PD 7
#define SW_PV 8
bool knap1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PU, OUTPUT);
  pinMode(LED_PD, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  knap1 = digitalRead(SW_PD);
  Serial.println(knap1);
}
  /*
  digitalWrite(LED_PU, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PD, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(LED_PU, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_PD, LOW);
  delay(1000);                       // wait for a second
}
*/
