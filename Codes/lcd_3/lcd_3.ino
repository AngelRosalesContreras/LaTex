#include <LiquidCrystal.h>

//Crear el objeto LCD con los numeros correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // Inicializar el LCD con el numero de  columnas y filas del LCD
  lcd.begin(16,2);
}

void loop() {
  int sen1=analogRead(A0);
  float sen2=analogRead(A1)*(5.0 / 1023.0);
  float sen3=analogRead(A2)*(100.0 / 1023.0);
  int tiempo=millis()/1000;
  // Cursor en la primera posicion de la primera fila
  lcd.setCursor(0,0);
  lcd.print("ADC:");
  lcd.print(sen1);
  lcd.print("   ");
  // Cursor en la 11 posicion de la primera fila
  lcd.setCursor(10,0);
  lcd.print("V:");
  lcd.print(sen2,1);//1 decimal
  lcd.print("V  ");
  // Cursor en la primera posicion de la 2 fila
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.print(sen3,1); //1 decimal
  lcd.print("337C  "); // "337" -> " "
  // Cursor en la 11 posicion de la 2 fila
  lcd.setCursor(10,1);
  lcd.print("t:");
  lcd.print(tiempo);
  lcd.print(" s  ");
  
  delay(200);
}