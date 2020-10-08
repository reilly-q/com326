#ifndef HEARTRATES_H
#define HEARTRATES_H

/*
 * HeartRates.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../../inc/common.h"

class HeartRates {
private:

    // Declare variables - strings, vectors, ints, time_t
    std::string firstName_;
    std::string lastName_;

    std::vector<int> dateOfBirth_;  /* DD MM YYYY */

    int age_;
    int maxHeartRate_;
    int targetHeartRate1_;
    int targetHeartRate2_;
    int yearsSince1900_;
    int month_;
    int day_;

public:

    // Constructors
    HeartRates();
    HeartRates(std::string nm1, std::string nm2, std::vector<int>& dob);
    HeartRates(std::string, std::string, std::vector<int>&, int, int, int, int);

    // Utility functions
    void CalculateDayMonthYear();
    void CorrectDateOfBirth(std::vector<int>&);
    void CalculateMaxHeartRate();
    void CalculateTargetHeartRate();

    // Setters - strings, vectors
    void SetFirstName(std::string nm);
    void SetLastName(std::string nm);

    void SetDateOfBirth(std::vector<int>);

    // Getters - strings, vectors
    std::string GetFirstName();
    std::string GetLastName();

    std::vector<int>& GetDateOfBirth();
};

#endif
