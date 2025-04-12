#include "Sensors.h"

/*
  Sensors.cpp - Implementation of the Sensors library for Teensy 4.1
  using the QuadEncoder hardware peripheral.
*/

// Default constructor — initializes encoder with dummy pins and sets holdValue to 0
Sensors::Sensors()
  : encoder(1, 0, 0, false), holdValue(0) {
  // Do not call init here because pins might not be real yet
}

// Properly initialize encoder with real pins and settings
void Sensors::beginEncoder(uint8_t channel, uint8_t pinA, uint8_t pinB, bool usePullups) {
  encoder = QuadEncoder(channel, pinA, pinB, usePullups);
  encoder.init();
  encoder.write(0);  // optional: start count from 0
}

// Return current encoder count
int32_t Sensors::readEncoder()
{
    uint32_t ret32;

    ret32 = channel[_encoder_ch].ENC->UPOS; /* Get upper 16 bits and make a snapshot. */
    ret32 <<= 16U;
    ret32 |= channel[_encoder_ch].ENC->LPOSH; /* Get lower 16 bits from hold register. */

    return (int32_t) ret32;
}


// Set encoder count to a specific value
void Sensors::writeEncoder(int32_t count) {
  encoder.write(count);
}

// Get held position
int32_t Sensors::getHoldPosition() {
  return encoder.getHoldPosition();
}

// Get difference from current position to held position
int16_t Sensors::getHoldDifference() {
  return encoder.getHoldDifference();
}
