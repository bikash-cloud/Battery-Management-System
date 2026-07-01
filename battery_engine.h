#ifndef BATTERY_ENGINE_H
#define BATTERY_ENGINE_H

#include <Arduino.h>
#include "config.h"

struct BatteryData {
  float cellVoltage[CELL_COUNT];
  String cellStatus[CELL_COUNT];

  float packVoltage;
  float averageVoltage;
  float strongestVoltage;
  float weakestVoltage;

  int strongestCell;
  int weakestCell;

  float imbalance;
  float batterySOC;

  String status;
};

BatteryData analyzeBattery(float cellVoltage[]);

#endif