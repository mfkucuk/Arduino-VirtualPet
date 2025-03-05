#include "kitchen_state.h"

#include "assets.h"
#include "utils.h"

void KitchenState::setup() {
  icons[0] = cookieBitmap;
  currentAction = 0;
  actionCount = 1;
}

void KitchenState::update() {

}

void KitchenState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      drawInvertBitmapColor(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    } else {
      global.display->drawBitmap(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    }

    x += 16 + (128 - actionCount * 16) / (actionCount + 1); // Move to the next icon with spacing
  }

  global.display->drawBitmap(100, 18, kitchenShelfBitmap, 24, 14, SSD1306_WHITE);
  global.display->drawBitmap(111, 35, kitchenTableBitmap, 16, 26, SSD1306_WHITE);
  global.display->drawBitmap(10, 20, kitchenFurnaceBitmap, 16, 33, SSD1306_WHITE);
}

void KitchenState::input(int pin, bool pressed, bool longPressed) {
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