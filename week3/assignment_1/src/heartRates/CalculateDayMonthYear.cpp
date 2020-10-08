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

    year_ = 1900 + localTime->tm_year;
    month_ = 1 + localTime->tm_mon;
    day_ = localTime->tm_mday;

    std::cout << "The current date is (Day/Month/Year): " << day_ << "/" << month_ << "/" << year_ << std::endl;
}
