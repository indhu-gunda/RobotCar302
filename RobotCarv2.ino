`const int motorTerminal1 = 10; // Digital Pin 1 connects to motor terminal 1
const int motorTerminal2 = 9; // Digital Pin 2 connects to motor terminal 2
 //const int enablePin = 5; // Digital pin 10 connects to the enable pin 
const int motorTerminal3 = 6; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal4 = 5; // Digital Pin 4 connects to motor terminal 2
 //   const int enablePin2 = 6; // Digital pin 9 connects to the enable pin 
const int photoLeft = 0; // Analog pin 0 connects to the left photoresistor
const int photoRight = 1; // Analog pin 1 connects to the right photoresistor
const int ledPhoto = 3;   // Digital pin 10 connects to LED
const int irPin = 2;  // Analog pin 2 connects to IR sensor
int sensorValueLeft;
int sensorValueRight;
int irValue;
int leftCutoff = 700;
int rightCutoff = 600;
int irCutoff = 300;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorTerminal1, OUTPUT);
  pinMode(motorTerminal2, OUTPUT);
  pinMode(motorTerminal3, OUTPUT);
  pinMode(motorTerminal4, OUTPUT);
  pinMode(ledPhoto, OUTPUT);
  pinMode(photoLeft, INPUT);
  pinMode(photoRight, INPUT);
}

void loop() {
  digitalWrite(ledPhoto, HIGH);
  delay(100);
  sensorValueLeft= analogRead(photoLeft);
  sensorValueRight = analogRead(photoRight);
  Serial.print(sensorValueLeft);
  Serial.print(" ");
  Serial.print(sensorValueRight);
  Serial.println();
 // irValue= analogRead(irPin);
  //Serial.println("IR value: " + irValue);
  delay(100);
 
//  if(irValue > irCutoff)
//  {
//    Serial.println("Obstacle detected. Stopping");
//    motorsOff(300);
//  }
//  if(sensorValueLeft < leftCutoff )
//  {
//    
//  Serial.println("Left on black! Move left slightly");
//  motorLeft(200);
//  delay(200);
//  }
//  
//  else if (sensorValueRight < rightCutoff )
//  {
//    Serial.println("Right on black! Move right slightly");
//    motorRight(200);
//    delay(200);
//    
//  }
// else if (sensorValueLeft > leftCutoff && sensorValueRight > rightCutoff)
//  {
//    
//    motorsOn(300);
//    motorsOff(100);
//    delay(400);
//    //motorsBack(150);
//   // delay(150);
//    
//    
//  
//  }

  
 

}
void motorAngle(int time)
{
  analogWrite(motorTerminal1, 0);
  analogWrite(motorTerminal2, 100);
  analogWrite(motorTerminal3, 100);
  analogWrite(motorTerminal4, 0);
  delay(time);
  analogWrite(motorTerminal1, 100);
  analogWrite(motorTerminal4, 100);
  //analogWrite(motorTerminal1, 100);
  delay(time);
}

void motorRight(int time)
{

 // analogWrite(motorTerminal1, 0);
 //analogWrite(motorTerminal2, 100);
 Serial.println("moving right");
  analogWrite(motorTerminal3, 0);
  analogWrite(motorTerminal4, 100);
  delay(time);
  //analogWrite(motorTerminal1, 100);
  analogWrite(motorTerminal3, 100);
  //analogWrite(motorTerminal3, 100);
  delay(time);
}

void motorLeft(int time)
{

  analogWrite(motorTerminal1, 0);
  analogWrite(motorTerminal2, 100);
  //analogWrite(motorTerminal3, 0);
 // analogWrite(motorTerminal4, 100);
  delay(time);
  analogWrite(motorTerminal1, 100);
  //analogWrite(motorTerminal3, 100);
  //analogWrite(motorTerminal1, 100);
  delay(time);
}

void motorsOn(int time)
{
  analogWrite(motorTerminal1, 0);
  analogWrite(motorTerminal2, 80);
  analogWrite(motorTerminal3, 0);
  analogWrite(motorTerminal4, 80);
  delay(time);
  analogWrite(motorTerminal1, 80);
  analogWrite(motorTerminal3, 80);
  delay(time);
}

void motorsOff(int time)
{
  //analogWrite(motorTerminal1, 0);
  analogWrite(motorTerminal2, 100);
  //analogWrite(motorTerminal3, 0);
  analogWrite(motorTerminal4, 100);
 // delay(time);
  analogWrite(motorTerminal1, 100);
  analogWrite(motorTerminal3, 100);
  delay(time);
}

void motorsBack(int time){
  analogWrite(motorTerminal1, 100);
  analogWrite(motorTerminal2, 0);
  analogWrite(motorTerminal3, 100);
  analogWrite(motorTerminal4, 0);
  delay(time);
  analogWrite(motorTerminal2, 100);
  analogWrite(motorTerminal4, 100);
  delay(time);
}
