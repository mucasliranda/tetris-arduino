#include <FastLED.h>
#include <Arduino.h>
#include <math.h>
#ifndef LED_H
#define LED_H

#define LED_PIN 33

class Led {
  public:
    void begin(int numRows, int numCols) {
      Serial.println("begin led");

      pinMode(LED_PIN, OUTPUT);

      this->numRows = numRows;
      this->numCols = numCols;

      this->leds = new CRGB[numRows * numCols];
      FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, numRows * numCols);
      FastLED.setBrightness(8);
    };
    void setPixel(int index, CRGB color) {
      // Agora preciso inverter a ordem das colunas no caso de linhas ímpares
      if (fmod((floor(index / numCols)), 2) == 0) { // Se a linha for par, ordem crescente
        index = index;
      } else { // Se a linha for ímpar, ordem decrescente
        index = ((floor(index / numCols)) + 1) * numCols - (index % numCols) - 1;
      }

      leds[index] = color;
    };
    void show() {
      FastLED.show();
    };
  private:
    CRGB *leds;
    int numRows;
    int numCols;
    int inversos[9] = {0, 8, 7, 6, 5, 4, 3, 2, 1};
};

#endif