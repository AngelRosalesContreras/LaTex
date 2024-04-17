#include <Servo.h>

int pinServo = 6;
int pulsoMin = 1000;
int pulsoMax = 2000;

Servo servo;

void setup() {
  servo.attach(pinServo, pulsoMin, pulsoMax);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int valor = Serial.parseInt();
    
    if(valor < 0){
      servo.write(0);
      enviarMensaje(valor);
      delay(20);
    }
    else if (valor > 180){
      servo.write(180);
      enviarMensaje(valor);
      delay(20);
    }
    else {
      servo.write(valor);
      enviarMensaje(valor);
      delay(20);
    }
    
  }
}

void enviarMensaje(int x) {
  Serial.print("Moviendo a: ");
  Serial.print(x);
  Serial.println(" grados");
}
