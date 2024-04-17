
int SENSOR;		// variable almacena valor leido de entrada analogica A0
float TEMPERATURA;	// valor de temperatura en grados centigrados

void setup(){
  Serial.begin(9600);	// inicializacion de comunicacion serie a 9600 bps
  // entradas analogicas no requieren inicializacion
}

void loop(){
  SENSOR = analogRead(A0);				// lectura de entrada analogica A0
  TEMPERATURA = ((SENSOR * 5000.0) / 1023) / 10;	// formula para convertir valor leido
							// en grados centigrados	
  Serial.println(TEMPERATURA, 1);			// imprime en monitor serial valor
							// de temperatura con un decimal
  delay(1000);						// demora de 1 seg. entre lecturas
}
