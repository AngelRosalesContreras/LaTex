byte pinesFilas[] = { 11, 10, 9, 8 };
byte pinesColumnas[] = { 7, 6, 5, 4 };

char teclas[4][4] = {{ '7','8','9', '%' },
                     { '4','5','6', 'X' },
                     { '1','2','3', '-' },
                     { 'ON','0','=', '+' }};


void setup()
{
  for (int nL = 0; nL <= 3; nL++) {
     pinMode(pinesFilas[nL], OUTPUT);
     digitalWrite(pinesFilas[nL], HIGH);
  }
  for (int nC = 0; nC <= 3; nC++) {
     pinMode(pinesColumnas[nC], INPUT_PULLUP);
  } 
   
  Serial.begin(9600);
  Serial.println("Teclado 4x4");
  Serial.println();
}
 
void loop()
{
    //Barrido por las filas
    for (int nL = 0; nL <= 3; nL++)
    {
      digitalWrite(pinesFilas[nL], LOW);
      
      //Barrido en columnas buscando un LOW
      for (int nC = 0; nC <= 3; nC++) {
        if (digitalRead(pinesColumnas[nC]) == LOW)
        {
          Serial.print("Tecla: ");
          Serial.println(teclas[nL][nC]);
          while(digitalRead(pinesColumnas[nC]) == LOW){}
        }
      }
      digitalWrite(pinesFilas[nL], HIGH);
    }
   delay(10);
}