#include <Arduino.h>
#include "config.h"
#include "adc_reader.h"

float readCellVoltage(int pin) {
  int adcValue = analogRead(pin);
  float voltage = (adcValue / ADC_MAX) * VREF;
  return voltage;
}