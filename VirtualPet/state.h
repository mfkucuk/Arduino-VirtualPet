#pragma once

#include "HardwareSerial.h"
#include "Arduino.h"
#include "global.h"
#include "state_manager.h"

struct State {
  virtual void setup();
  virtual void update();
  virtual void render();
  virtual void input(int pin, bool pressed, bool longPressed);
};