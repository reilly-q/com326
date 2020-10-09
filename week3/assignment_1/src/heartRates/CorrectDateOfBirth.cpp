/*
 * CorrectDateOfBirth.cpp
 *
 * Version Information v1.5
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

    std::vector<int> tmp; tmp.resize(3);

    // Prepare time for validation.
    CalculateDayMonthYear();

    // Insert dob into tmp.
    if(dob.size() > 3) {        /* Cut down to size. */
        for(int i = 0; i < tmp.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth provided was larger than\n(Day/Month/Year) and "
            "has been\nsuccessfully cut to correct size.";
    } else if(dob.size() < 3) { /* Insert into larger format. */
        for(int i = 0; i < dob.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth provided was smaller than\n(Day/Month/Year) and "
            "has been\nsuccessfully inserted to correct size.";
    } else {                    /* insert into equal size format */
        tmp = dob;

        std::cout << "Date of birth provided was equal to\n(Day/Month/Year) and "
            "has been\nsuccessfully inserted.";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Verify year, month then day.
    if(tmp[2] >= 1900 && tmp[2] <= currentDate_[2] - 2) {
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
                tmp[1] == 8 || tmp[1] == 10 || tmp[1] == 12)) {

                dateOfBirth_[0] = tmp[0];
                dateVerified = 1;

            } else {
                std::cout << "The day is not valid.";
                std::cout << std::endl << std::endl;
                exit(-1);
            }
        } else {
            std::cout << "The month is not valid.";
            std::cout << std::endl << std::endl;
            exit(-1);
        }
    } else {
        std::cout << "The year is not valid.";
        std::cout << std::endl << std::endl;
        exit(-1);
    }

    // Inform user of validation results.
    if(dateVerified == 1) {
        //Check if the users birthday has passed.
        if((dateOfBirth_[1] > currentDate_[1]) || (dateOfBirth_[1] == currentDate_[1] && dateOfBirth_[0] > currentDate_[0])) {
            age_ = (currentDate_[2] - dateOfBirth_[2]) - 1;
        } else{
            age_ = (currentDate_[2] - dateOfBirth_[2]);
        }
        std::cout << "The date has been\nsuccessfully validated and age is set.\n";
        std::cout << "You are " << age_ << " years old.";
        std::cout << std::endl << std::endl;
    } else {
        std::cout << "The date was not\nsuccessfully validated and age is not set.";
        std::cout << std::endl << std::endl;
        exit(-1);
    }
}
