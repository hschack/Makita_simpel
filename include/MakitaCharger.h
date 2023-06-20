#ifndef MAKITACHARGER_H
#define MAKITACHARGER_H

#include <Arduino.h>

extern uint32_t currentMillis;
extern float Filteredvoltage_A2;
extern uint8_t ChargeBattery;
extern uint8_t MAKITApin3status;
extern uint32_t Printinterval;

void MakitaChargerSetup();
void MakitaChargerLoop();

#endif // MAKITACHARGER_H
