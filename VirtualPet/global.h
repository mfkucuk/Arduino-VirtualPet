#pragma once
#include <avr/pgmspace.h>

// pins
#define BUZZER_PIN 5
#define LEFT_BUTTON_PIN 6
#define RIGHT_BUTTON_PIN 7
#define MIDDLE_BUTTON_PIN 8

// game states
#define MENU_STATE 0
#define GAME_STATE 1

// rooms in game state
#define KITCHEN_STATE 0
#define BEDROOM_STATE 1 
#define GAMEROOM_STATE 2

// games
#define PONG_STATE 2

// oled
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

struct StateManager;
struct Adafruit_SSD1306;
struct Stats;

struct Global {
  StateManager* stateManager;
  Adafruit_SSD1306* display;
  Stats* stats;
};

extern Global global;