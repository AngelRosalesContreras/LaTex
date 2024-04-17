void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

int delayVal()
{
  int v; // crea una variable temporal 'v'
  v = analogRead(A0); // lee el valor del potenciómetro
  v /= 4; // convierte 0-1023 a 0-255
  return v; // devuelve el valor final
} 
