#include "Arduino.h"
#include "ButtonAndSensor.h"

#define BUTTON_PIN 0
#define RELAY_PIN 1
#define LONG_DELAY 5000
#define SHORT_DELAY 250
#define MANUAL_FACTOR 10 // 3600
#define ONE_SECOND SHORT_DELAY * 4
#define MANUAL_CAPACITY MANUAL_FACTOR * ONE_SECOND


ButtonAndSensor::ButtonAndSensor(){
    pinMode(BUTTON_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    _accumulator = 0;
}

void ButtonAndSensor::checkSensor(){
}

void ButtonAndSensor::checkButton(){
    if(!digitalRead(BUTTON_PIN)) return;
    _accumulator = _accumulator == 0 ? MANUAL_CAPACITY : SHORT_DELAY;
}

void ButtonAndSensor::checkBoth(){
    checkSensor();
    checkButton();
    bool isLast = _accumulator == SHORT_DELAY;
    if(_accumulator > 0) _accumulator -= SHORT_DELAY;
    digitalWrite(RELAY_PIN, _accumulator > 0);
    delay(isLast ? LONG_DELAY : SHORT_DELAY);
}

