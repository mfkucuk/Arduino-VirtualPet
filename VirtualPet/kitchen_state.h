#pragma once

#include "state.h"

struct KitchenState : public State {

  int currentAction;
  int actionCount;

  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};