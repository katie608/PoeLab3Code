// Include the Servo library 
#include <Servo.h> 

// Include the required Servo Libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

Servo Servo1;
Servo Servo2;
void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  Servo1.attach(11);
  Servo2.attach(9);
  AFMS.begin();
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
}

void loop() {
//  Serial.println("A0:");
  long sensor1 = analogRead(A0);
  long sensor2 = analogRead(A1);

  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  
  Serial.print(sensor1);
  Serial.print("\t");
  Serial.println(sensor2);
//  Serial.println("A1:");
//  Serial.println(analogRead(A1));
//  Servo1.write(i);
//  Servo2.write(j);
  

}
