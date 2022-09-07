#include "Arduino.h"
#include "ButtonAndSensor.h"

#define BUTTON_PIN 0
#define RELAY_PIN 1
#define ACCUMULATOR_CAPACITY 100
#define MANUALLY_FACTOR 36
#define LARGE_BUTTON_DELAY 5000
#define SHORT_BUTTON_DELAY 300
#define TICK_DELAY 30
#define ONE_SECOND 1000


ButtonAndSensor::ButtonAndSensor(){
}

ButtonAndSensor::checkSensor(){
    delay(TICK_DELAY)
}

ButtonAndSensor::checkButton(){
    bool isRead = digitalRead(BUTTON);
    if(isRead){
        delay(TICK_DELAY);
        return;
    }
    _isToggled = !_isToggled;
    _accumulator = _isToggled ? BS_ACCUMULATOR_CAPACITY * MANUALLY_FACTOR : 0;     
    digitalWrite(RELAY_PIN, isToggled);
    delay(_isToggled ? SHORT_BUTTON_DELAY : LARGE_BUTTON_DELAY);
}

ButtonAndSensor::setup(){
    pinMode(BUTTON_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
}

ButtonAndSensor::loop(){
    checkSensor();
    checkButton();
    delay(ONE_SECOND);
    if(_accumulator > 0) _accumulator--;
    if(_accumulator == 0) digitalWrite(RELAY_PIN, LOW);
}
