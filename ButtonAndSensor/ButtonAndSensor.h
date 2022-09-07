#ifndef ButtonAndSensor_h
#define ButtonAndSensor_h

#include "Arduino.h"

class ButtonAndSensor {

    public:
        void ButtonAndSensor();
        void checkButton();
        void checkSensor();
        void loop();
        void setup();

    private:
        int _accumulator;
        bool _isToggled;
};

#endif
