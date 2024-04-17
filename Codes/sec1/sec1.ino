int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int tiempo = 200;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(tiempo);
  digitalWrite(led1, LOW);
  delay(tiempo);
  digitalWrite(led2, HIGH);
  delay(tiempo);
  digitalWrite(led2, LOW);
  delay(tiempo);
  digitalWrite(led3, HIGH);
  delay(tiempo);
  digitalWrite(led3, LOW);
  delay(tiempo);
  digitalWrite(led4, HIGH);
  delay(tiempo);
  digitalWrite(led4, LOW);
  delay(tiempo);
}
