int column[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A5, A4};
int layer[4] = {A3, A2, A1, A0};

int x = 750;
int y = 200;


void setup(){
  for (int i = 0; i < 16; i++){
    pinMode(column[i], OUTPUT);
    }
  for (int i = 0; i < 4; i++){
    pinMode(layer[i], OUTPUT);
  }
}

void loop(){
  start();
  delay(x);
  startSequence();
  delay(x);
  diagonalLayer();
  delay(x);
}

//FUNCTIONS:

void start(){
  for (int i = 0; i < 16; i++)
 {
  digitalWrite(column[i], LOW);
 }
 for (int i = 0; i < 4; i++)
 {
  digitalWrite(layer[i], HIGH);
 }
 delay(x);
 for (int i = 0; i < 16; i++)
 {
  digitalWrite(column[i], HIGH);
 }
 for (int i = 0; i < 4; i++)
 {
  digitalWrite(layer[i], LOW);
 }
 delay(x);
 for (int i = 0; i < 16; i++)
 {
  digitalWrite(column[i], LOW);
 }
 for (int i = 0; i < 4; i++)
 {
  digitalWrite(layer[i], HIGH);
 }
 delay(x);
 for (int i = 0; i < 16; i++)
 {
  digitalWrite(column[i], HIGH);
 }
 for (int i = 0; i < 4; i++)
 {
  digitalWrite(layer[i], LOW);
 }
}

void startSequence(){
  turnFirstLayerOn();
  delay(x/4);
  turnFirstLayerOff();
  turnSecondLayerOn();
  delay(x/4);
  turnSecondLayerOff();
  delay(x/4);
  turnThirdLayerOn();
  delay(x/4);
  turnThirdLayerOff();
  delay(x/4);
  turnFourthLayerOn();
  delay(x/4);
  turnFourthLayerOff();
  turnThirdLayerOn();
  delay(x/4);
  turnThirdLayerOff();
  delay(x/4);
  turnSecondLayerOn();
  delay(x/4);
  turnSecondLayerOff();
  delay(3*x/4);
  turnFirstLayerOn();
  delay(x/4);
  turnFirstLayerOff();
  delay(3*x/4);
}

void diagonalLayer(){

  turnOnRow1();
  turnOnRow2();
  turnOnRow3();
  turnOnRow4();
  delay(x/4);
  turnOnRow4Opposite();
  turnOnRow3Opposite();
  turnOnRow2Opposite();
  turnOnRow1Opposite();
  delay(2*x/4);
  
  turnOnRow1();
  delay(3*x/4);
  turnOnRow2();
  delay(3*x/4);
  turnOnRow3();
  delay(2*x/4);
  turnOnRow4();
  delay(2*x/4);
  turnOnRow4Opposite();
  delay(x/4);
  turnOnRow3Opposite();
  delay(2*x/4);
  turnOnRow2Opposite();
  delay(x/3);
  turnOnRow1Opposite();
  delay(x/3);
  turnOnRow1();
  turnOnRow2();
  turnOnRow3();
  turnOnRow4();
  delay(x/3);
  turnOnRow4Opposite();
  turnOnRow3Opposite();
  turnOnRow2Opposite();
  turnOnRow1Opposite();
  

  turnOnRow1Back();
  delay(2*x/4);
  turnOnRow2Back();
  delay(x/4);
  turnOnRow3Back();
  delay(2*x/4);
  turnOnRow4Back();
  delay(2*x/4);
  turnOffRow4Back();
  delay(x/4);
  turnOffRow3Back();
  delay(x/4);
  turnOffRow2Back();
  delay(x/4);
  turnOffRow1Back();
  delay(2*x/4);
  
  turnOnRow1Back();
  turnOnRow2Back();
  turnOnRow3Back();
  turnOnRow4Back();
  delay(x/4);
  turnOffRow1Back();
  turnOffRow2Back();
  turnOffRow3Back();
  turnOffRow4Back();
  delay(2*x/4);

}
