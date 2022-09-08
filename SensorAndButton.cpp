#include "Arduino.h"
#include "SensorAndButton.h"

SensorAndButton::SensorAndButton(){
    pinMode(BUTTON_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    _accumulator = 0;
}

void SensorAndButton::checkSensor(){
}

void SensorAndButton::checkButton(){
    boolean isToggled = false;
    for(int i = 0; i < TICK_COUNT; i++){
        isToggled |= digitalRead(BUTTON_PIN);
        if(isToggled){
            _accumulator = _accumulator == 0 ? MANUAL_CAPACITY : SHORT_DELAY;
            return;
        }
        delay(TICK);
    } 
}

void SensorAndButton::checkBoth(){
    checkSensor();
    checkButton();
    bool isLast = _accumulator == SHORT_DELAY;
    if(_accumulator > 0) _accumulator -= SHORT_DELAY;
    digitalWrite(RELAY_PIN, _accumulator > 0);
    delay(isLast ? LONG_DELAY : SHORT_DELAY);
}
