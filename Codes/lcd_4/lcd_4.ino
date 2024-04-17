#include <LiquidCrystal.h>
//Crear el objeto LCD con los numeros correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte N[8] = {
B11111,
B10001,
B10001,
B10001,
B10001,
B10001,
B10001,
B00000,
};
byte A[8] = {
B11111,
B10001,
B10001,
B10001,
B10001,
B11111,
B10001,
B00000,
};
byte Y[8] = {
B10001,
B10001,
B10001,
B10001,
B11111,
B00100,
B00100,
B00000,
};
byte L[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B11111,
B00000,
};
byte M[8] = {
B11111,
B10101,
B10101,
B10101,
B10101,
B10101,
B10101,
B00000,
};
byte P[8] = {
B11111,
B10001,
B10001,
B10001,
B11111,
B10000,
B10000,
B00000,
};
byte cara[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000,
};
byte cuerpo[8] = {
B01110,
B01110,
B00100,
B11111,
B00100,
B01010,
B10001,
B00000,
};

void setup () {
  lcd.createChar (0,N);
  lcd.createChar (1,A);
  lcd.createChar (2,Y);
  lcd.createChar (3,L);
  lcd.createChar (4,M);
  lcd.createChar (5,P);
  lcd.createChar (6,cara);
  lcd.createChar (7,cuerpo);
  // Inicializar el LCD con el numero de  columnas y filas del LCD
  lcd.begin (20, 4); 
  
  // Escribimos el texto en el LCD
  lcd.print("Nuevos Caracteres");
  lcd.setCursor(0, 1);
  lcd.print("---");
  lcd.write (byte (5));
  lcd.write (byte (3));
  lcd.write (byte (1));
  lcd.write (byte (2));
  lcd.write (byte (1));
  lcd.write (' ');
  lcd.write (byte (4));
  lcd.write (byte (1));
  lcd.write (byte (3));
  lcd.print("---");
  
  lcd.setCursor(0, 2);
  for(int i=0;i<10;i++)
  {
    lcd.write (byte (6));
    lcd.write (' ');
  }
  lcd.setCursor(0, 3);
  for(int i=0;i<20;i++)
    lcd.write (byte (7));
  
}

void loop () {}
