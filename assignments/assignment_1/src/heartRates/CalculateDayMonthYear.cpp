/*
 * CalculateDayMonthYear.cpp
 *
 * Version Information v1.2
 * Author: Quinn Reilly
 * Date: 08 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CalculateDayMonthYear() {
    std::time_t tTime = std::time(nullptr);
    tm *localTime = localtime(&tTime);

    currentDate_[2] = 1900 + localTime->tm_year;
    currentDate_[1] = 1 + localTime->tm_mon;
    currentDate_[0] = localTime->tm_mday;

    std::cout << "The current date is (Day/Month/Year):\t" << currentDate_[0] << "/" << currentDate_[1] << "/" << currentDate_[2] << std::endl << std::endl;
}
