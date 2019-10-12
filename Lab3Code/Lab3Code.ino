 // Include the required Servo Libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int speed_constant = 20;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);


void setup() {
  // initialize serial
  Serial.begin(9600);
  Serial.println("Setup");

  // begin adafruit motor shield
  AFMS.begin();
  myMotor1->setSpeed(10);
  myMotor2->setSpeed(10);
}

void loop() {
  // use serial port to increment speed
  if (Serial.available() > 0 ) {
    char temp = Serial.read();
    if (temp == '+') {
      speed_constant = speed_constant + 10;
    }
    if (temp == '-') {
      speed_constant = speed_constant - 10;
    }
  }

  // set sensors equal to variables so they can be used in calculaiton
  long sensor1 = analogRead(A0); // on the left
  long sensor2 = analogRead(A1); // on the right

  // set the direction of the motors in the direction we want the robot to move
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);

  // calculate the speed of each motor using proportional control
  int m1_speed = (14*(sensor1-sensor2)/50+speed_constant);
  int m2_speed = (14*(sensor2-sensor1)/50+speed_constant);

  // set speed of each motor
  myMotor1->setSpeed(m1_speed);
  myMotor2->setSpeed(m2_speed);
  
  // display IR sensor values
  // IR values are about 952 when pointed at floor, and 1002 when pointed at tape
  Serial.print(millis());
  Serial.print(",");
  Serial.print(sensor1);
  Serial.print(",");
  Serial.print(sensor2);
  Serial.print(",");
  Serial.print(m1_speed);
  Serial.print(",");
  Serial.println(m2_speed);
  
  
}
