/*
 * CorrectDateOfBirth.cpp
 *
 * Version Information v1.3
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CorrectDateOfBirth(std::vector<int>& dob) {
    // Init variables - bools, vectors.
    bool dateVerified = 0;

    std::vector<int> tmp; tmp.reserve(3);

    // Prepare time for validation.
    CalculateDayMonthYear();

    // Insert dob into tmp.
    if(dob.size() > 3) {        /* Cut down to size. */
        for(int i = 0; i < tmp.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth provided was larger than DD/MM/YYYY and\n"
            "has been successfully cut to correct size.";
    } else if(dob.size() < 3) { /* Insert into larger format. */
        for(int i = 0; i < tmp.size(); i++) {
            if(dob.size() >= i) {
                tmp[i] = dob[i];
            } else {
                tmp[i] = 0;
            }
        }

        std::cout << "Date of birth provided was smaller than DD/MM/YYYY and\n"
            "has been successfully cut to correct size.";
    } else {
        tmp = dob;              /* insert into equal size format */

        std::cout << "Date of birth provided was equal to DD/MM/YYYY and\n"
            "has been successfully cut to correct size.";
    }

    std::cout << std::endl;

    // Verify year, month then day.
    if(tmp[2] > 1900 && tmp[2] < 1900 + yearsSince1900_) {
        dateOfBirth_[2] = tmp[2];
        if(tmp[1] > 0 && tmp[1] < 13) {
            dateOfBirth_[1] = tmp[1];
            if((tmp[0] > 0 && tmp[0] < 29) && (tmp[1] == 2)) {          /* Check days for February. */

                dateOfBirth_[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 30) && (tmp[1] == 2) &&   /* Check days for February on a leap year. */
                tmp[2] % 4 == 0) {

                dateOfBirth_[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 31) && (tmp[1] == 4 ||    /* Check days for months with 30 days. */
                tmp[1] == 6 || tmp[1] == 9 || tmp[1] == 11)) {

                dateOfBirth_[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 32) && (tmp[1] == 1 ||    /* Check days for months with 31 days. */
                tmp[1] == 3 || tmp[1] == 5 || tmp[1] == 7 ||
                tmp[1] == 8 || tmp[1] == 10 || tmp[1] == 11)) {

                dateOfBirth_[0] = tmp[0];
                dateVerified = 1;

            } else {
                std::cout << "The day is not valid.";
            }
        } else {
            std::cout << "The month is not valid.";
        }
    } else {
        std::cout << "The year is not valid.";
    }

    std::cout << std::endl;

    // Inform user of validation results.
    if(dateVerified == 1) {
        //Check if the users birthday has passed.
        if((dateOfBirth_[1] > month_) || (dateOfBirth_[1] == month_ && dateOfBirth_[0] > day_)) {
            age_ = ((1900 + yearsSince1900_) - dateOfBirth_[2]) - 1;
        } else{
            age_ = ((1900 + yearsSince1900_) - dateOfBirth_[2]);
        }
        std::cout << "The date has been successfully validated and age is set. ";
        std::cout << "You are " << age_ << " years old.";
    } else {
        std::cout << "The date has been not been successfully validated and is not set.";
    }

    std::cout << std::endl;
}
