#include <CuteBuzzerSounds.h>

#include "global.h"
#include "state_manager.h"

#include "menu_state.h"
#include "game_state.h"

#include "kitchen_state.h"
#include "bedroom_state.h"
#include "gameroom_state.h"

#include "pong_state.h"

#include "particle.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "stats.h"

#define HOLD_THRESHOLD 500

int buttonPins[3] = { LEFT_BUTTON_PIN, RIGHT_BUTTON_PIN, MIDDLE_BUTTON_PIN };
int buttons[3];
bool buttonsPressed[3];
bool buttonsHeld[3];
unsigned long pressStartTimes[3];

Global global;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(MIDDLE_BUTTON_PIN, INPUT_PULLUP);
  cute.init(BUZZER_PIN);

  StateManager stateManager;
  MenuState menu;
  GameState game;

  global.gameState = &game;

  KitchenState kitchen;
  BedroomState bedroom;
  GameroomState gameroom;

  PongState pong;

  game.currentRoom = 0;
  game.rooms[KITCHEN_STATE] = &kitchen;
  game.rooms[BEDROOM_STATE] = &bedroom;
  game.rooms[GAMEROOM_STATE] = &gameroom;
  
  stateManager.currentState = 0;
  stateManager.states[MENU_STATE] = &menu;
  stateManager.states[GAME_STATE] = &game;
  stateManager.states[PONG_STATE] = &pong;

  global.stateManager = &stateManager;
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  global.display = &display;
  if (!global.display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  Stats stats;
  global.stats = &stats;
  global.stats->load();

  ParticleSystem particleSystem;
  global.particleSystem = &particleSystem;

  global.stateManager->changeState(MENU_STATE);

}

void loop() {
  global.stateManager->update();

  global.display->clearDisplay();
  global.stateManager->render();
  global.display->display();

  for (int i = 0; i < 3; i++) {
    buttons[i] = digitalRead(buttonPins[i]);

    if (buttons[i] == LOW) {
      global.stateManager->input(buttonPins[i], false, false);

      if (!buttonsPressed[i]) {
        buttonsPressed[i] = true;
        pressStartTimes[i] = millis();
      }

      if (!buttonsHeld[i] && millis() - pressStartTimes[i] >= HOLD_THRESHOLD) {
        buttonsHeld[i] = true;
      }
    } else {
      if (buttonsHeld[i]) {
        global.stateManager->input(buttonPins[i], false, true);
      } else if (buttonsPressed[i]) {
        global.stateManager->input(buttonPins[i], true, false);
      }

      buttonsPressed[i] = false;
      buttonsHeld[i] = false;
    }
  }
}
