#include <Arduino.h>
#include "game/game.h"
#include "grid/grid.h"
#include "colors/colors.h"
#include "keyboard/keyboard.h"
#include "led.cpp"

void setup() {
  Serial.begin(9600);
  
  while(!Serial);
}

int i = 0;

void loop() {
  Game game = Game();
  
  while(true) {
    game.handleInput();

    game.draw();

    delay(300);
  }
}