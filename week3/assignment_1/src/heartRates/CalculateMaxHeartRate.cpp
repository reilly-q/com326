/*
 * CalculateMaxHeartRate.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 08 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CalculateMaxHeartRate() {
    maxHeartRate_ = 220 - age_;
    std::cout << "Your max heart rate is: " << maxHeartRate_ << std::endl;
}
