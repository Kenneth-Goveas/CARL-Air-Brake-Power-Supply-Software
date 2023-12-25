/** @mainpage
 *
 *  This is the main app for flashing on the power supply module of the CARL Air
 *  Brake computer. The source code documentation is aimed at developers
 *  interested in contributing to or modifying the software.
 */

#include "Configuration.h"
#include "Flash.h"
#include "Battery.h"
#include "Indicator.h"
#include "Level.h"

void setup (void) {
    Flash.begin(FLASH_INTERVAL);
    Battery.begin(BATTERY_INPUT, BATTERY_OVERSAMPLING);
    Indicator.begin(INDICATOR_COUNT, INDICATOR_RED_LED, INDICATOR_GREEN_LED);
    Level.begin(LEVEL_COUNT, LEVEL_THRESHOLD, LEVEL_HYSTERESIS);
}

void loop (void) {
    uint8_t level;
    color_t color[INDICATOR_COUNT];

    level = Level.getLevel(Battery.getReading());

    if (Flash.offState() && level == 0) {
        for (uint8_t i = 0; i < INDICATOR_COUNT; i++) {
            color[i] = COLOR_BLACK;
        }
    } else {
        for (uint8_t i = 0; i < INDICATOR_COUNT; i++) {
            if (i < level) {
                color[i] = COLOR_GREEN;
            } else {
                color[i] = COLOR_RED;
            }
        }
    }

    Indicator.setColors(color);
}
