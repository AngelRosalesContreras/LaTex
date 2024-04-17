#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN  2

float temperatura;
float humedad;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();

  if(isnan(humedad) || isnan(temperatura)){
    Serial.println("ERROR EN EL SENSOR");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" Humedad: ");
  Serial.println(humedad);
  delay(500);

}

