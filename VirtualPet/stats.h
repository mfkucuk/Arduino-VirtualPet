#pragma once

#include <EEPROM.h>

#define FIRST_TIME_ADDRESS 10

#define AGE_ADDRESS 0
#define HAPPINESS_ADDRESS 2
#define ENERGY_ADDRESS 3
#define HUNGER_ADDRESS 4

struct Stats {

  int age;
  int happiness;
  int energy;
  int hunger;

  void load();
  void updateAge(const int& by);
  void updateHappiness(int by);
  void updateEnergy(int by);
  void updateHunger(int by);
};