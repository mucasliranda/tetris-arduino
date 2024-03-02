#include "Keyboard.h"

Keyboard::Keyboard(int leftPin, int rightPin, int rotatePin, int downPin) {
  this->leftPin = leftPin;
  this->rightPin = rightPin;
  this->rotatePin = rotatePin;
  this->downPin = downPin;
  this->lastDebounceTime = 0;
  this->debounceDelay = 50;
}

void Keyboard::begin() {
  pinMode(this->leftPin, INPUT_PULLUP);
  pinMode(this->rightPin, INPUT_PULLUP);
  pinMode(this->rotatePin, INPUT_PULLUP);
  pinMode(this->downPin, INPUT_PULLUP);
}

int Keyboard::readInput() {
  int leftState = digitalRead(this->leftPin);
  int rightState = digitalRead(this->rightPin);
  int rotateState = digitalRead(this->rotatePin);
  int downState = digitalRead(this->downPin);

  if (millis() - lastDebounceTime > debounceDelay) {
    if (leftState == HIGH) {
      lastDebounceTime = millis();
      return 1;
    }
    if (rightState == HIGH) {
      lastDebounceTime = millis();
      return 2;
    }
    if (rotateState == HIGH) {
      lastDebounceTime = millis();
      return 3;
    }
    if (downState == HIGH) {
      lastDebounceTime = millis();
      return 4;
    }
  }

  return 0;
}
