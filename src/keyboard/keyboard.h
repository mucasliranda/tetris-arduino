#pragma once
#include <Arduino.h>

class Keyboard {
  public:
    Keyboard();
    void begin(int leftPin, int rightPin, int rotatePin, int downPin);
    int readInput();
    
  private:
    int leftPin;
    int rightPin;
    int rotatePin;
    int downPin;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
};
