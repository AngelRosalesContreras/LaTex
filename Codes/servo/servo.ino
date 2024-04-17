#include <Servo.h>

int pinServo = 6;
int pulsoMin = 1000;
int pulsoMax = 2000;


Servo servo;

void setup() {
  servo.attach(pinServo, pulsoMin, pulsoMax);
}

void loop() {
  servo.write(0);
  delay(5000);
  servo.write(180);
  delay(5000);
}
