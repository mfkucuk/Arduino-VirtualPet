#include "gameroom_state.h"

#include "assets.h"
#include "utils.h"
#include "global.h"
#include "Adafruit_SSD1306.h"
#include "state_manager.h"
#include "particle.h"
#include "stats.h"
#include <CuteBuzzerSounds.h>

void GameroomState::setup() {
  currentAction = 0;
  actionCount = 2;
}

void GameroomState::update() {
  global.particleSystem->update();

  if (global.particleSystem->running) {
    if (millis() % 10 == 0) {
      global.stats->updateHappiness(1);
    }
  }
}

void GameroomState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      if (i == 0) {
        drawInvertBitmapColor(x, 1, gamepadBitmap, 16, 14, SSD1306_WHITE);
      } else {
        drawInvertBitmapColor(x, 1, pongLogoBitmap, 16, 14, SSD1306_WHITE);
      }
    } else {
      if (i == 0) {
        global.display->drawBitmap(x, 1, gamepadBitmap, 16, 14, SSD1306_WHITE);
      } else {
        global.display->drawBitmap(x, 1, pongLogoBitmap, 16, 14, SSD1306_WHITE);
      }
    }

    x += 16 + (128 - actionCount * 16) / (actionCount + 1); // Move to the next icon with spacing
  }

  global.display->drawBitmap(88, 18, televisionBitmap, 24, 18, SSD1306_WHITE);
  global.display->drawBitmap(84, 42, couchBitmap, 32, 16, SSD1306_WHITE);
  global.display->drawBitmap(16, 18, windowBitmap, 24, 16, SSD1306_WHITE);
  global.display->drawBitmap(16, 43, carpetBitmap, 24, 14, SSD1306_WHITE);
}

void GameroomState::input(int pin, bool pressed, bool longPressed) {
  if (pin == LEFT_BUTTON_PIN && pressed) {
    if (global.particleSystem->running) return;
    currentAction++;
    if (currentAction >= actionCount) {
      currentAction = 0;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    if (currentAction == 0) {
      if (global.particleSystem->running) {
        global.particleSystem->stop();
      } else {
        global.particleSystem->x = 100;
        global.particleSystem->y = 26;
        global.particleSystem->color = SSD1306_WHITE;
        global.particleSystem->gravity = 0;
        global.particleSystem->lifetime = 0.08f;
        global.particleSystem->play();
        cute.play(S_SUPER_HAPPY);
      }
    } else if (currentAction == 1) {
      global.stateManager->changeState(PONG_STATE);
    }
  }
}