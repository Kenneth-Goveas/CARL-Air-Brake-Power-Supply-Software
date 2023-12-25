/** @file Level.h */

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <Arduino.h>

/** @brief  Battery level classification.
 *
 *  This class provides an API for categorizing a battery voltage reading into
 *  one of several levels. For a classification into levels *L0* to *Ln*, a set
 *  of thresholds *V1* to *Vn* are necessary. If the voltage reading is between
 *  *Vi* and *V(i+1)*, then it is classified as level *Li*. If the reading is
 *  below *V1*, it is classified as level *L0*, and if it is above *Vn*, it is
 *  classified as *Ln*. Additionally, a hysteresis margin *H* is also applied to
 *  the thresholds *Vi*. If the reading is between *Vi-H* and *Vi+H*, then it is
 *  either classified as *L(i-1)* or *Li*, whichever is closer to the level into
 *  which the previous reading was classified. This prevents the level from
 *  rapidly fluctuating when the reading is near any of the thresholds.
 *
 *  The following configuration parameters are necessary for initializing
 *  objects of this class.
 *  - `count` `(uint8_t)`:          Number of thresholds.
 *  - `threshold` `(uint16_t *)`:   Threshold values.
 *  - `hysteresis` `(uint8_t)`:     Hysteresis margin.
 *
 *  An object of this class must be initialized before use by calling
 *  Level_t::begin(). This configures the above parameters for that object.
 *  Subsequently, Level_t::getLevel() can be called to categorize readings.
 */

class Level_t {
    private:
        uint8_t count;
        uint16_t * threshold;
        uint8_t hysteresis;
        uint8_t level;
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  count       Number of thresholds.
         *  @param  threshold   Threshold values.
         *  @param  hysteresis  Hysteresis margin.
         */
        void begin (
            uint8_t count, const uint16_t * threshold, uint8_t hysteresis
        );
        /** @brief  Categorize reading.
         *
         *  Categorizes a battery voltage reading into the appropriate level.
         *
         *  @param  reading Battery voltage reading.
         *
         *  @return Level corresponding to the reading.
         */
        uint8_t getLevel (uint16_t reading);
};

extern Level_t Level;   //!< Object to expose API.

#endif
