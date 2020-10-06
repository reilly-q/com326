/*
 * HeartRates.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
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
    targetHeartRate_ = 0;
}

HeartRates::HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob, int age, int maxHR, int targetHR) {
    // Init variables - strings, vectors, ints
    firstName_ = nm1;
    lastName_ = nm2;

    dateOfBirth_.reserve(3);  /* DD MM YYYY */
    CorrectDateOfBirth(dob);

    age_ = age;
    maxHeartRate_ = maxHR;
    targetHeartRate_ = targetHR;
}

// Utility functions
//void HeartRates::CorrectDateOfBirth(std::vector<int>&) {}
void HeartRates::CalculateAge() {}
void HeartRates::CalculateMaxHeartRate() {}
void HeartRates::CalculateTargetHeartRate() {}

// Setters - strings, vectors
void HeartRates::SetFirstname(std::string nm) {}
void HeartRates::SetLastName(std::string nm) {}

void HeartRates::SetDateofBirth(std::vector<int>) {}

// Getters - strings, vectors
std::string HeartRates::GetFirstname() {return "Hello";}
std::string HeartRates::GetLastName() {return "Hello";}

std::vector<int>& HeartRates::GetDateofBirth() {return dateOfBirth_;}
