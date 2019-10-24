//Original code by Dejan Nedelkovski
//Mac version by Niam Moltta
//RADAR

#include <Servo.h>. 

const int trigPin = 7;
const int echoPin = 8;

int servoType = 180   //360 for continuous servo
int servoSpeed = 130  //Servo speed in RPM

long duration;
int distance;
Servo myServo; 

void setup() {
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(9);
  
  myServo.write(90);    //stop
}

void loop() {
  
  for(int i=15;i<=165;i++){  
    if(servoType == 180)
    {
      myServo.write(i);
    }
    else if(servoType == 360)
    {
      myServo.write(180);   //Rotate CW
      delay(((1/360)/servoSpeed)*60000);
      myServo.write(90);    //stop
    }
    delay(30);
    distance = calculateDistance();

    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance); 
    Serial.print("."); 
  }
  
  for(int i=165;i>15;i--){  
    if(servoType == 180)
    {
      myServo.write(i);
    }
    else if(servoType == 360)
    {
      myServo.write(0);   //Rotate CCW
      delay(((1/360)/servoSpeed)*60000);
      myServo.write(90);    //stop
    }
    delay(30);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
//enjoy!
