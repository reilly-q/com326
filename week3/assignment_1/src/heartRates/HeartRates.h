#ifndef HEARTRATES_H
#define HEARTRATES_H

/*
 * HeartRates.h
 *
 * Version Information v1.1
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

    std::vector<int> dateOfBirth_;  /* (Day/Month/Year) */
    std::vector<int> currentDate_;  /* (Day/Month/Year) */

    int age_;
    int maxHeartRate_;
    int targetHeartRateLower_;
    int targetHeartRateHigher_;

public:

    // Constructors
    HeartRates();
    HeartRates(std::string, std::string, std::vector<int>&);
    HeartRates(std::string, std::string, std::vector<int>&, int, int, int, int);

    // Utility functions
    void CalculateDayMonthYear();
    void CorrectDateOfBirth(std::vector<int>&);
    void CalculateMaxHeartRate();
    void CalculateTargetHeartRate();

    // Setters - strings, vectors
    void SetFirstName(std::string);
    void SetLastName(std::string);

    void SetDateOfBirth(std::vector<int>);
    void SetCurrentDate(std::vector<int>);

    // Getters - strings, vectors
    std::string GetFirstName();
    std::string GetLastName();

    std::vector<int>& GetDateOfBirth();
    std::vector<int>& GetCurrentDate();

    // Straggler Getters - ints

    int GetMaxHeartRate();
    int GetTargetHeartRateLower();
    int GetTargetHeartRateHigher();
};

#endif
