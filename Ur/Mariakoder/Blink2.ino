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
#define LED 11
#define buttonUP 8
#define buttonDOWN 10 
#define buttonBLINK 4
#define buttonTIME 6
#define buttonGO 2

bool knapUP;
bool knapDOWN;
bool knapBLINK;
bool knapTIME;
bool knapGO;

int BLINK = 10;
int LYSSTYRKE = 255;
int TIME = 500;

unsigned long knapTID_last;
const long interval = 250;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(buttonUP, INPUT);
  pinMode(buttonDOWN,INPUT);
  pinMode(buttonBLINK, INPUT_PULLUP);
  pinMode(buttonTIME, INPUT_PULLUP);
  pinMode(buttonGO,INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  unsigned long tid = millis();
  
  knapUP = digitalRead(buttonUP);
  knapDOWN = digitalRead(buttonDOWN);
  knapBLINK = digitalRead(buttonBLINK);
  knapTIME = digitalRead(buttonTIME);
  knapGO = digitalRead(buttonGO);

//Start knappen
  if (knapGO == LOW) {                  //Når knap trykkes ned, starter blink på LED
    for(int i = 0; i < BLINK; i++) {    //Der køres antal BLINK runder på LED'en, hvor den tændes i TID sek og slukkes i TID sek
      analogWrite(LED,LYSSTYRKE);
      delay(TIME);
      analogWrite(LED,0);
      delay(TIME);
    }
  }
//Ændring af BLINK
  if (knapBLINK == LOW){
    if ((knapDOWN == HIGH) && (tid - knapTID_last >= interval)) {
       BLINK--;
       Serial.print(BLINK);
       knapTID_last = tid;
    }
  }
   if (knapBLINK == LOW){
    if ((knapUP == LOW) && (tid - knapTID_last >= interval)) {
       BLINK++;
       Serial.print(BLINK);
       knapTID_last = tid;
    }
   }
//Ændring af TIME
  if (knapTIME == LOW){
    if ((knapDOWN == HIGH) && (tid - knapTID_last >= interval)) {
       TIME-=50;
       Serial.print(TIME);
       knapTID_last = tid;
    }
  }
   if (knapTIME == LOW){
    if ((knapUP == LOW) && (tid - knapTID_last >= interval)) {
       TIME+=50;
       Serial.print(TIME);
       knapTID_last = tid;
    }
   }
}
  
  /*
  digitalWrite(LED_PU, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PU2, HIGH);
  delay(1000);                       // wait for a second
  
  digitalWrite(LED_PU, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_PU2, LOW);  
  delay(1000);                       // wait for a second
  */
