/** @file Indicator.h */

#ifndef __INDICATOR_H__
#define __INDICATOR_H__

#include <Arduino.h>

/** @brief  Indication LED color.
 *
 *  This enumeration represents possible colors of the indication LEDs. The
 *  indication LEDs are dual colored. Each is composed of one red and one green
 *  constituent LED.
 */

typedef enum {
    COLOR_BLACK,    //!< Both red and green components off.
    COLOR_RED,      //!< Red component on, green component off.
    COLOR_GREEN,    //!< Red component off, green component on.
    COLOR_YELLOW    //!< Both red and green components on.
} color_t;

/** @brief  Indication LED control.
 *
 *  This class provides an API for indication LED control. The indication LEDs
 *  are an array of dual colored (red and green) LEDs. Each LED is driven by two
 *  active high digital outputs, one for each color.
 *
 *  The following configuration parameters are necessary for initializing
 *  objects of this class.
 *  - `count` `(uint8_t)`:      Number of LEDs in the array.
 *  - `redLed` `(uint8_t *)`:   Digital output pins connected to the red
 *                              terminals of the LEDs.
 *  - `greenLed` `(uint8_t *)`: Digital output pins connected to the green
 *                              terminals of the LEDs.
 *
 *  An object of this class must be initialized before use by calling
 *  Indicator_t::begin(). This configures the above parameters for that object.
 *  Subsequently, Indicator_t::setColors() can be called to drive the LEDs,
 *  lighting them up in the desired colors.
 */

class Indicator_t {
    private:
        uint8_t count;
        uint8_t * redLed;
        uint8_t * greenLed;
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  count       Number of LEDs in the array.
         *  @param  redLed      Digital output pins connected to the red
         *                      terminals of the LEDs.
         *  @param  greenLed    Digital output pins connected to the green
         *                      terminals of the LEDs.
         */
        void begin (
            uint8_t count, const uint8_t * redLed, const uint8_t * greenLed
        );
        /** @brief  Drive LEDs.
         *
         *  Drives the LEDs and sets the desired colors.
         *
         *  @param  color   Desired colors of the LEDs.
         */
        void setColors (const color_t * color);
};

extern Indicator_t Indicator;   //!< Object to expose API.

#endif
