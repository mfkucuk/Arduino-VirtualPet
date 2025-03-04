#include "kitchen_state.h"

#include "assets.h"
#include "global.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void KitchenState::setup() {

}

void KitchenState::update() {

}

void KitchenState::render() {
  global.display->setTextSize(1);
  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(0, 10);

  global.display->println("Kitchen");

  global.display->drawBitmap(100, 10, kitchenShelfBitmap, 24, 14, SSD1306_WHITE);
  global.display->drawBitmap(111, 35, kitchenTableBitmap, 16, 26, SSD1306_WHITE);
}

void KitchenState::input(int pin, bool pressed) {

}