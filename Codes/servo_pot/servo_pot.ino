#include <Servo.h>

int pinServo = 6;
int pulsoMin = 1000;
int pulsoMax = 2000;
int valorPot;
int angulo;
int pot = 0;

Servo servo;

void setup() {
  servo.attach(pinServo, pulsoMin, pulsoMax);
}

void loop() {
  valorPot = analogRead(pot);
  angulo = map(valorPot,0,1023,0,180);
  servo.write(angulo);
  delay(20);
}
