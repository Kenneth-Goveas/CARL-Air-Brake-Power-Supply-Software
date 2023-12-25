/** @file Battery.h */

#ifndef __BATTERY_H__
#define __BATTERY_H__

#include <Arduino.h>

/** @brief  Battery voltage measurement.
 *
 *  This class provides an API for battery voltage measurement. The voltage is
 *  measured on an analog input connected to the battery through a resistive
 *  voltage divider. Measurements are carried out by sampling the analog input
 *  several times and taking the mean.
 *
 *  The following configuration parameters are necessary for initializing
 *  objects of this class.
 *  - `battery` `(uint8_t)`:        Analog input pin to sample.
 *  - `oversampling` `(uint16_t)`:  Number of samples in a measurement.
 *
 *  An object of this class must be initialized before use by calling
 *  Battery_t::begin(). This configures the above parameters for that object
 *  Subsequently, Battery_t::getReading() can be called to carry out a
 *  measurement as described above.
 */

class Battery_t {
    private:
        uint8_t battery;
        uint16_t oversampling;
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  battery         Analog input pin to sample.
         *  @param  oversampling    Number of samples in a measurement.
         */
        void begin (uint8_t battery, uint16_t oversampling);
        /** @brief  Measure voltage.
         *
         *  Measures the battery voltage as configured.
         *
         *  @return Analog reading corresponding to the measured voltage.
         */
        uint16_t getReading (void);
};

extern Battery_t Battery;   //!< Object to expose API.

#endif
