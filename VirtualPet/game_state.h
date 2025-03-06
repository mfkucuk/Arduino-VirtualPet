#pragma once

#include "state.h"

#define RABBIT_WIDTH 16
#define RABBIT_HEIGHT 26

struct GameState : public State {

  int currentRoom = 0;
  State* rooms[3];

  bool statsOpen = false;
  bool hat = false;

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};