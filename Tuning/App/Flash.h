/** @file Flash.h */

#ifndef __FLASH_H__
#define __FLASH_H__

#include <Arduino.h>

/** @brief  Timed flashing.
 *
 *  This class provides an API to implement a flashing signal. This signal is
 *  entirely a software construct, and switches between *on* and *off* states at
 *  regular intervals.
 *
 *  The following configuration parameter is necessary for initializing objects
 *  of this class.
 *  - `interval` `(uint32_t)`:  Flashing interval in milliseconds.
 *
 *  An object of this class must be initialized before use by calling
 *  Flash_t::begin(). This configures the above parameter for that object.
 *  Subsequently, Flash_t::onState() and Flash_t::offState() can be called to
 *  check if the flashing signal is currently on or off respectively.
 */

class Flash_t {
    private:
        uint32_t interval;
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  interval    Flashing interval in milliseconds.
         */
        void begin (uint32_t interval);
        /** @brief  Check for on state.
         *
         *  Checks if the signal is currently on.
         *
         *  @retval true    Signal is on.
         *  @retval false   Signal is off.
         */
        bool onState (void);
        /** @brief  Check for off state.
         *
         *  Checks if the signal is currently off.
         *
         *  @retval true    Signal is off.
         *  @retval false   Signal is on.
         */
        bool offState (void);
};

extern Flash_t Flash;   //!< Object to expose API.

#endif
