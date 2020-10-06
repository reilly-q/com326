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

    // Declare variables - strings, vectors, ints
    std::string firstName_;
    std::string lastName_;

    std::vector<int> dateOfBirth_;  /* DD MM YYYY */

    int age_;
    int maxHeartRate_;
    int targetHeartRate_;

public:

    // Constructors
    HeartRates();
    HeartRates(std::string, std::string, std::vector<int>&, int, int, int);

    // Utility functions
    void CorrectDateOfBirth(std::vector<int>&);
    void CalculateAge();
    void CalculateMaxHeartRate();
    void CalculateTargetHeartRate();

    // Setters - strings, vectors
    void SetFirstname(std::string nm);
    void SetLastName(std::string nm);

    void SetDateofBirth(std::vector<int>);

    // Getters - strings, vectors
    std::string GetFirstname();
    std::string GetLastName();

    std::vector<int>& GetDateofBirth();
};

#endif
