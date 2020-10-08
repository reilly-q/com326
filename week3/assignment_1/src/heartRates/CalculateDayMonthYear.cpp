/*
 * CalculateDayMonthYear.cpp
 *
 * Version Information v1.1
 * Author: Quinn Reilly
 * Date: 08 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CalculateDayMonthYear() {
    std::time_t ttime = std::time(nullptr);
    tm *local_time = localtime(&ttime);

    yearsSince1900_ = tm.tm_year;
    month_          = tm.tm_mon + 1;
    day_            = tm.tm_mday + 1;
}
