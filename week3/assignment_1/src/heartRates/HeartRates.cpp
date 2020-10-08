/*
 * HeartRates.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 07 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

// Constructors
HeartRates::HeartRates() {
    // Init variables - strings, vectors, ints
    firstName_ = "default";
    lastName_ = "default";

    dateOfBirth_.push_back(00); /* (Day/Month/Year) */
    dateOfBirth_.push_back(00); /* (Day/Month/Year) */
    dateOfBirth_.push_back(0000); /* (Day/Month/Year) */

    age_ = 0;
    maxHeartRate_ = 0;
    targetHeartRateLower_ = 0;
    targetHeartRateHigher_ = 0;
    year_ = 0;
    month_ = 0;
    day_ = 0;

    //CalculateDayMonthYear();
}

HeartRates::HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob) {
    // Init variables - strings, vectors, ints
    firstName_ = nm1;
    lastName_ = nm2;

    dateOfBirth_.resize(3);  /* DD MM YYYY */

    age_ = 0;
    maxHeartRate_ = 0;
    targetHeartRateLower_ = 0;
    targetHeartRateHigher_ = 0;
    year_ = 0;
    month_ = 0;
    day_ = 0;

    CorrectDateOfBirth(dob);
    //CalculateDayMonthYear();
}

HeartRates::HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob, int age, int maxHR, int targetHR1, int targetHR2) {
    // Init variables - strings, vectors, ints
    firstName_ = nm1;
    lastName_ = nm2;

    dateOfBirth_.resize(3);  /* DD MM YYYY */

    age_ = age;
    maxHeartRate_ = maxHR;
    targetHeartRateLower_ = targetHR1;
    targetHeartRateHigher_ = targetHR2;
    year_ = 0;
    month_ = 0;
    day_ = 0;

    CorrectDateOfBirth(dob);
    //CalculateDayMonthYear();
}
