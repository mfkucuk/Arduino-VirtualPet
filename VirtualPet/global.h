#pragma once

// pins
#define BUZZER_PIN 5
#define LEFT_BUTTON_PIN 6
#define RIGHT_BUTTON_PIN 7
#define MIDDLE_BUTTON_PIN 8

// game states
#define GAME_STATE 0

// rooms in game state
#define KITCHEN_STATE 0
#define BEDROOM_STATE 1 
#define GAMEROOM_STATE 2

// games
#define PONG_STATE 1

// oled
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

struct StateManager;
struct Adafruit_SSD1306;
struct Stats;
struct ParticleSystem;
struct GameState;

struct Global {
  StateManager* stateManager;
  Adafruit_SSD1306* display;
  Stats* stats;
  ParticleSystem* particleSystem;
  GameState* gameState;
};

extern Global global;