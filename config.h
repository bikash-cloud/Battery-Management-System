#ifndef CONFIG_H
#define CONFIG_H

#define CELL_COUNT 4

const int CELL_PINS[CELL_COUNT] = {33, 35, 34, 32};

const float ADC_MAX = 4095.0;
const float VREF = 3.3;

const float HEALTHY_LIMIT = 2.0;
const float MINOR_LIMIT = 5.0;
const float CRITICAL_LIMIT = 10.0;

const float CELL_UNDER_VOLTAGE = 1.0;
const float CELL_OVER_VOLTAGE = 2.8;

#endif