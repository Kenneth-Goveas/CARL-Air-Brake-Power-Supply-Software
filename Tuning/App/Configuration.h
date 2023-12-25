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

/// Console_t configuration parameter `baud`
const uint32_t CONSOLE_BAUD = 115200;

#endif
