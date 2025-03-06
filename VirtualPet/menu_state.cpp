#include "menu_state.h"

#include "Arduino.h"
#include "HardwareSerial.h"
#include "global.h"
#include "state_manager.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void MenuState::setup() {
}

void MenuState::update() {}

void MenuState::render() {
  global.display->setTextSize(1);
  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(45, 30);

  global.display->println(F("RIBBIT"));

  global.display->setCursor(15, 55);
  global.display->println(F("[Press to START]"));

  global.display->setCursor(22, 6);
  global.display->println(F("Made by Feyyaz"));
}

void MenuState::input(int pin, bool pressed, bool longPressed) {
  if (pressed) {

    delay(100);

    global.stateManager->changeState(GAME_STATE);
  }
}