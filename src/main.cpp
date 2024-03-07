#include <Arduino.h>
#include <stdio.h>

#include "SendOnlySoftwareSerial.h"
#include "ProTrinketGamepad.h"
#include "button.h"

#define LED_PIN 1 // built in red LED
#define RESPONSE_DELAY_MS 5

SendOnlySoftwareSerial serialTx(1); // Tx pin


uint16_t buttonMap;
Button buttons[] = {
    Button(3),
    Button(4),
    Button(5),
    Button(6),
    // Button(4, 8),
    // Button(5, 9),
};

void blink()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}

void enableSerialDebug()
{
  serialTx.begin(9600);
  serialTx.println("Started");
}

// the setup routine runs once when you press reset:
void setup()
{
  pinMode(LED_PIN, OUTPUT);

  TrinketGamepad.begin();

  // enableSerialDebug();
}

// the loop routine runs over and over again forever:
void loop()
{

  // handle buttons
  for (uint8_t i = 0; i < sizeof(buttons) / sizeof(Button); i++)
  {
    uint8_t bState = buttons[i].read();
    bitWrite(buttonMap, i, !bState);

    // serialDebugButton(buttons[i]);
  }

  TrinketGamepad.move(0, 0, 0, 0, buttonMap);

  // wait between gamepad readings
  delay(RESPONSE_DELAY_MS);
}
