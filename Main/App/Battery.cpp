#include "Battery.h"

Battery_t Battery;

void Battery_t :: begin (uint8_t battery, uint16_t oversampling) {
    this->battery = battery;
    this->oversampling = oversampling;

    pinMode(battery, INPUT);
}

uint16_t Battery_t :: getReading (void) {
    uint16_t reading = 0;
    uint32_t readingSum = 0;

    for (uint16_t i = 0; i < oversampling; i++) {
        readingSum += analogRead(battery);
    }
    reading = readingSum / oversampling;

    return reading;
}
