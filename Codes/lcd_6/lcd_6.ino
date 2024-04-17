#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  direccion  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD en una posicion  central.
  lcd.setCursor(10, 0);
  lcd.print("www.upiit.ipn.mx");
  lcd.setCursor(4, 1);
  lcd.print("Test de desplazamiento  ");
}

void loop() {
  //desplazamos una posicion a la izquierda
  lcd.scrollDisplayLeft(); 
  delay(500);
}
