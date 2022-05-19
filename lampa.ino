//#include<UltraDistSensor.h>
#include <Wire.h> 
int blue = 13;// choose the pin for the LED
int red = 3;
int green = 4;
int inputPin = 2; // choose the input pin (for PIR sensor)             // we start, assuming no motion detected
int const trigPin = 6;
int const echoPin = 5;
int val = 0; // variable for reading the pin status

int distance;
//UltraDistSensor s;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    //trigger pin -> high pt 5 microsecunde
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(blue, OUTPUT); // declare LED as output
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(inputPin, INPUT); // declare sensor as input
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);   
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin); // read input value
  distance = 0.01723 * readUltrasonicDistance(6, 5);
  Serial.println(distance);
//  distance = s.distanceInCm();
  if (val == HIGH) { // check if the input is HIGH
    if (distance > 40){
      digitalWrite(red,HIGH);
      digitalWrite(blue,LOW);
      digitalWrite(green,LOW);
      delay(1500);
      digitalWrite(red,LOW);
      digitalWrite(blue,HIGH);
      digitalWrite(green,HIGH);
      delay(1500);
    }
    if (distance > 25 && distance < 40){
      digitalWrite(blue, HIGH);
      digitalWrite(green, LOW);  
      digitalWrite(red, LOW);
      delay(500);  
    }
    if (distance > 10 && distance < 25){
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);  
      digitalWrite(red, HIGH);
      delay(500);   
    }
    if (distance < 10){
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);  
      digitalWrite(blue, HIGH);
      delay(500);   
    }
  }
  else {
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);  
    digitalWrite(red, LOW);  
  }
}
