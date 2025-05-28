#include <AccelStepper.h>

#define pinBotaoEsquerdo 4
#define pinBotaoDireito 12

#define motorPin1 6
#define motorPin2 7
#define motorPin3 8
#define motorPin4 9

AccelStepper stepper(AccelStepper::FULL4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  pinMode(pinBotaoEsquerdo, INPUT_PULLUP);
  pinMode(pinBotaoDireito, INPUT_PULLUP);

  stepper.setMaxSpeed(1200);   // até 1500 pode funcionar, teste gradualmente
  stepper.setSpeed(0);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pinBotaoEsquerdo) == LOW) {
    stepper.setSpeed(-1000);   // gira rápido para esquerda
    Serial.println("Esquerda");
  } else if (digitalRead(pinBotaoDireito) == LOW) {
    stepper.setSpeed(1000);    // gira rápido para direita
    Serial.println("Direita");
  } else {
    stepper.setSpeed(0);       // para
  }

  stepper.runSpeed();
}
