#include "bedroom_state.h"

#include "assets.h"
#include "utils.h"

void BedroomState::setup() {
  icons[0] = zzzBitmap;
  icons[1] = hatBitmap;
  currentAction = 0;
  actionCount = 2;
}

void BedroomState::update() {

}

void BedroomState::render() {
  int totalWidth = actionCount * 16;
  int spacing = (128 - totalWidth) / (actionCount + 1);

  int x = spacing; // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      drawInvertBitmapColor(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    } else {
      global.display->drawBitmap(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    }

    x += 16 + spacing; // Move to the next icon with spacing
  }
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