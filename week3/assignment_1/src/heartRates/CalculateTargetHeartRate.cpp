/*
 * CalculateTargetHeartRate.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 08 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CalculateTargetHeartRate() {
    // Calculate low end of target then high end and print.
    //std::cout << "The lower end of your target heart rate is: " << (targetHeartRateLower_ = maxHeartRate_ * 0.5) << std::endl;
    //std::cout << "The Higher end of your target heart rate is: " << (targetHeartRateHigher_ = maxHeartRate_ * 0.85) << std::endl;

    // Calculate low end of target then high end
    targetHeartRateLower_ = maxHeartRate_ * 0.5;
    targetHeartRateHigher_ = maxHeartRate_ * 0.85;
}
