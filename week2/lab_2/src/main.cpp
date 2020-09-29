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
void challenge1();
void challenge2();
void challenge3();
void challenge4();

// Other methods
void introDiceCountCombo();
void introRegex();

// Main loop
int main() {
    //introDiceCountCombo();
    //introRegex();

    //challenge1();
    //challenge2();
    //challenge3();
    challenge4();

    // End program
    return 0;
}

void challenge1() {
    // Initialize Variables
    std::string s1, s2, input;

    // Instruct user and get input.
    std::cout << "Enter word one: ";
    std::getline(std::cin, s1);
    std::cout << std::endl;

    std::cout << "Enter word two: ";
    std::getline(std::cin, s2);
    std::cout << std::endl;

    // Convert uppercase characters to lowercase.
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] >= 65 && s1[i] <= 90) {
            s1[i] = s1[i] + 32;
        }
    }

    for(int i = 0; i < s1.size(); i++) {
        if(s2[i] >= 65 && s2[i] <= 90) {
            s2[i] = s2[i] + 32;
        }
    }

    // Build a regex to extract secret message.
    std::regex r1("([Hh]oliday|[Bb]elize)");
    std::smatch m1;

    // Check regex against s1 and s2.
    if(std::regex_search(s1, m1, r1) || std::regex_search(s2, m1, r1)) {
        std::cout << "Are you a secret agent?: ";
        std::cin >> input;
        std::cout << std::endl;

        // Ask user if they are a secret agent.
        if(input == "yes" || input == "Yes") {
            std::cout << "Bang! You're dead!" << std::endl;
        }
    } else {
        // Check if the strings match.
        if(s1 == s2) {
            std::cout << "This pleases Chuck Norris!";
        } else {
            std::cout << "I pity the fool";
        }
        std::cout << std::endl;
    }
}

void challenge2() {
    // Initialize variables
    std::string input;
    int count = 1;

    // Instruct user and get input.
    std::cout << "Enter a camel case statement to count its words: ";
    std::getline(std::cin, input);
    std::cout << std::endl;

    // Check for uppercase letters and count.
    for(int i = 0; i < input.size(); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            count++;
        }
    }

    std::cout << "There are " << count << " words in this string" << std::endl;
}

void challenge3() {
    // Initialize variables
    std::string input;

    // Instruct user and get input.
    std::cout << "Enter your email: ";
    std::getline(std::cin, input);
    std::cout << std::endl;

    // Build a regex to extract a valid email address.
    std::regex r1("[\\w\\d]+@[\\w\\d]+.[a-z]+.?[a-z]?+");
    std::smatch m1;

    // Make sure there is a result and check that against the input.
    if(std::regex_search(input, m1, r1) && m1.str() == input)
        std::cout << "This is a valid email";
    else
        std::cout << "This is not a valid email";

    std::cout << std::endl;
}

void challenge4() {
    // Initialize variables
    std::string s;
    int k;
    int count = 0;

    // Instruct user and get input.
    std::cout << "Enter your message to encrypt: ";
    std::getline(std::cin, s);
    std::cout << std::endl;

    // Instruct user and get input.
    std::cout << "Enter your rotation offset number: ";
    std::cin >> k;
    std::cout << std::endl;

    // Check for illegal characters.
    for(int i = 0; i < s.size(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || "-")) {
            count++;
        }
    }

    // Check that input is correct before encrypting and decrypting message.
    if((k <= 100 && k >= 0) && count == 0) {
        // Move letters foward.
        for(int i = 0; i < s.size(); i++) {
            count = 0;
            for(int j = s[i]; j <= s[i] + k; j++) {
                if(j > 'z') {
                    count = 0;
                } else {
                    count++;
                }
            }
            if(s[i] != '-') {
                s[i] += count;
            }
        }

        //count = 0;

        std::cout << s << std::endl;

        // Move letter back
        for(int i = 0; i < s.size(); i++) {
            count = 0;
            for(int j = s[i]; j >= s[i] - k; j--) {
                if(j < 'a') {
                    count = 0;
                } else {
                    count++;
                }
            }
            if(s[i] != '-') {
                s[i] -= count;
            }
        }

        std::cout << s << std::endl;
    } else {
        std::cout << "Only letters are allowed. No spaces or numbers. "
            "K must be between 0 and 100" << std::endl;
    }


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
    std::regex r1("[a-zA-Z]{1,2}\\d{1,2} \\d{1,2}[a-zA-Z]{1,2}"); //\D\D\d\d\s\d\D\D
    std::smatch m1;

    if(std::regex_search(address, m1, r1)) {
        std::cout << m1.str() << std::endl;
    } else {
        std::cout << "No match\n";
    }
}
