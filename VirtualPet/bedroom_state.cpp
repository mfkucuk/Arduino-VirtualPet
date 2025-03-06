#include "bedroom_state.h"

#include "assets.h"
#include "utils.h"
#include "particle.h"
#include "stats.h"
#include "game_state.h"
#include <CuteBuzzerSounds.h>

void BedroomState::setup() {
  currentAction = 0;
  actionCount = 2;
}

void BedroomState::update() {
  global.particleSystem->update();

  if (global.particleSystem->running) {
    if (millis() % 10 == 0) {
      global.stats->updateEnergy(1);
    }
  }
}

void BedroomState::render() {
  int x = (128 - actionCount * 16) / (actionCount + 1); // Start with initial spacing

  for (int i = 0; i < actionCount; i++) {
    if (i == currentAction) {
      if (i == 0) {
        drawInvertBitmapColor(x, 1, zzzBitmap, 16, 14, SSD1306_WHITE);
      } else {
        drawInvertBitmapColor(x, 1, hatBitmap, 16, 14, SSD1306_WHITE);
      }
    } else {
      if (i == 0) {
        global.display->drawBitmap(x, 1, zzzBitmap, 16, 14, SSD1306_WHITE);
      } else {
        global.display->drawBitmap(x, 1, hatBitmap, 16, 14, SSD1306_WHITE);
      }
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
    if (global.particleSystem->running) return;
    currentAction++;
    if (currentAction >= actionCount) {
      currentAction = 0;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    if (currentAction == 0) {
      if (global.particleSystem->running) {
        cute.play(S_JUMP);
        global.particleSystem->stop();
      } else {
        cute.play(S_SLEEPING);
        global.particleSystem->x = 13;
        global.particleSystem->y = 34;
        global.particleSystem->color = SSD1306_WHITE;
        global.particleSystem->gravity = -1;
        global.particleSystem->lifetime = 0.2f;
        global.particleSystem->play();
      }
    } else if (currentAction == 1) {
      global.gameState->hat = !global.gameState->hat;
      if (global.gameState->hat) {
        cute.play(S_SURPRISE);
      }
    }
  }
}