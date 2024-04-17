#include <LiquidCrystal.h>

//Crear el objeto LCD con los numeros correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // Inicializar el LCD con el numero de  columnas y filas del LCD
  lcd.begin(16, 2);
  // Escribimos el Mensaje en el LCD en una posicion  central.
  lcd.setCursor(10, 0);
  lcd.print("www.upiit.ipn.mx");
  lcd.setCursor(5, 1);
  lcd.print("Tutorial LCD, Test de desplazamiento  ");
}

void loop() {
  //desplazamos una posicion a la izquierda
  lcd.scrollDisplayLeft(); 
  delay(250);
}