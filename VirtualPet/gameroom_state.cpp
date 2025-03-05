#include "gameroom_state.h"

#include "assets.h"
#include "utils.h"
#include "global.h"
#include "Adafruit_SSD1306.h"
#include "state_manager.h"

void GameroomState::setup() {
  icons[0] = pongLogoBitmap;
  currentAction = 0;
  actionCount = 1;
}

void GameroomState::update() {

}

void GameroomState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      drawInvertBitmapColor(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    } else {
      global.display->drawBitmap(x, 1, icons[i], 16, 14, SSD1306_WHITE);
    }

    x += 16 + (128 - actionCount * 16) / (actionCount + 1); // Move to the next icon with spacing
  }

  global.display->drawBitmap(88, 18, televisionBitmap, 24, 18, SSD1306_WHITE);
  global.display->drawBitmap(84, 42, couchBitmap, 32, 16, SSD1306_WHITE);
  global.display->drawBitmap(16, 18, windowBitmap, 24, 16, SSD1306_WHITE);
}

void GameroomState::input(int pin, bool pressed, bool longPressed) {
  if (pin == LEFT_BUTTON_PIN && pressed) {
    currentAction++;
    if (currentAction >= actionCount) {
      currentAction = 0;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    global.stateManager->changeState(currentAction + 2);
  }
}