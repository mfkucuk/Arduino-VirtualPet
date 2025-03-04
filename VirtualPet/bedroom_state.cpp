#include "bedroom_state.h"

#include "global.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void BedroomState::setup() {

}

void BedroomState::update() {

}

void BedroomState::render() {
  global.display->setTextSize(1);
  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(0, 10);

  global.display->println("Bedroom");
}

void BedroomState::input(int pin, bool pressed) {

}