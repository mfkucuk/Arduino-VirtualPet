#pragma once

#include "state.h"

struct PongState : public State {

  struct Ball {
    int x, y;
    int vx, vy;
    int radius;
  };

  struct Paddle {
    int x, y, w, h;
  };

  Ball ball { 64, 32, 2, 2, 2 };
  Paddle paddle1 { 5, 24, 5, 16 };
  Paddle paddle2 { 118, 24, 5, 16 };
  int playerScore;
  int computerScore;
  bool roundStarted;

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};