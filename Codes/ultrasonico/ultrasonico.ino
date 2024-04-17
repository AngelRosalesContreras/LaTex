int trig = 10;
int eco = 9;
int duracion;
float distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  duracion = pulseIn(eco,HIGH);
  distancia = duracion / 58.2;
  Serial.println(distancia);
  delay(500);

}
