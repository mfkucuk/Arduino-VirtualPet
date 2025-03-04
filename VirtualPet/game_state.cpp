#include "game_state.h"

#include "HardwareSerial.h"
#include <CuteBuzzerSounds.h>

#include "global.h"
#include "assets.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void GameState::setup() {
  rooms[currentRoom]->setup();

  x = SCREEN_WIDTH / 2 - RABBIT_WIDTH / 2;
  y = SCREEN_HEIGHT / 2 - RABBIT_HEIGHT / 2;
}

void GameState::update() {
  rooms[currentRoom]->update();
}

void GameState::render() {
  rooms[currentRoom]->render();

  global.display->drawBitmap(x, y, rabbitBitmap, 16, 26, SSD1306_WHITE);
}

void GameState::input(int pin, bool pressed) {
  if (pin == LEFT_BUTTON_PIN && pressed) {
    currentRoom++;
    if (currentRoom > 2) {
      currentRoom = 0;
    }
  }

  rooms[currentRoom]->input(pin, pressed);
}