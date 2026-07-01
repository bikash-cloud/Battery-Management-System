#include "battery_engine.h"

BatteryData analyzeBattery(float cellVoltage[]) {
  BatteryData data;

  data.packVoltage = 0;

  for (int i = 0; i < CELL_COUNT; i++) {
    data.cellVoltage[i] = cellVoltage[i];
    data.packVoltage += cellVoltage[i];

    if (data.cellVoltage[i] < CELL_UNDER_VOLTAGE) {
      data.cellStatus[i] = "UNDER VOLTAGE";
    }
    else if (data.cellVoltage[i] > CELL_OVER_VOLTAGE) {
      data.cellStatus[i] = "OVER VOLTAGE";
    }
    else {
      data.cellStatus[i] = "NORMAL";
    }
  }

  data.averageVoltage = data.packVoltage / CELL_COUNT;

  data.batterySOC = (data.averageVoltage / VREF) * 100.0;

  if (data.batterySOC > 100.0) {
    data.batterySOC = 100.0;
  }

  if (data.batterySOC < 0.0) {
    data.batterySOC = 0.0;
  }

  data.strongestVoltage = data.cellVoltage[0];
  data.weakestVoltage = data.cellVoltage[0];
  data.strongestCell = 1;
  data.weakestCell = 1;

  for (int i = 1; i < CELL_COUNT; i++) {
    if (data.cellVoltage[i] > data.strongestVoltage) {
      data.strongestVoltage = data.cellVoltage[i];
      data.strongestCell = i + 1;
    }

    if (data.cellVoltage[i] < data.weakestVoltage) {
      data.weakestVoltage = data.cellVoltage[i];
      data.weakestCell = i + 1;
    }
  }

  data.imbalance =
    ((data.strongestVoltage - data.weakestVoltage) / data.averageVoltage) * 100.0;

  if (data.imbalance < HEALTHY_LIMIT) {
    data.status = "Healthy";
  }
  else if (data.imbalance < MINOR_LIMIT) {
    data.status = "Minor Imbalance";
  }
  else if (data.imbalance < CRITICAL_LIMIT) {
    data.status = "Critical Imbalance";
  }
  else {
    data.status = "Pack Failure";
  }

  return data;
}