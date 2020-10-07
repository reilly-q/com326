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

    std::vector<int> tmp; tmp.reserve(3);

    // Insert dob into tmp
    if(dob.size() > 3) {        /* Cut down to size */
        for(int i = 0; i < tmp.size(); i++) {
            tmp[i] = dob[i];
        }

        std::cout << "Date of birth provided was larger than DD/MM/YYYY and\n"
            "has been successfully cut to correct size.";
    } else if(dob.size() < 3) { /*  */
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
        tmp = dob;
    }

    std::cout << std::endl;

    if(tmp[2] > 0 && tmp[2] < 0 /* Check out time library */) {
        if(tmp[1] > 0 && tmp[1] < 13) {
            if((tmp[0] > 0 && tmp[0] < 29) && (tmp[1] == 2)) {

                tmp[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 30) && (tmp[1] == 2) && tmp[2] % 4 == 0) {

                tmp[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 31) && (tmp[1] == 4 ||
                tmp[1] == 6 || tmp[1] == 9 || tmp[1] == 11)) {

                tmp[0] = tmp[0];
                dateVerified = 1;

            } else if((tmp[0] > 0 && tmp[0] < 32) && (tmp[1] == 1 ||
                tmp[1] == 3 || tmp[1] == 5 || tmp[1] == 7 ||
                tmp[1] == 8 || tmp[1] == 10 || tmp[1] == 11)) {

                tmp[0] = tmp[0];
                dateVerified = 1;

            } else {
                std::cout << "The day is not valid";
            }
        } else {
            std::cout << "The month is not valid";
        }
    }
}
