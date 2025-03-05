#include "bedroom_state.h"

#include "assets.h"
#include "utils.h"
#include "Adafruit_SSD1306.h"
#include "global.h"

void BedroomState::setup() {
  icons[0] = zzzBitmap;
  icons[1] = hatBitmap;
  currentAction = 0;
  actionCount = 2;
}

void BedroomState::update() {

}

void BedroomState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      drawInvertBitmapColor(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    } else {
      global.display->drawBitmap(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    }

    x += 16 + (128 - actionCount * 16) / (actionCount + 1); // Move to the next icon with spacing
  }

  global.display->drawBitmap(8, 32, bedBitmap, 24, 14, SSD1306_WHITE);
  global.display->drawBitmap(76, 18, clockBitmap, 16, 16, SSD1306_WHITE);
  global.display->drawBitmap(100, 23, wardrobeBitmap, 16, 24, SSD1306_WHITE);
  global.display->drawBitmap(36, 24, nightstandBitmap, 16, 22, SSD1306_WHITE);
}

void BedroomState::input(int pin, bool pressed, bool longPressed) {
  if (pin == LEFT_BUTTON_PIN && pressed) {
    currentAction++;
    if (currentAction >= actionCount) {
      currentAction = 0;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    if (currentAction == 0) {
      
    }
  }
}