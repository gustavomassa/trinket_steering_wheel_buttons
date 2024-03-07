#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>
#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"

#define BUTTON_DEBOUNCE_MS 30

class Button {
public:
    Button(uint8_t pin, boolean pullup = true, boolean debounce = false);
    boolean isPressed(const uint8_t state);   
    boolean isReleased(const uint8_t state);
    uint8_t read();
    void serialDebug(SendOnlySoftwareSerial serial);

private:
  boolean pullup = true;
  boolean debounce = false;
  boolean pressed = false;
  boolean changed = false;
  uint8_t pin;
  uint8_t lastState; // last button reading
  unsigned long debounceMs = 0; // last time the button was toggled

};

#endif // BUTTON_H