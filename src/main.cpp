#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"

const int ledPin = 1; // built in red LED
SendOnlySoftwareSerial ftdiTx (1);  // Tx pin

void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

// the setup routine runs once when you press reset:
void setup()
{
  pinMode(ledPin, OUTPUT);

  ftdiTx.begin(9600);

  blink();
}

// the loop routine runs over and over again forever:
void loop()
{
  blink();

  ftdiTx.println("blink");

  delay(100);
}
