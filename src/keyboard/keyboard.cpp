#include "keyboard.h"
#include <Arduino.h>

Keyboard::Keyboard() {
  this->lastDebounceTime = 0;
  this->debounceDelay = 50;
}

void Keyboard::begin(int leftPin, int rightPin, int rotatePin, int downPin) {
  // pinMode(this->leftPin, INPUT_PULLUP);
  // pinMode(this->rightPin, INPUT_PULLUP);
  // pinMode(this->rotatePin, INPUT_PULLUP);
  // pinMode(this->downPin, INPUT_PULLUP);

  Serial.println("keyboard begin");

  this->leftPin = leftPin;
  this->rightPin = rightPin;
  this->rotatePin = rotatePin;
  this->downPin = downPin;




  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(rotatePin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(leftPin), leftISR, FALLING);
  // attachInterrupt(digitalPinToInterrupt(rightPin), rightISR, FALLING);
  // attachInterrupt(digitalPinToInterrupt(rotatePin), rotateISR, FALLING);
  // attachInterrupt(digitalPinToInterrupt(downPin), downISR, FALLING);
}

// void Keyboard::leftISR() {
//   // Lógica para o botão esquerdo pressionado
  
//   Serial.println("left");
// }

// void Keyboard::rightISR() {
//   // Lógica para o botão direito pressionado
//   Serial.println("right");
// }

// void Keyboard::rotateISR() {
//   // Lógica para o botão de rotação pressionado
//   Serial.println("rotate");
// }

// void Keyboard::downISR() {
//   // Lógica para o botão para baixo pressionado
//   Serial.println("down");
// }

int Keyboard::readInput() {
  int leftState = digitalRead(this->leftPin);
  int rightState = digitalRead(this->rightPin);
  int rotateState = digitalRead(this->rotatePin);
  int downState = digitalRead(this->downPin);

  // if (millis() - lastDebounceTime > debounceDelay) {
    if (leftState == HIGH) {
      // lastDebounceTime = millis();
      return 1;
    }
    if (rightState == HIGH) {
      // lastDebounceTime = millis();
      return 2;
    }
    if (rotateState == HIGH) {
      // lastDebounceTime = millis();
      return 3;
    }
    if (downState == HIGH) {
      // lastDebounceTime = millis();
      return 4;
    }
  // }

  return 0;
}
