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

    dateOfBirth_.push_back(00); /* DD MM YYYY */
    dateOfBirth_.push_back(00); /* DD MM YYYY */
    dateOfBirth_.push_back(0000); /* DD MM YYYY */

    age_ = 0;
    maxHeartRate_ = 0;
    targetHeartRate1_ = 0;
    targetHeartRate2_ = 0;
    yearsSince1900_ = 0;
    month_ = 0;
    day_ = 0;

    //CalculateDayMonthYear();
}

HeartRates::HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob) {
    // Init variables - strings, vectors, ints
    firstName_ = nm1;
    lastName_ = nm2;

    dateOfBirth_.reserve(3);  /* DD MM YYYY */

    age_ = 0;
    maxHeartRate_ = 0;
    targetHeartRate1_ = 0;
    targetHeartRate2_ = 0;
    yearsSince1900_ = 0;
    month_ = 0;
    day_ = 0;

    CorrectDateOfBirth(dob);
    //CalculateDayMonthYear();
}

HeartRates::HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob, int age, int maxHR, int targetHR1, int targetHR2) {
    // Init variables - strings, vectors, ints
    firstName_ = nm1;
    lastName_ = nm2;

    dateOfBirth_.reserve(3);  /* DD MM YYYY */

    age_ = age;
    maxHeartRate_ = maxHR;
    targetHeartRate1_ = targetHR1;
    targetHeartRate2_ = targetHR2;
    yearsSince1900_ = 0;
    month_ = 0;
    day_ = 0;

    CorrectDateOfBirth(dob);
    //CalculateDayMonthYear();
}
