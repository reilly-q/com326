/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 20 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"
#include "person/Person.h"


// Challenge Methods
void challenge1(); /* Warm up exercise. */
void challenge2(); /* Arrays and vectors. Print arrays and vectors using pointers. */
void challenge3(); /* Objects and pointers. Create a person class. */
void challenge4(); /* Tic-Tac-Toe. Use some pointers. */

// Other methods
void CalculateGravity(float altitude, float& gravity); /* Calculate gravity at certain altitude. */
void Print(float a[], int size); /* Print array using pointers. */
void Print(std::vector<float> &b, int size); /* Print vector using pointers. */

bool Compare(Person &p1, Person &p2);

// Main loop
int main() {
    challenge1();
    challenge2();
    challenge3();
    //challenge4();

    // End program
    return 0;
}

void challenge1() {
    float gravity {9.800665f};
    float speed {9.800665f};
    float *aPtr = nullptr, *bPtr = nullptr;
    aPtr = &gravity;
    bPtr = aPtr;

    std::cout << "the value of gravity: " << gravity << std::endl;
    std::cout << "the address of gravity: " << &gravity << std::endl;
    std::cout << "the size of gravity: " << sizeof(gravity) << std::endl << std::endl;

    float altitude {6731.0f};
    CalculateGravity(altitude, gravity);

    std::cout << "Gravity after Calculation: " << gravity << std::endl << std::endl;

    std::cout << "the value of aPtr: " << aPtr << std::endl;
    std::cout << "the address of aPtr: " << &aPtr << std::endl;
    std::cout << "the value of pointer of aPtr: " << *aPtr << std::endl;
    std::cout << "the size of aPtr: " << sizeof(aPtr) << std::endl << std::endl;

    std::cout << "the value of bPtr: " << bPtr << std::endl;
    std::cout << "the address of bPtr: " << &bPtr << std::endl;
    std::cout << "the value of pointer of bPtr: " << *bPtr << std::endl;
    std::cout << "the size of bPtr: " << sizeof(bPtr) << std::endl << std::endl;
}

void challenge2() {
    float a[]{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> b{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    Print(a, 5);
    Print(b, 5);
}

void challenge3() {
    Person paul("Paul", "Doherty", "Ninja", 33);
    Person Mary("Mary", "McGonigle", "CTO", 28);
    Person paul2("Paul", "Doherty", "Ninja", 33);

    if(Compare(paul, paul2)) {
        std::cout << "This is the same person\n";
    } else {
        std::cout << "This is a different person\n";
    }
}

void CalculateGravity(float altitude, float& gravity) {
    // gravity = gravity * (1 / altitude) ^ 2
    float tmp = 6400.0f / altitude;
    tmp = pow(tmp, 2);

    gravity = gravity * tmp;
}

void Print(float a[], int size) {
    //float *a{nullptr};
    //a = &a[0];

    for(int i = 0; i < size; i++) {
        std::cout << *a << std::endl;
        a++;
    }
    std::cout << std::endl;
}

void Print(std::vector<float>& b, int size) {
    float *number{&b[size] - 1};

    for(int i = 0; i < size; i++) {
        std::cout << *number   << std::endl;
        number--;
    }
    std::cout << std::endl;
}

bool Compare(Person &p1, Person &p2) {
    Person *p1Ptr{ nullptr };
    Person *p2Ptr{ nullptr };

    p1Ptr = &p1;
    p2Ptr = &p2;

    if(p1Ptr->getFirstName() != p2Ptr->getFirstName()) {
        return false;
    } else if(p1Ptr->getSecondName() != p2Ptr->getSecondName()) {
        return false;
    } else if(p1Ptr->getAge() != p2Ptr->getAge()) {
        return false;
    }

    return true;
}
