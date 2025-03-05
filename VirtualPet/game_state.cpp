#include "game_state.h"

#include "HardwareSerial.h"
#include <CuteBuzzerSounds.h>

#include "global.h"
#include "assets.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void GameState::setup() {
  rooms[currentRoom]->setup();
}

void GameState::update() {
  rooms[currentRoom]->update();
}

void GameState::render() {
  global.display->drawRect(0, 0, 128, 16, SSD1306_WHITE);

  rooms[currentRoom]->render();

  global.display->drawBitmap(SCREEN_WIDTH / 2 - RABBIT_WIDTH / 2, SCREEN_HEIGHT / 2 - RABBIT_HEIGHT / 2 + 10, rabbitBitmap, 16, 26, SSD1306_WHITE);
}

void GameState::input(int pin, bool pressed, bool longPressed) {
  if (pin == RIGHT_BUTTON_PIN && pressed) {
    currentRoom++;
    if (currentRoom > 2) {
      currentRoom = 0;
    }
    rooms[currentRoom]->setup();
  }

  rooms[currentRoom]->input(pin, pressed, longPressed);
}