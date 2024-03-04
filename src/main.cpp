#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"
#include <ProTrinketGamepad.h>

#define LED_PIN 1      // built in red LED
#define PIN_BUTTON 3   // PD3
#define PIN_BUTTON_2 4 // PD4
#define RESPONSE_DELAY_MS 5

SendOnlySoftwareSerial serialTx(1); // Tx pin
boolean buttonPressed = false;      // whether or not mouse button pressed
int lastReading = 1;                // last button reading
unsigned long debounceTimeMs = 0;   // last time the button was toggled
unsigned long debounceMs = 50;      // debounce time, increase if the mouse clicks rapidly

uint16_t buttonMap;
const uint8_t BUTTON_PINS[] = {3, 4};

void blink()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}

// the setup routine runs once when you press reset:
void setup()
{
  pinMode(LED_PIN, OUTPUT);

  for (uint8_t i = 0; i < sizeof(BUTTON_PINS); i++)
  {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  TrinketGamepad.begin();

  serialTx.begin(9600);
  serialTx.println("Started");
}

// the loop routine runs over and over again forever:
void loop()
{
  for (uint8_t i = 0; i < sizeof(BUTTON_PINS); i++)
  {
    char b = digitalRead(BUTTON_PINS[i]);
    bitWrite(buttonMap, i, !b);

  if (b == LOW) {
    buttonPressed = true;
    blink();
  }

    /*     char b = digitalRead(BUTTON_PINS[i]);
        if (b != lastReading)
        {                            // switch changed
          debounceTimeMs = millis(); // reset debounce timer
        }

        if ((millis() - debounceTimeMs) > debounceMs)
        {
          if (b == LOW)
          {
            buttonPressed = true;

            lastReading = b;
            bitWrite(buttonMap, i, !b);

            blink();
            serialTx.println("button 0");
          }
        } */
  }

  TrinketGamepad.move(0, 0, 0, 0, buttonMap);

  // wait between gamepad readings
  delay(RESPONSE_DELAY_MS);
}
