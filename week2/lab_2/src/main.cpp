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

// Main loop
int main() {
    introDiceCountCombo();

    // End program
    return 0;
}

void introDiceCountCombo() {
    int counter = 0;
    int target = 0;

    std::cout << "Choose a number to test: ";
    std::cin >> target;
    std::cout << std::endl;

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
