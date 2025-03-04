#pragma once

struct State;

struct StateManager {
  int currentState;
  State* states[2];
  
  void changeState(int state);
  void update();
  void render();
  void input(int pin, bool pressed);
};