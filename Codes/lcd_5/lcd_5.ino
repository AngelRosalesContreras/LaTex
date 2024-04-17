#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  direccion  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("Hola Mundo");
}

void loop() {
   // Ubicamos el cursor en la primera posicion(columna:0) de la segunda linea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el numero de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}

