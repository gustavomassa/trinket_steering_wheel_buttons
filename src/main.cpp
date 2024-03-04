#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"
#include <ProTrinketGamepad.h>
#include <stdio.h>

#define LED_PIN 1      // built in red LED
#define RESPONSE_DELAY_MS 5
#define BUTTON_DEBOUNCE_MS 20

SendOnlySoftwareSerial serialTx(1); // Tx pin

struct Button
{
  uint8_t index;
  uint8_t pin;
  uint8_t lastState = HIGH;     // last button reading
  boolean pressed = false;
  boolean changed = false;
  unsigned long debounceMs = 0; // last time the button was toggled

  Button(uint8_t index, uint8_t pin) : index(index), pin(pin) {}
  void init()
  {
    pinMode(pin, INPUT_PULLUP);
  }
  uint8_t read()
  {
    changed = false;

// get current state
    const uint8_t state = digitalRead(pin);
    
    // check if changed state
    if (state != lastState)
    {
      changed = true;

      if (lastState == HIGH && state == LOW)
      {
        pressed = true;

        // only apply debounce for pressed state
/*         if ((millis() - debounceMs) > BUTTON_DEBOUNCE_MS)
        {
        } */
      }
      else if (lastState == LOW && state == HIGH)
      {
        pressed = false;

        // reset debounce timer
        debounceMs = millis();
      }

      lastState = state;
    }

    return lastState;
  }
};

uint16_t buttonMap;
Button buttons[] = {
    Button(0, 3),
    Button(1, 4),
    Button(2, 5),
    Button(3, 6),
    //Button(4, 8),
    //Button(5, 9),
};

void blink()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}

void serialDebugButton(Button b)
{
  if (b.changed)
  {
    int length = snprintf(NULL, 0, "b(%d): %d, pressed: %d", b.index, b.lastState, b.pressed);
    char buffer[length + 1];
    snprintf(buffer, length + 1, "b(%d): %d, pressed: %d", b.index, b.lastState, b.pressed);
    serialTx.println(buffer);
  }
}

// the setup routine runs once when you press reset:
void setup()
{
  pinMode(LED_PIN, OUTPUT);

  for (uint8_t i = 0; i < sizeof(buttons); i++)
  {
    buttons[i].init();
  }

  TrinketGamepad.begin();

  serialTx.begin(9600);
  serialTx.println("Started");
}

// the loop routine runs over and over again forever:
void loop()
{

  // handle buttons
  for (uint8_t i = 0; i < sizeof(buttons) / sizeof(Button); i++)
  {
    uint8_t bState = buttons[i].read();
    bitWrite(buttonMap, i, !bState);

    serialDebugButton(buttons[i]);
  }

  TrinketGamepad.move(0, 0, 0, 0, buttonMap);

  // wait between gamepad readings
  delay(RESPONSE_DELAY_MS);
}
