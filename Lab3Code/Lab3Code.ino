// Include the Servo library 
#include <Servo.h> 
Servo Servo1;
Servo Servo2;
void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  Servo1.attach(11);
  Servo2.attach(9);
}

void loop() {
//  Serial.println("A0:");
  Serial.println(analogRead(A0));
//  Serial.println("A1:");
//  Serial.println(analogRead(A1));
  Servo1.write(i);
  Servo2.write(j);
  

}
