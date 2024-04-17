#include <Stepper.h>

#define STEPS 4076

Stepper stepper(STEPS,2,3,4,5);


void setup() {
  stepper.setSpeed(100);
}

void loop() {
  stepper.step(4076);
  delay(1000);
  stepper.step(-4076);
  delay(1000);
}
