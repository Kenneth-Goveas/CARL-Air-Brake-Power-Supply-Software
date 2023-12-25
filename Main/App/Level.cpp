#include "Level.h"

Level_t Level;

void Level_t :: begin (
    uint8_t count, const uint16_t * threshold, uint8_t hysteresis
) {
    this->count = count;
    this->threshold = (uint16_t *)malloc((count + 2) * sizeof(uint16_t));
    this->hysteresis = hysteresis;
    this->level = 0;

    (this->threshold)[0] = 0;
    (this->threshold)[count + 1] = 1024;
    for (uint8_t i = 0; i < count; i++) {
        (this->threshold)[i + 1] = threshold[i];
    }
}

uint8_t Level_t :: getLevel (uint16_t reading) {
    for (uint8_t i = 1; i <= count; i++) {
        if (
               threshold[i] - hysteresis < reading
            && threshold[i] + hysteresis > reading
        ) {
            if (level < i) {
                level = i - 1;
            } else {
                level = i;
            }
            return level;
        }
    }

    for (uint8_t i = 0; i <= count; i++) {
        if (threshold[i] <= reading && reading <= threshold[i + 1]) {
            level = i;
            return level;
        }
    }

    return 0;
}
