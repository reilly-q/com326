/*
 * main.cpp
 *
 * Version Information
 * Author: Quinn Reilly
 * Date: 29 sept 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"

// Challenge Methods

// Other methods
void introDiceCountCombo();
void introRegex();

// Main loop
int main() {
    //introDiceCountCombo();
    introRegex();

    // End program
    return 0;
}

void introDiceCountCombo() {
    // Initialize variables
    int counter = 0;
    int target = 0;

    // Instruct user and get user input.
    std::cout << "Choose a number to test: ";
    std::cin >> target;
    std::cout << std::endl;

    /* 3 for loops to represent 3 die. Count the possible combinations
     * that equal target.
     */
    for(int i = 1; i < 7; i++) {
        for(int j = 1; j < 7; j++) {
            for(int k = 1; k < 7; k++) {
                if(i + j + k == target) {
                    counter++;
                }
            }
        }
    }

    std::cout << "No. of possible combinations: " << counter << std::endl;
}
void introRegex() {
    // Build a regex to extract postcode.
    std::string address = "Ulster University, Magee Campus, BT48 7JL, UK";
    std::regex r1("[a-zA-Z]{1,2}\\d{1,2} \\d{1, 2}[a-zA-Z]{1,2}"); //\D\D\d\d\s\d\D\D
    std::smatch m1;

    if(std::regex_search(address, m1, r1)) {
        std::cout << m1.str() << std::endl;
    } else {
        std::cout << "No match\n";
    }
}
