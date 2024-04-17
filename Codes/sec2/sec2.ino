int n;
int tiempo = 200;

void setup() {
  for(n=5;n<9;n++){
    pinMode(n, OUTPUT);
  }
}

void loop() {
  for(n=5;n<9;n++){
    digitalWrite(n, HIGH);
    delay(tiempo);
    digitalWrite(n, LOW);
    delay(tiempo);
  }
}
