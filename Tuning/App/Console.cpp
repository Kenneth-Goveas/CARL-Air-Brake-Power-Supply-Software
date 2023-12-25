#include "Console.h"

Console_t Console;

void Console_t :: begin (uint32_t baud) {
    Serial.begin(baud);
    while (!Serial);
}

void showReading (uint16_t reading) {
    Serial.print("Analog reading: ");
    Serial.println(reading);
}
