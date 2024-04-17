const int botonPin = 2; 

void setup() {
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
}

// Funcion para leer el estado del boton
bool leerEstadoBoton() {
  return digitalRead(botonPin) == HIGH;
}

void loop() {
  // Llamar a la funcion para leer el estado del boton
  bool estadoBoton = leerEstadoBoton();
  // Mostrar el estado del boton por la comunicacion serial
  Serial.print("Estado del boton: ");
  Serial.println(estadoBoton ? "Presionado" : "No presionado");

  delay(500);
}