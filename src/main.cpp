#include <Arduino.h>
#include "game/game.h"
#include "grid/grid.h"
#include "colors/colors.h"
#include "keyboard/keyboard.h"
#include "led.cpp"

// #define LED_COUNT  256
// #define LED_PIN    33
// #define GAME_SPEED 500

// #define LEFT    16
// #define RIGHT   17
// #define ROTATE  18
// #define DOWN    19

// Keyboard keyboard(LEFT, RIGHT, ROTATE, DOWN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  while(!Serial);

  // for(int i = 0; i < grid.grid.size(); i++) {
  //   for(int j = 0; j < grid.grid[i].size(); j++) {
  //     Serial.print("key: ");
  //     Serial.print(grid.grid[i][j].key);
  //     Serial.print(", color: ");
  //     Serial.println(grid.grid[i][j].color);
  //   }
  // }

  // for(int i = 0; i < grid.grid.size(); i++) {
  //   Serial.print('[');
  //   for(int j = 0; j < grid.grid[i].size(); j++) {
  //     Serial.print(grid.grid[i][j].key);
  //     Serial.print(", ");
  //   }
  //   Serial.println(']');
  // }
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

// while (gameNotOver) {
//   getKeyboardInput
//   changeScores
//   draw
//   wait(gameSpeed)
// }