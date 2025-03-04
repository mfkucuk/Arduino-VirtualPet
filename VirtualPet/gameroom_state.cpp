#include "gameroom_state.h"

#include "global.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void GameroomState::setup() {

}

void GameroomState::update() {

}

void GameroomState::render() {
  global.display->setTextSize(1);
  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(0, 10);

  global.display->println("Game room");
}

void GameroomState::input(int pin, bool pressed) {

}