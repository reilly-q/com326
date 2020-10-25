/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"
#include "heartRates/HeartRates.h"

// Additional methods
int CheckForLetters(std::string tmp);

// Main loop
int main() {
    // Init variables - strings, vectors, ints
    std::string firstName, lastName, tmp;

    std::vector<int> dob; dob.resize(3);

    int counter = 0;

    // Instruct user and get input.
    // Get Name 1.
    std::cout << "Please enter your first name:\t\t";
    std::cin >> firstName;
    std::cout << std::endl;

    // Get Name 2.
    std::cout << "Please enter your last name:\t\t";
    std::cin >> lastName;
    std::cout << std::endl;

    // Get Date of Birth 1.
    std::cout << "Please enter the day you were born:\t";
    std::cin >> tmp;
    std::cout << std::endl;
    counter = CheckForLetters(tmp);

    if(counter == 0) {
        dob[0] = std::stoi(tmp);
    } else {
        std::cout << "Input is invalid.";
        std::cout << std::endl;

        exit(-1);
    }
    counter = 0;

    // Get Date of Birth 2.
    std::cout << "Please enter the month you were born:\t";
    std::cin >> tmp;
    std::cout << std::endl;
    counter = CheckForLetters(tmp);

    if(counter == 0) {
        dob[1] = std::stoi(tmp);
    } else {
        std::cout << "Input is invalid.";
        std::cout << std::endl;

        exit(-1);
    }
    counter = 0;

    // Get Date of Birth 3.
    std::cout << "Please enter the year you were born:\t";
    std::cin >> tmp;
    std::cout << std::endl;
    counter = CheckForLetters(tmp);

    if(counter == 0) {
        dob[2] = std::stoi(tmp);
    } else {
        std::cout << "Input is invalid.";
        std::cout << std::endl;

        exit(-1);
    }
    counter = 0;

    // Init HeartRates object.
    HeartRates hr(firstName, lastName, dob);
    hr.CalculateMaxHeartRate();
    hr.CalculateTargetHeartRate();

    // Print output.
    std::cout << "Hello " << hr.GetFirstName() << " " << hr.GetLastName() << "." << std::endl;

    std::cout << "Your max heart rate is:\t\t\t" << hr.GetMaxHeartRate() << std::endl;
    std::cout << "Your low target heart rate is:\t\t" << hr.GetTargetHeartRateLower() << std::endl;
    std::cout << "Your high target heart rate is:\t\t" << hr.GetTargetHeartRateHigher() << std::endl << std::endl;

    // End program
    return 0;
}

int CheckForLetters(std::string tmp) {
    int counter = 0;

    for(int i = 0; i < tmp.size(); i++) {
        if((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z')) {
            counter++;
        }
    }

    return counter;
}
