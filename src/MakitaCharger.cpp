#include <Arduino.h>
#include "MakitaCharger.h"

#define FETmakita 9   // PB1
#define LEDmakitacharger LED_BUILTIN  // 10
#define StartChargerVoltage 15
#define StopChargerVoltage 19.5
#define FILTER_CONST 0.98f

void MakitaChargerSetup() {
  pinMode(LEDmakitacharger, OUTPUT);
  digitalWrite(LEDmakitacharger, HIGH); // set to known state
  pinMode(FETmakita, OUTPUT); // Turn on charger FET
  digitalWrite(FETmakita, LOW); // set to known state
}

void MakitaChargerLoop() {
static uint32_t Readinterval = millis();
volatile static float voltage_A2;

  if (millis() - Readinterval >= 100) {
    voltage_A2 = analogRead(A2);
    voltage_A2 = voltage_A2 * (50 / 1023.0);
    Filteredvoltage_A2 = FILTER_CONST * Filteredvoltage_A2 + voltage_A2 * (1 - FILTER_CONST);
    Readinterval = millis();
  }
}
