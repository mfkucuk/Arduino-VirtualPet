#include "Arduino.h"
#include "game_state.h"

#include "HardwareSerial.h"
#include <CuteBuzzerSounds.h>

#include "global.h"
#include "assets.h"
#include "particle.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "stats.h"

void GameState::setup() {
  rooms[currentRoom]->setup();
}

void GameState::update() {
  rooms[currentRoom]->update();

  if (millis() % 500 == 0) {
    global.stats->updateHunger(-1);
  }

  if (millis() % 600 == 0) {
    global.stats->updateEnergy(-1);
  }

  if (millis() % 700 == 0) {
    global.stats->updateHappiness(-1);
  }
}

void GameState::render() {
  global.display->drawLine(0, 40, 128, 40, SSD1306_WHITE);
  global.display->drawRect(0, 0, 128, 16, SSD1306_WHITE);

  rooms[currentRoom]->render();
  
  if (!global.particleSystem->running || global.particleSystem->color == SSD1306_BLACK) {
    global.display->drawBitmap(SCREEN_WIDTH / 2 - RABBIT_WIDTH / 2, SCREEN_HEIGHT / 2 - RABBIT_HEIGHT / 2 + 10, rabbitBitmap, 16, 26, SSD1306_WHITE);

    if (hat) {
      global.display->drawBitmap(SCREEN_WIDTH / 2 - RABBIT_WIDTH / 2, SCREEN_HEIGHT / 2 - RABBIT_HEIGHT / 2 + 2, hatBitmap, 16, 14, SSD1306_WHITE);
    }
  } 

  global.particleSystem->render();

  if (statsOpen) {
    global.display->fillRect(4, 20, 120, 60, SSD1306_WHITE);

    global.display->setTextSize(1);
    global.display->setTextColor(SSD1306_BLACK);
    global.display->setCursor(6, 21);
    global.display->print(F("Name: "));
    global.display->print(F("Ribbit"));

    global.display->setCursor(6, 29);
    global.display->print(F("Age: "));
    global.display->print(global.stats->age);

    global.display->setCursor(6, 37);
    global.display->print(F("Happiness:"));
    global.display->drawRect(68, 38, 54, 6, SSD1306_BLACK);
    global.display->fillRect(68, 38, (global.stats->happiness / 100.0f) * 54.0f, 6, SSD1306_BLACK);

    global.display->setCursor(6, 45);
    global.display->print(F("Energy:"));
    global.display->drawRect(68, 46, 54, 6, SSD1306_BLACK);
    global.display->fillRect(68, 46, (global.stats->energy / 100.0f) * 54.0f, 6, SSD1306_BLACK);

    global.display->setCursor(6, 53);
    global.display->print(F("Hunger:"));
    global.display->drawRect(68, 54, 54, 6, SSD1306_BLACK);
    global.display->fillRect(68, 54, (global.stats->hunger / 100.0f) * 54.0f, 6, SSD1306_BLACK);
  }
}

void GameState::input(int pin, bool pressed, bool longPressed) {
  if (pin == MIDDLE_BUTTON_PIN && longPressed) {
    global.stateManager->changeState(MENU_STATE);
  }

  if (pin == LEFT_BUTTON_PIN && longPressed) {
    statsOpen = !statsOpen; 
  }

  if (statsOpen) return;
  
  rooms[currentRoom]->input(pin, pressed, longPressed);

  if (global.particleSystem->running) return;

  if (pin == RIGHT_BUTTON_PIN && pressed) {
    currentRoom++;
    if (currentRoom > 2) {
      currentRoom = 0;
    }
    rooms[currentRoom]->setup();
  }
}