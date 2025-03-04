#include "menu_state.h"

#include "Arduino.h"
#include "HardwareSerial.h"
#include "global.h"
#include "state_manager.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void MenuState::setup() {
  Serial.println("Menu state");
}

void MenuState::update() {}

void MenuState::render() {}

void MenuState::input(int pin, bool pressed) {
  if (pin == LEFT_BUTTON_PIN && pressed) {

    delay(100);

    global.stateManager->changeState(GAME_STATE);
  }
}