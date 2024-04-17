void setup() {
}

void loop() {
}

//Funcion para leer valor analogico
int delayVal()
{
  int v; // crea una variable temporal 'v'
  v = analogRead(A0); // lee el valor de A0
  v /= 4; // convierte 0-1023 a 0-255
  return v; // devuelve el valor final
}
