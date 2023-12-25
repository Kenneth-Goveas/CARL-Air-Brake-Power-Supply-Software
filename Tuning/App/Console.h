/** @file Console.h */

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <Arduino.h>

/** @brief  Serial output console.
 *
 *  This class provides an API for printing battery voltage readings to the
 *  serial output console.
 *
 *  The following configuration parameter is necessary for initializing objects
 *  of this class.
 *  - `baud` `(uint32_t)`:  Serial output baud rate.
 *
 *  An object of this class must be initialized before use by calling
 *  Console_t::begin(). This configures the above parameter for that object.
 *  Subsequently, Console_t::showReading() can be called to print a battery
 *  voltage reading.
 */

class Console_t {
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  baud    Serial output baud rate.
         */
        void begin (uint32_t baud);
        /** @brief  Print reading.
         *
         *  Prints a battery voltage reading to the serial output console.
         *
         *  @param  reading Battery voltage reading.
         */
        void showReading (uint16_t reading);
};

extern Console_t Console;   //!< Object to expose API.

#endif
