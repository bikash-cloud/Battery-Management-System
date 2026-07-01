#include "config.h"
#include "adc_reader.h"
#include "battery_engine.h"

unsigned long measurementCount = 0;

void setup() {
  Serial.begin(115200);
}

void printBatteryBar(float soc) {
  int bars = soc / 10;

  Serial.print("[");
  for (int i = 0; i < 10; i++) {
    if (i < bars) Serial.print("#");
    else Serial.print("-");
  }

  Serial.print("] ");
  Serial.print(soc, 1);
  Serial.println(" %");
}

void printRuntime() {
  unsigned long totalSeconds = millis() / 1000;

  unsigned long hours = totalSeconds / 3600;
  unsigned long minutes = (totalSeconds % 3600) / 60;
  unsigned long seconds = totalSeconds % 60;

  Serial.print("Runtime           : ");

  if (hours < 10) Serial.print("0");
  Serial.print(hours);
  Serial.print(":");

  if (minutes < 10) Serial.print("0");
  Serial.print(minutes);
  Serial.print(":");

  if (seconds < 10) Serial.print("0");
  Serial.println(seconds);
}

void printActiveFaults(BatteryData battery) {
  bool faultFound = false;

  Serial.println("Active Faults:");

  for (int i = 0; i < CELL_COUNT; i++) {
    if (battery.cellStatus[i] == "UNDER VOLTAGE") {
      Serial.print("- Cell ");
      Serial.print(i + 1);
      Serial.println(" Under Voltage");
      faultFound = true;
    }

    if (battery.cellStatus[i] == "OVER VOLTAGE") {
      Serial.print("- Cell ");
      Serial.print(i + 1);
      Serial.println(" Over Voltage");
      faultFound = true;
    }
  }

  if (battery.imbalance >= CRITICAL_LIMIT) {
    Serial.println("- High Cell Imbalance");
    faultFound = true;
  }

  if (battery.status == "Pack Failure") {
    Serial.println("- Pack Failure Condition");
    faultFound = true;
  }

  if (!faultFound) {
    Serial.println("- No Active Faults");
  }
}

void printRecommendation(BatteryData battery) {
  Serial.println("Recommendation:");

  if (battery.status == "Healthy") {
    Serial.println("- Pack is healthy. No action required.");
  }
  else if (battery.status == "Minor Imbalance") {
    Serial.println("- Monitor the pack. Minor balancing may be required.");
  }
  else if (battery.status == "Critical Imbalance") {
    Serial.print("- Balance weak Cell ");
    Serial.println(battery.weakestCell);
    Serial.println("- Avoid heavy load until balancing is complete.");
  }
  else {
    Serial.println("- Pack failure risk detected.");
    Serial.print("- Inspect weakest Cell ");
    Serial.println(battery.weakestCell);
    Serial.println("- Stop operation and perform cell balancing.");
  }
}

void loop() {
  measurementCount++;

  float cells[CELL_COUNT];

  for (int i = 0; i < CELL_COUNT; i++) {
    cells[i] = readCellVoltage(CELL_PINS[i]);
  }

  BatteryData battery = analyzeBattery(cells);

  Serial.println("=================================================");
  Serial.println("        BATTERY INTELLIGENCE ENGINE");
  Serial.println("=================================================");

  Serial.print("Measurement No.   : ");
  Serial.println(measurementCount);

  printRuntime();

  Serial.println("-------------------------------------------------");

  for (int i = 0; i < CELL_COUNT; i++) {
    Serial.print("Cell ");
    Serial.print(i + 1);
    Serial.print(" : ");
    Serial.print(battery.cellVoltage[i], 2);
    Serial.print(" V  [");
    Serial.print(battery.cellStatus[i]);
    Serial.println("]");
  }

  Serial.println("-------------------------------------------------");

  Serial.print("Pack Voltage      : ");
  Serial.print(battery.packVoltage, 2);
  Serial.println(" V");

  Serial.print("Average Voltage   : ");
  Serial.print(battery.averageVoltage, 2);
  Serial.println(" V");

  Serial.print("Battery SOC       : ");
  Serial.print(battery.batterySOC, 1);
  Serial.println(" %");

  Serial.print("Battery Bar       : ");
  printBatteryBar(battery.batterySOC);

  Serial.print("Strongest Cell    : Cell ");
  Serial.println(battery.strongestCell);

  Serial.print("Weakest Cell      : Cell ");
  Serial.println(battery.weakestCell);

  Serial.print("Imbalance         : ");
  Serial.print(battery.imbalance, 2);
  Serial.println(" %");

  Serial.print("Battery Status    : ");
  Serial.println(battery.status);

  Serial.println("-------------------------------------------------");
  printActiveFaults(battery);

  Serial.println("-------------------------------------------------");
  printRecommendation(battery);

  Serial.println("=================================================");
  Serial.println();

  delay(1000);
}