#include <CuteBuzzerSounds.h>

#include "global.h"
#include "state_manager.h"

#include "menu_state.h"
#include "game_state.h"

#include "kitchen_state.h"
#include "bedroom_state.h"
#include "gameroom_state.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int buttonPins[2] = { LEFT_BUTTON_PIN, RIGHT_BUTTON_PIN };
int buttons[2];
bool buttonsHeld[2];

Global global;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  cute.init(BUZZER_PIN);

  StateManager stateManager;
  MenuState menu;
  GameState game;

  KitchenState kitchen;
  BedroomState bedroom;
  GameroomState gameroom;

  game.currentRoom = 0;
  game.rooms[KITCHEN_STATE] = &kitchen;
  game.rooms[BEDROOM_STATE] = &bedroom;
  game.rooms[GAMEROOM_STATE] = &gameroom;
  
  stateManager.currentState = 0;
  stateManager.states[MENU_STATE] = &menu;
  stateManager.states[GAME_STATE] = &game;

  global.stateManager = &stateManager;

  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
  global.display = &display;
  if (!global.display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (true);
  }

  global.stateManager->changeState(MENU_STATE);
}

void loop() {
  global.stateManager->update();

  global.display->clearDisplay();
  global.stateManager->render();
  global.display->display();

  for (int i = 0; i < 2; i++) {
    buttons[i] = digitalRead(buttonPins[i]);

    if (buttons[i] == LOW) {
      if (!buttonsHeld[i]) {
        buttonsHeld[i] = true;
        global.stateManager->input(buttonPins[i], true);
      } else {
        global.stateManager->input(buttonPins[i], false);
      }
    } else {
      buttonsHeld[i] = false;
    }
  }
}
