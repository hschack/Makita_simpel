#include <Arduino.h>
#include "MakitaCharger.h"

uint32_t currentMillis;
float Filteredvoltage_A2 = 0.0f;
uint8_t ChargeBattery = 0;
uint8_t MAKITApin3status = 0;
uint32_t Printinterval = millis();

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  delay(100);
  MakitaChargerSetup();
}

void loop() {
  MakitaChargerLoop();
    if (millis() - Printinterval >= 1000) {
    Serial.println(Filteredvoltage_A2, 4);
    Printinterval = millis();
  }
}