/** @file Configuration.h */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <Arduino.h>

/// Flash_t configuration parameter `interval`
const uint32_t FLASH_INTERVAL = 500;

/// Battery_t configuration parameter `input`
const uint8_t BATTERY_INPUT = A0;

/// Battery_t configuration parameter `oversampling`
const uint16_t BATTERY_OVERSAMPLING = 500;

/// Indicator_t configuration parameter `count`
const uint8_t INDICATOR_COUNT = 5;

/// Indicator_t configuration parameter `redLed`
const uint8_t INDICATOR_RED_LED [] = {2, 3, 4, 5, 6};

/// Indicator_t configuration parameter `greenLed`
const uint8_t INDICATOR_GREEN_LED [] = {A1, A2, A3, A4, A5};

/// Level_t configuration parameter `count`
const uint8_t LEVEL_COUNT = 5;

/// Level_t configuration parameter `threshold`
const uint16_t LEVEL_THRESHOLD [] = {600, 650, 700, 750, 800};

/// Level_t configuration parameter `hysteresis`
const uint8_t LEVEL_HYSTERESIS = 5;

#endif
