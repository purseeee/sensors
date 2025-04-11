#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <QuadEncoder.h>

/*
  Sensors.h - A Teensy-compatible library for managing quadrature encoder data.
  This library wraps the QuadEncoder class and provides additional helper functions
  like hold, getHoldDifference, etc.
*/

class Sensors {
public:
    // Constructor: initializes encoder with dummy values. Must call beginEncoder() later.
    Sensors();

    // Set up the encoder hardware
    void beginEncoder(uint8_t channel, uint8_t pinA, uint8_t pinB, bool usePullups);

    // Read current encoder count
    int32_t readEncoder();

    // Write (reset) encoder count
    void writeEncoder(int32_t count);

    // Hold current encoder position
    void holdEncoder();

    // Get the held position
    int32_t getHoldPosition();

    // Get the difference between current position and hold position
    int32_t getHoldDifference();

private:
    QuadEncoder encoder;   // Encoder object from the library
    int32_t holdValue;     // Stores the held encoder value
};

#endif
