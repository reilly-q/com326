#ifndef PERSON_H
#define PERSON_H

/*
 * Person.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 20 oct 2020
 *
 * Copyright notice
 */

#include "../../inc/common.h"
#include "../module/Module.h"

class Person {
private:

    // Declare variables - strings, vectors, ints
    std::string firstName_;
    std::string secondName_;
    std::string occupation_;
    int age_;

public:

    // Constructors
    Person(std::string firstName, std::string secondName, std::string occupation, int age) : firstName_{firstName}, secondName_{secondName}, occupation_{occupation}, age_{age} {}
    // Utility functions

    // Utility functions for Module

    // Setters - strings, ints
    //void setModuleOneMark(int);

    // Getters - strings, ints
    std::string getFirstName() const{return firstName_;};
    std::string getSecondName() const{return secondName_;};
    std::string getOccupatio() const {return occupation_;}
    int getAge() const{return age_;};
};

#endif
