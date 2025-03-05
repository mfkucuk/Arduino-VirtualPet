#include "state_manager.h"
#include "state.h"

void StateManager::changeState(int state) {
  currentState = state;
  states[currentState]->setup();
}

void StateManager::update() {
  states[currentState]->update();
}

void StateManager::render() {
  states[currentState]->render();
}

void StateManager::input(int pin, bool pressed, bool longPressed) {
  states[currentState]->input(pin, pressed, longPressed);
}