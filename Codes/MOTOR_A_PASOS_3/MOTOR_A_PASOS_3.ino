// Definicion de pines
int pin1 = 5;  // Conectar al primer terminal del motor
int pin2 = 4;  // Conectar al segundo terminal del motor
int pin3 = 3;  // Conectar al tercer terminal del motor
int pin4 = 2;  // Conectar al cuarto terminal del motor

// Variables para el control de pasos
int paso = 0;
int pasoo = 0;
int delayTiempo = 1000; // Ajusta este valor segun la velocidad que desees

// Secuencias de pasos
const int UnPaso[4] = {B1000, 
                       B0100,  
                       B0010, 
                       B0001};

const int DosPasos[4] = {B1100, 
                         B0110, 
                         B0011, 
                         B1001};

const int MedioPaso[8] = {B1000, 
                          B1100, 
                          B0100, 
                          B0110, 
                          B0010, 
                          B0011, 
                          B0001, 
                          B1001};

void setup() {
  // Configurar los pines como salida
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  // Elegir la secuencia de pasos segun el valor de "paso"
  
  setOutput(UnPaso);
  //setOutput(DosPasos);
  //setOutput(MedioPaso);

  // Incrementar el valor de "paso" y reiniciarlo si alcanza 3 o 7
  paso = (paso + 1) % 4;
  //paso = (paso + 1) % 8;

  delay(delayTiempo);  // Pausa para controlar la velocidad del motor
}

// Funcion para establecer los valores de los pines de salida
void setOutput(const int* secuencia) {
  digitalWrite(pin1, bitRead(secuencia[paso], 0));
  digitalWrite(pin2, bitRead(secuencia[paso], 1));
  digitalWrite(pin3, bitRead(secuencia[paso], 2));
  digitalWrite(pin4, bitRead(secuencia[paso], 3));
}
