
const int motorTerminal1 = 8; // Digital Pin 1 connects to motor terminal 1
const int motorTerminal2 = 12; // Digital Pin 2 connects to motor terminal 2
const int enablePin = 5; // Digital pin 10 connects to the enable pin 
const int motorTerminal3 = 7; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal4 = 4; // Digital Pin 4 connects to motor terminal 2
const int enablePin2 = 6; // Digital pin 9 connects to the enable pin 
const int photoLeft = A0; // Analog pin 0 connects to the left photoresistor
const int photoRight = A1; // Analog pin 1 connects to the right photoresistor
const int ledPhoto = 10;   // Digital pin 10 connects to LED

void setup() 
{

  Serial.begin(9600);
  //The rest of the pins function as outputs
  pinMode(motorTerminal1, OUTPUT);
  pinMode(motorTerminal2, OUTPUT);
  //pinMode(enablePin, OUTPUT);
  pinMode(motorTerminal3, OUTPUT);
  pinMode(motorTerminal4, OUTPUT);
  //pinMode(enablePin2, OUTPUT);
  
//  digitalWrite(enablePin, HIGH);
//  digitalWrite(enablePin2, HIGH);
  pinMode(ledPhoto, OUTPUT);
}

void loop() 
{
//  forward(5000);
//  backward(5000);
//  motorsOff(1000);
    Serial.println("Start");
    digitalWrite(ledPhoto, HIGH);
    delay(1000);
    int sensorValue(analogRead(photoLeft));
    Serial.println("left: " + sensorValue);
//    Serial.println("right: " + analogRead(photoRight));
}

void forward(int time)
{
  Serial.println("forward");
  digitalWrite(motorTerminal1, LOW); //these logic levels create forward direction
  digitalWrite(motorTerminal2, HIGH); 
  digitalWrite(motorTerminal3, LOW); //these logic levels create forward direction
  digitalWrite(motorTerminal4, HIGH); 
  delay(time);
}

void backward(int time)
{
  Serial.println("backward");
  digitalWrite(motorTerminal1, HIGH); // these logic levels create reverse direction
  digitalWrite(motorTerminal2, LOW); 
  digitalWrite(motorTerminal3, HIGH); // these logic levels create reserve                                                                                                                                                                                                           direction
  digitalWrite(motorTerminal4, LOW); 
  delay(time);
}

void motorsOff(int time)
{
    Serial.println("stop");
//  digitalWrite(enablePin, LOW);
  digitalWrite(motorTerminal1, LOW);
  digitalWrite(motorTerminal2, LOW);
  digitalWrite(motorTerminal3, LOW);
  digitalWrite(motorTerminal4, LOW);
//  digitalWrite(enablePin2, LOW);
  delay(time);
}

void motorA(int time)
{
  digitalWrite(motorTerminal1, LOW); //these logic levels create forward direction
  digitalWrite(motorTerminal2, HIGH);
  delay(time);
}

void motorB(int time)
{
  digitalWrite(motorTerminal3, LOW); //these logic levels create forward direction
  digitalWrite(motorTerminal4, HIGH);
  delay(time);
}
