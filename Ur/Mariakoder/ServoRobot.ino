#include <Servo.h>                     //Inkludere Servo library
Servo LLegServo, LFootServo, RLegServo, RFootServo;  //Laver servo elementer

#define LEDRED   4                     //Rød LED på pin 4
#define LEDGREEN 8                     //Grøn LED på pin 8
#define BUZZER   7                     //En buzzer (simpel højtaler) på pin 7

//Værdier til at robotten står oprejst (værdierne er i grader):
#define LFootServoDefaultPos 70
#define LLegServoDefaultPos  35
#define RLegServoDefaultPos  140
#define RFootServoDefaultPos 110

int lysSensorPin   = A0;               //Pin til LDR (analog)
int lysSensorValue = 0;                //Variable til at gemme værdien fra sensoren
int distance;                          //Variable til at gemme distance udregnet fra *duration
long duration;                         //Variable brugt til at gemme tiden man får tilbage fra ultralydssensoren

const int trigPin = 12;                //trigPin sender signaler så ultralydssensoren udsender lyd
const int echoPin = 13;                //echoPin lytter efter tilbagevendende ultralyd og giver et signal

unsigned long time;                    //Variable til at gemme tid
unsigned long timer;                   //Variable til at starte tid "forfra"
const unsigned long period = 100;      //Period er til at time morsekoden


void setup(){
// Sætter servoerne op:
LLegServo. attach(6) ;                 // Left Leg på pin 6
LFootServo.attach(11);                 // Left Foot på pin 11
RLegServo. attach(5) ;                 // Right Leg på pin 5
RFootServo.attach(3) ;                 // Right Foot på pin 3

//Sætter servoerne i default position:
LLegServo. write(LLegServoDefaultPos );
LFootServo.write(LFootServoDefaultPos);
RLegServo. write(RLegServoDefaultPos );
RFootServo.write(RFootServoDefaultPos);
delay(1000);                           //Giver robotten tid til at stille sig i defult position

pinMode(LEDRED,  OUTPUT);
pinMode(LEDGREEN,OUTPUT);
pinMode(BUZZER,  OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT );
Serial.begin(9600);
}

void loop(){
//Print comandoer til at tjekke forskellige værdier
  //Serial.println(lysSensorValue);      //Printer sensorværdien fra LDR
  //Serial.print(",");
  //Serial.println(millis());            //Printer den interne tid
  //Serial.print(",");
  //Serial.println(distance);            //Printer afstand i cm (målt af ultralyds sensoren)
  //Serial.print("Fish Tacos ");         //Makes Fish Tacos

lysSensorValue = analog
Read(lysSensorPin);  //Opdatere værdien fra lys sensoren

//Ultralydssensoren tjekker afstand
digitalWrite(trigPin, LOW );
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW );
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

//Når der er mørkt (når sensorValue er lig eller under 750) er den grønne LED slukket og den røde LED tændt og buzzeren "spiller" morsekode
if (lysSensorValue <= 750){
  timer  = millis() - time;               //Nulstiller tiden så den starter fra nul når der bliver mørkt
  digitalWrite(LEDRED,HIGH );
  digitalWrite(LEDGREEN,LOW);

  //'BUZZER' spiller "SOS" i morsekode: En 'periode' er lige med længden af en "prik" i morsekode
  //Servoerne får det til at se ud som om den panikker i mørket
  // . . . (S)
  if (timer >= 1  * period){ digitalWrite(BUZZER,HIGH); LFootServo.write( 60);}
  if (timer >= 2  * period){ digitalWrite(BUZZER,LOW ); RFootServo.write( 90);}
  if (timer >= 3  * period){ digitalWrite(BUZZER,HIGH); LFootServo.write( 80);}
  if (timer >= 4  * period){ digitalWrite(BUZZER,LOW );                       }
  if (timer >= 5  * period){ digitalWrite(BUZZER,HIGH); RLegServo. write(155);}
  if (timer >= 6  * period){ digitalWrite(BUZZER,LOW ); LLegServo. write( 55);}

  // - - - (O)
  if (timer >= 9  * period){ digitalWrite(BUZZER,HIGH); RFootServo.write(110);}
  if (timer >= 12 * period){ digitalWrite(BUZZER,LOW ); LFootServo.write( 75);}
  if (timer >= 13 * period){ digitalWrite(BUZZER,HIGH);                       }
  if (timer >= 16 * period){ digitalWrite(BUZZER,LOW ); LLegServo .write( 15);}
  if (timer >= 17 * period){ digitalWrite(BUZZER,HIGH); RLegServo .write(160);}
  if (timer >= 20 * period){ digitalWrite(BUZZER,LOW );                       }

  // . . . (S)
  if (timer >= 23 * period){ digitalWrite(BUZZER,HIGH); LFootServo.write( 60);}
  if (timer >= 24 * period){ digitalWrite(BUZZER,LOW ); RFootServo.write( 90);}
  if (timer >= 25 * period){ digitalWrite(BUZZER,HIGH); LFootServo.write( 80);}
  if (timer >= 26 * period){ digitalWrite(BUZZER,LOW );                       }
  if (timer >= 27 * period){ digitalWrite(BUZZER,HIGH); RLegServo. write(155);}
  if (timer >= 28 * period){ digitalWrite(BUZZER,LOW ); LLegServo. write( 55);}
  if (timer >= 35 * period){ LLegServo. write(LLegServoDefaultPos );
                             LFootServo.write(LFootServoDefaultPos);
                             RLegServo. write(RLegServoDefaultPos );
                             RFootServo.write(RFootServoDefaultPos);
                             delayMicroseconds(50);
                             time = millis();                                 }   //For at nulstille 'timer' så 'SOS' bliver spillet på repeat mens der er mørkt
  }


//Når der er lyst (når sensorValue er over 650) er den grønne LED tændt og den røde og buzzeren er slukket
else {
  digitalWrite(LEDRED,  LOW );
  digitalWrite(LEDGREEN,HIGH);
  digitalWrite(BUZZER,  LOW );
  LLegServo. write(LLegServoDefaultPos );
  LFootServo.write(LFootServoDefaultPos);
  RLegServo. write(RLegServoDefaultPos );
  RFootServo.write(RFootServoDefaultPos);
  time = millis();
  }
}
