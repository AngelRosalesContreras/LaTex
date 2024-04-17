int led = 5;
int brillo;

void setup() {
  pinMode(led, OUTPUT);

}

void loop() {
  for(brillo = 0 ; brillo < 256; brillo++){
    analogWrite(led,brillo);
    delay(15);
  }

  for(brillo = 256; brillo >= 0; brillo--){
    analogWrite(led,brillo);
    delay(15);
  }

}
