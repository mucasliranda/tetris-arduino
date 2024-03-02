#pragma once
#include <Arduino.h>

class Keyboard {
    public:
    Keyboard(int leftPin, int rightPin, int rotatePin, int downPin);
    void begin();
    int readInput();
    
  private:
    int leftPin;
    int rightPin;
    int rotatePin;
    int downPin;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
};
