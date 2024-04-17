int in1 = 2;
int in2 = 3;
int ena = 5;
int velocidad;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
}

void loop() {
  for(velocidad = 0; velocidad < 256; velocidad++){
    digitalWrite(ena, velocidad);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}
