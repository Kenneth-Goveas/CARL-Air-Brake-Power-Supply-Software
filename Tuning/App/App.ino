/** @mainpage
 *
 *  This is the tuning app for flashing on the power supply module of the CARL
 *  Air Brake computer. The source code documentation is aimed at developers
 *  interested in contributing to or modifying the software.
 */

#include "Configuration.h"
#include "Flash.h"
#include "Battery.h"
#include "Indicator.h"
#include "Console.h"

void setup (void) {
    Flash.begin(FLASH_INTERVAL);
    Battery.begin(BATTERY_INPUT, BATTERY_OVERSAMPLING);
    Indicator.begin(INDICATOR_COUNT, INDICATOR_RED_LED, INDICATOR_GREEN_LED);
    Console.begin(CONSOLE_BAUD);
}

void loop (void) {
    color_t color[INDICATOR_COUNT];

    Console.showReading(Battery.getReading());

    if (Flash.onState()) {
        for (uint8_t i = 0; i < INDICATOR_COUNT; i++) {
            if (i % 2 == 0) {
                color[i] = COLOR_RED;
            } else {
                color[i] = COLOR_GREEN;
            }
        }
    }

    if (Flash.offState()) {
        for (uint8_t i = 0; i < INDICATOR_COUNT; i++) {
            if (i % 2 == 0) {
                color[i] = COLOR_GREEN;
            } else {
                color[i] = COLOR_RED;
            }
        }
    }

    Indicator.setColors(color);
}
