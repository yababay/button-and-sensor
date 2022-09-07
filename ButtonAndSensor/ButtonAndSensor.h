#ifndef ButtonAndSensor_h
#define ButtonAndSensor_h

#include "Arduino.h"

class ButtonAndSensor {

    public:
        ButtonAndSensor();
        void checkButton();
        void checkSensor();
        void checkBoth();

    private:
        uint32_t _accumulator;
};

#endif
