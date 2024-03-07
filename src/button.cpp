#include "button.h"

Button::Button(uint8_t pin, boolean pullup = true, boolean debounce = false)
{
    //this->index = index;
    this->pin = pin;
    this->pullup = pullup;
    this->debounce = debounce;

    if (this->pullup)
    {
      pinMode(pin, INPUT_PULLUP);
      this->lastState = HIGH;
    }
    else
    {
      pinMode(pin, INPUT);
      this->lastState = LOW;
    }

    if (this->debounce)
    {
        // reset debounce timer
        this->debounceMs = millis();
    }
}

boolean Button::isPressed(const uint8_t state)
{
    if (this->pullup)
    {
        return (this->lastState == HIGH && state == LOW);
    }
    else
    {
        return (this->lastState == LOW && state == HIGH);
    }

    return false;
}

boolean Button::isReleased(const uint8_t state)
{
    if (this->pullup)
    {
        return (this->lastState == LOW && state == HIGH);
    }
    else
    {
        return (this->lastState == HIGH && state == LOW);
    }

    return false;
}

uint8_t Button::read()
{
    // check debounce before changing state
    if (this->debounce)    {
        if ((millis() - this->debounceMs) < BUTTON_DEBOUNCE_MS)
        {
            return this->lastState;
        }

        // reset debounce timer
        this->debounceMs = millis();
    }

    // get current state
    this->changed = false;
    const uint8_t state = digitalRead(pin);

    // check if changed state
    if (state != this->lastState)
    {
        this->changed = true;

        if (this->isPressed(state))
        {
            this->pressed = true;
        }
        else if (this->isReleased(state))
        {
            this->pressed = false;
        }

        // update last state
        this->lastState = state;
    }

    return this->lastState;
}

void Button::serialDebug(SendOnlySoftwareSerial serial)
{
  if (this->changed)
  {
    int length = snprintf(NULL, 0, "b: %d, pressed: %d", this->lastState, this->pressed);
    char buffer[length + 1];
    snprintf(buffer, length + 1, "b: %d, pressed: %d", this->lastState, this->pressed);
    serial.println(buffer);
  }
}
