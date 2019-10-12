// Include the Servo library 
#include <Servo.h> 

// Include the required Servo Libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int speed_constant = 20;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);
  Serial.println("Setup");

  // begin adafruit motor shield
  AFMS.begin();
  myMotor1->setSpeed(10);
  myMotor2->setSpeed(10);
}

void loop() {
  // set sensors equal to variables so they can be used in calculaiton

  if (Serial.available() > 0 ) {
    char temp = Serial.read();
    if (temp == '+') {
      speed_constant = speed_constant + 10;
    }
    if (temp == '-') {
      speed_constant = speed_constant - 10;
    }
  }
  long sensor1 = analogRead(A0); // on the left
  long sensor2 = analogRead(A1); // on the right

  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  
  myMotor1->setSpeed(10*(sensor1-sensor2)/50+speed_constant);
  myMotor2->setSpeed(10*(sensor2-sensor1)/50+speed_constant);
  
  // display IR sensor values
  // IR values are about 952 when pointed at floor, and 1002 when pointed at tape
  Serial.print(sensor1);
  Serial.print("\t");
  Serial.println(sensor2);
  Serial.print("\t");
  Serial.print(speed_constant);
}
