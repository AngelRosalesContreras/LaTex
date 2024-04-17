//Display 7 Segmentos Anodo Comun
int display7a[10]= {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
//Delcaracion de Los Pines del Display
byte a=2;
byte b=3;
byte c=4;
byte d=5;
byte e=6;
byte f=7;
byte g=8;
// Declaracion de los Pines de los Transistores
byte t1=9;
byte t2=10;
byte t3=11;
byte t4=12;
//Contadores para hacer el Temporizador
long tempor=0,contret=0;
//Funcion que coloca en el puerto de salida los bits comenzando
// desde el pin ini hasta el pin fin
void puerto(int bits,int ini,int fin){
  for(int i=ini;i<=fin;i++)
  {
    digitalWrite(i,bitRead(bits,i-ini));
  }
}
//Funcion encargada de la multiplexacion
void mostrar( ) //Rutina mostrar
{
   int dig[4];   //Declarar las variables
                 //como un entero, es decir de 8bits
   //Digito Millar
   dig[0]=tempor/1000;
   //Digito Centena
   dig[1]=(tempor-dig[0]*1000)/100;
   //Digito Decena
   dig[2]=(tempor-dig[0]*1000-dig[1]*100)/10;
   //Digito Unidad
   dig[3]=(tempor-dig[0]*1000-dig[1]*100-dig[2]*10);
   //Rutina de Multiplexacion
   for(int i=t1;i<=t4;i++){ 
     //Muestra unidades
     puerto(display7a[dig[i-t1]],a,g); 
     digitalWrite(i,LOW);  //Enciende el display de unidades
     delay(1);               //Retardo de 1 milisegundos
     digitalWrite(i,HIGH);   //Apaga el display de unidades
   }                      
}
//Funcion que cuenta el tiempo que le toma al temporizador
//incrementar su cuenta
void temporizacion() 
{
   contret=50;       //Cargue con 50 la variable CONTRET
   while (contret>0) //Mientras que la variable CONTRET sea mayor que cero
   {
      mostrar();        //Llamar la rutina MOSTRAR
      contret--;        // Decremente la variable CONTRET
   }
}
//Configura todos los pines como Salidas
void setup() {
  //Configura los 8 Pines digitales como SALIDAS
  for(int i=a;i<=t4;i++){
    pinMode(i,OUTPUT);
  }
}
//Programa Principal
void loop() {
   tempor=0;  //Inicializa el temporizador en Cero
      while(tempor<9999) //mientras la variable TEMPOR es menor que 9999
      {
         temporizacion(); //Llama la Funcion Temporizaor
         tempor++;        //Incrementa el tempor 
      }
}