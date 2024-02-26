#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "grid/grid.h"
#include "colors/colors.h"

#define LED_COUNT  256
#define LED_PIN    13
#define GAME_SPEED 50

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

Grid grid = Grid();

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  Serial.begin(9600);





  for(int i = 0; i < grid.grid.size(); i++) {
    for(int j = 0; j < grid.grid[i].size(); j++) {
      Serial.print("key: ");
      Serial.print(grid.grid[i][j].key);
      Serial.print(", color: ");
      Serial.println(grid.grid[i][j].color);
    }
  }

  // for(int i = 0; i < grid.grid.size(); i++) {
  //   Serial.print('[');
  //   for(int j = 0; j < grid.grid[i].size(); j++) {
  //     Serial.print(grid.grid[i][j].key);
  //     Serial.print(", ");
  //   }
  //   Serial.println(']');
  // }
}

void loop() {
  // put your main code here, to run repeatedly:


  while(false) {

    for(int row = grid.grid.size() - 1; row >= 0; row--) {
      uint32_t color = GetRandomColor();
      for(int column = 0; column < grid.grid[row].size(); column++) {
        strip.setPixelColor(grid.grid[row][column].key, color);
        strip.show();
        delay(GAME_SPEED);
      }
    }



    // for (int i = 0; i < strip.numPixels(); i++) {
    //   strip.setPixelColor(i, darkGrey);
    //   strip.show();
    //   delay(50);
    //   strip.setPixelColor(i, strip.Color(0, 0, 0));
    //   strip.show();
    // }

    // for (int i = 0; i < strip.numPixels(); i++) {
    //   strip.setPixelColor(i, purple);
    //   strip.show();
    //   delay(50);
    //   strip.setPixelColor(i, strip.Color(0, 0, 0));
    //   strip.show();
    // }
    
    // for (int i = 0; i < strip.numPixels(); i++) {
    //   strip.setPixelColor(i, darkBlue);
    //   strip.show();
    //   delay(50);
    //   strip.setPixelColor(i, strip.Color(0, 0, 0));
    //   strip.show();
    // }
  }
}
