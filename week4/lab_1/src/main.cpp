/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"
#include "student/Student.h"
#include <cassert>

// Challenge Methods
void challenge1(); /* Crashing make the program crash on purpose. */
void challenge2(); /* Use an assert. Check if the two arrays are the same size. */
void challenge3(); /* Use an assert. Check if the two arrays are the same size. Wrapped in preprocessor. */
void challenge4(); /* Create two students to test Student.h */
void challenge5(); /* Implement a menu system */

// Other methods=

// Main loop
int main() {
    //challenge1();
    //challenge2();
    //challenge3();
    //challenge4();

    // End program
    return 0;
}

void challenge1() {
    // Initialize variables - const ints, int arrays.
    const int size1 = 8, size2 = 5;
    int a1[size1]{0, 1, 2, 3, 4, 5, 6, 7};
    int a2[size2];

    // Try to crash the program by assigning variables to non existing points in second array.
    for(int i = 0; i < size1; i++) {
        a2[i] = a1[i];
        std::cout << a1[i] << std::endl;
        std::cout << a2[i] << std::endl;
    }
}

void challenge2() {
    // Initialize variables - const ints, int arrays.
    const int size1 = 8, size2 = 5;
    int a1[size1]{0, 1, 2, 3, 4, 5, 6, 7};
    int a2[size2];

    assert(size1 == size2 && "Holy mama ... the size is not the same !!!");
}

void challenge3() {
    // Initialize variables - const ints, int arrays.
    const int size1 = 8, size2 = 5;
    int a1[size1]{0, 1, 2, 3, 4, 5, 6, 7};
    int a2[size2];

#ifndef NDEBUG
    assert(size1 == size2 && "Holy mama ... the size is not the same !!!");
#endif
}

void challenge4() {
    Student s1("Tiger Woods", "B00769147", "BSc Hons Computer Science", 2);
    s1.AddModule("Object Oriented Programming", "COM326", 5, 90);
    s1.AddModule("UX/UI Development", "COM321", 5, 85);
    s1.AddModule("Professional Development", "EEE407", 5, 95);

    Student s2("Shane Lowry", "B00769148", "BSc Hons Information Technology", 2);
    s2.AddModule("Object Oriented Programming", "COM326", 5, 60);
    s2.AddModule("UX/UI Development", "COM321", 5, 85);

    std::cout << "Student Information:\n";
    s1.toString();
    std::cout << "Classification: " << s1.CalculateClassification() << std::endl;

    std::cout << "\n\n";
    s2.toString();
    std::cout << "Classification: " << s2.CalculateClassification() << std::endl;
}

void challenge5() {
    
}
