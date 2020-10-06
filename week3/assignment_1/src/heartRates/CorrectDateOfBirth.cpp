/*
 * CorrectDateOfBirth.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "HeartRates.h"

void HeartRates::CorrectDateOfBirth(std::vector<int>& dob) {
    // Init variables - bools, vectors
    bool dateVerified = 0;

    std::vector<int> tmp = dob;
    tmp.reserve(3);

    if(dob.size() > 3) {
        for(int i = 0; i < dateOfBirth_.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth has been successfully cut to correct size.";
    } else if(dob.size() < 3) {
        for(int i = 0; i < dob.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth has been successfully inserted to correct size.";

        std::cout << tmp[2];
    } else {
        dateOfBirth_ = dob;
    }

    if(dob.size() == 3) {
        if(dateOfBirth_[0] > 0 && dateOfBirth_[0] < 100) {
            dateOfBirth_ = dob;
        }
    } else {

    }
}
