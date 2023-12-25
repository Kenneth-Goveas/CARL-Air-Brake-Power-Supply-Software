#include "Indicator.h"

Indicator_t Indicator;

void Indicator_t :: begin (
    uint8_t count, const uint8_t * redLed, const uint8_t * greenLed
) {
    this->count = count;
    this->redLed = (uint8_t *)malloc(count * sizeof(uint8_t));
    this->greenLed = (uint8_t *)malloc(count * sizeof(uint8_t));

    for (uint8_t i = 0; i < count; i++) {
        (this->redLed)[i] = redLed[i];
        (this->greenLed)[i] = greenLed[i];
    }

    for (uint8_t i = 0; i < count; i++) {
        pinMode(redLed[i], OUTPUT);
        pinMode(greenLed[i], OUTPUT);
    }
}

void Indicator_t :: setColors (const color_t * color) {
    for (uint8_t i = 0; i < count; i++) {
        switch (color[i]) {
            case COLOR_BLACK:
                digitalWrite(redLed[i], LOW);
                digitalWrite(greenLed[i], LOW);
                break;
            case COLOR_RED:
                digitalWrite(redLed[i], HIGH);
                digitalWrite(greenLed[i], LOW);
                break;
            case COLOR_GREEN:
                digitalWrite(redLed[i], LOW);
                digitalWrite(greenLed[i], HIGH);
                break;
            case COLOR_YELLOW:
                digitalWrite(redLed[i], HIGH);
                digitalWrite(greenLed[i], HIGH);
                break;
        }
    }
}
