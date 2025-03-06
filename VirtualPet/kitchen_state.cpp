#include "kitchen_state.h"

#include "assets.h"
#include "particle.h"
#include "utils.h"
#include "stats.h"
#include <CuteBuzzerSounds.h>

void KitchenState::setup() {
  currentAction = 0;
  actionCount = 1;
}

void KitchenState::update() {
  global.particleSystem->update();

  if (global.particleSystem->running) {
    if (millis() % 10 == 0) {
      global.stats->updateHunger(-1);
    }
  }
}

void KitchenState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  drawInvertBitmapColor(x, 1, cookieBitmap, 16, 14, SSD1306_WHITE);

  global.display->drawBitmap(100, 18, kitchenShelfBitmap, 24, 14, SSD1306_WHITE);
  global.display->drawBitmap(111, 35, kitchenTableBitmap, 16, 26, SSD1306_WHITE);
  global.display->drawBitmap(10, 22, kitchenFurnaceBitmap, 16, 33, SSD1306_WHITE);
  global.display->drawBitmap(34, 18, doorBitmap, 16, 22, SSD1306_WHITE);
}

void KitchenState::input(int pin, bool pressed, bool longPressed) {
  if (pin == MIDDLE_BUTTON_PIN && pressed) {
    if (currentAction == 0) {
      if (global.particleSystem->running) {
        global.particleSystem->stop();
      } else {
        global.particleSystem->x = 62;
        global.particleSystem->y = 37;
        global.particleSystem->color = SSD1306_BLACK;
        global.particleSystem->gravity = 1;
        global.particleSystem->lifetime = 0.1f;
        global.particleSystem->play();
        cute.play(S_HAPPY_SHORT);
      }
    }
  }
}