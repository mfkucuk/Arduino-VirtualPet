#pragma once

#include "state.h"

struct GameroomState : public State {

  const unsigned char* icons[1];
  int currentAction;
  int actionCount;

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};