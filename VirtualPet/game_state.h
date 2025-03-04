#pragma once

#include "state.h"

#define RABBIT_WIDTH 16
#define RABBIT_HEIGHT 26

struct GameState : public State {

  int x, y;

  int currentRoom;
  State* rooms[3];

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed) override;
};