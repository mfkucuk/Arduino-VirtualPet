#include "stats.h"

#include <Arduino.h>

void Stats::load() {
  if (EEPROM.read(FIRST_TIME_ADDRESS) == 255) {
    EEPROM.write(FIRST_TIME_ADDRESS, 0);

    age = 0;
    happiness = 50;
    energy = 50;
    hunger = 50;

    EEPROM.write(AGE_ADDRESS, age);
    EEPROM.write(HAPPINESS_ADDRESS, happiness);
    EEPROM.write(ENERGY_ADDRESS, energy);
    EEPROM.write(HUNGER_ADDRESS, hunger);
    return;
  }

  age = EEPROM.read(AGE_ADDRESS);
  happiness = EEPROM.read(HAPPINESS_ADDRESS);
  energy = EEPROM.read(ENERGY_ADDRESS);
  hunger = EEPROM.read(HUNGER_ADDRESS);

  randomSeed(analogRead(0));
  if (random(10) >= 7) {
    updateAge(1);
  }
}

void Stats::updateAge(const int& by) {
  age += by;

  if (age >= 255) {
    age = 255;
  }

  EEPROM.write(AGE_ADDRESS, age);
}

void Stats::updateHappiness(int by) {

  happiness += by;

  if (happiness >= 100) {
    happiness = 100;
  } else if (happiness <= 0) {
    happiness = 0;
  }
  EEPROM.write(HAPPINESS_ADDRESS, happiness);
}

void Stats::updateEnergy(int by) {
  energy += by;

  if (energy >= 100) {
    energy = 100;
  } else if (energy <= 0) {
    energy = 0;
  }
  EEPROM.write(ENERGY_ADDRESS, energy);
}

void Stats::updateHunger(int by) {
  hunger += by;

  if (hunger >= 100) {
    hunger = 100;
  } else if (hunger <= 0) {
    hunger = 0;
  }
  EEPROM.write(HUNGER_ADDRESS, hunger);
}