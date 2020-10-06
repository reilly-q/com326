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
#include "student/Student.h"

// Challenge Methods
void challenge1(); /* String warmup */
void challenge2(); /* Camel case */
void challenge3(); /* Valid email */
void challenge4(); /* Caesar Cipher */

void additionalChallenge1(); /* Swedish Chef */
void additionalChallenge2(); /* Mars Exploration */

// Other methods
void introDiceCountCombo();
void introRegex();
std::string encryptMessage(std::string s, int k);
std::string decryptMessage(std::string s, int k);

// Main loop
int main() {
    //challenge1();
    challenge2();
    //challenge3();
    //challenge4();

    // End program
    return 0;
}

void challenge2() {
    Student st;

    st.toString();
    std::cout << st.CalculateClassification() << std::endl;

    st.setName("Mark Gonzales");
    st.setRegistrationId("SK8LEG3ND");
    st.setCourse("Skateboarding is not a crime");
    st.setModuleOneMark(10);

    st.toString();
    std::cout << st.CalculateClassification() << std::endl;
}
