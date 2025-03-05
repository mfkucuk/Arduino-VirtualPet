#include "stats.h"

void Stats::load() {
  if (EEPROM.read(FIRST_TIME_ADDRESS) == 255) {
    EEPROM.write(FIRST_TIME_ADDRESS, 0);

    age = 0;
    money = 0;
    happiness = 50;
    energy = 50;
    hunger = 50;

    EEPROM.write(AGE_ADDRESS, age);
    EEPROM.write(MONEY_ADDRESS, money);
    EEPROM.write(HAPPINESS_ADDRESS, happiness);
    EEPROM.write(ENERGY_ADDRESS, energy);
    EEPROM.write(HUNGER_ADDRESS, hunger);
  }

  age = EEPROM.read(AGE_ADDRESS);
  money = EEPROM.read(MONEY_ADDRESS);
  happiness = EEPROM.read(HAPPINESS_ADDRESS);
  energy = EEPROM.read(ENERGY_ADDRESS);
  hunger = EEPROM.read(HUNGER_ADDRESS);
}

void Stats::updateAge(const int& by) {
  age += by;
  EEPROM.write(AGE_ADDRESS, age);
}

void Stats::updateMoney(int by) {
  money += by;
  EEPROM.write(MONEY_ADDRESS, money);
}

void Stats::updateHappiness(int by) {
  happiness += by;
  EEPROM.write(HAPPINESS_ADDRESS, by);
}

void Stats::updateEnergy(int by) {
  energy += by;
  EEPROM.write(ENERGY_ADDRESS, by);
}

void Stats::updateHunger(int by) {
  hunger += by;
  EEPROM.write(HUNGER_ADDRESS, by);
}