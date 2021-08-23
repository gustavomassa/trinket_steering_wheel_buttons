#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"

const int ledPin = 1; // built in red LED
SendOnlySoftwareSerial hc05Slave (0);  // Tx pin

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

  hc05Slave.begin(9600);

  blink();
}

// the loop routine runs over and over again forever:
void loop()
{
  blink();
  hc05Slave.println("tocson");
  delay(100);
}
