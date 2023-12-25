#include "Flash.h"

Flash_t Flash;

void Flash_t :: begin (uint32_t interval) {
    this->interval = interval;
}

bool Flash_t :: onState (void) {
    if ((millis() / interval) % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool Flash_t :: offState (void) {
    if ((millis() / interval) % 2 == 0) {
        return false;
    } else {
        return true;
    }
}
