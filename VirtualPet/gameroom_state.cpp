#include "global.h"
#include "gameroom_state.h"

#include "assets.h"
#include "utils.h"
#include "state_manager.h"

void GameroomState::setup() {
  icons[0] = pongLogoBitmap;
  currentAction = 0;
  actionCount = 1;
}

void GameroomState::update() {

}

void GameroomState::render() {
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