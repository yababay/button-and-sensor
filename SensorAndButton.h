#ifndef SensorAndButton_h

#define SensorAndButton_h
#define BUTTON_PIN 0
#define RELAY_PIN 1
#define LONG_DELAY 5000
#define TICK 10
#define TICK_COUNT 25
#define SHORT_DELAY TICK * TICK_COUNT
#define MANUAL_FACTOR 3600
#define ONE_SECOND SHORT_DELAY * 4
#define MANUAL_CAPACITY MANUAL_FACTOR * ONE_SECOND

#include "Arduino.h"

class SensorAndButton {

    public:
        SensorAndButton();
        void checkButton();
        void checkSensor();
        void checkBoth();

    private:
        uint32_t _accumulator;
};

#endif
