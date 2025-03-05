#pragma once

#include "state.h"

struct MenuState : public State {
  void setup() override;
  void update() override;
  void render() override;
  void input(int pin, bool pressed, bool longPressed) override;
};