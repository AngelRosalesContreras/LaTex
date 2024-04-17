const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

const int N = 7;
const int SEGMENTOS[N] = {A,B,C,D,E,F,G};

/*CATODO COMUN*/
const int DIGITOS[10][N] = {
/*0*/ {1,1,1,1,1,1,0},
/*1*/ {0,1,1,0,0,0,0},
/*2*/ {1,1,0,1,1,0,1},
/*3*/ {1,1,1,1,0,0,1},
/*4*/ {0,1,1,0,0,1,1},
/*5*/ {1,0,1,1,0,1,1},
/*6*/ {1,0,1,1,1,1,1},
/*7*/ {1,1,1,0,0,0,0},
/*8*/ {1,1,1,1,1,1,1},
/*9*/ {1,1,1,1,0,1,1}
};
const int OFF = LOW;

void setup()
{
  for (int i=0; i<N; i++){
    pinMode(SEGMENTOS[i], OUTPUT);
    digitalWrite(SEGMENTOS[i], OFF);//apagar
  }
}

void print(int d){
  for (int i=0; i<N; i++){
    digitalWrite(SEGMENTOS[i], DIGITOS[d][i]);
  }
}

void loop()
{
  for(int i=0; i<10; i++){
    print(i);
    delay(1000);// esperar 1000 milisegundos
  }
}