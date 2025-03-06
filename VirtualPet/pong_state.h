#pragma once

#include "state.h"

struct PongState : public State {

  struct Ball {
    int x, y;
    int vy, vx;
  };

  struct Paddle {
    int x, y;
  };

  Ball ball { 64, 32, 3, 3 };
  Paddle paddle1 { 5, 24 };
  Paddle paddle2 { 118, 24 };
  int playerScore;
  int computerScore;
  bool roundStarted;

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};