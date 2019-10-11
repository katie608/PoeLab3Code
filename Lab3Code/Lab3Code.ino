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

  // set up motors
  Servo1.attach(11);
  Servo2.attach(9);

  // begin adafruit motor shield
  AFMS.begin();
  myMotor1->setSpeed(50);
  myMotor2->setSpeed(50);
}

void loop() {
  // set sensors equal to variables so they can be used in calculaiton
  long sensor1 = analogRead(A0); // on the left
  long sensor2 = analogRead(A1); // on the right
  
  // proportional control: (difference / range) * constant
  
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);

  // display IR sensor values
  // IR values are about 952 when pointed at floor, and 1002 when pointed at tape
  Serial.print(sensor1);
  Serial.print("\t");
  Serial.println(sensor2);
}
