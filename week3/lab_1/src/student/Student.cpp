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
#include "Student.h"

// Constructors
Student::Student() {
    // Set strings
    name_ = "Billy, Bragg";
    registrationId_ = "B00578985";
    course_ = "Music theory";

    // Set int
    yearOfStudy_ = 3;
    moduleOneMark_ = 87;
    moduleTwoMark_ = 92;
    moduleThreeMark_= 47;
}

Student::Student(std::string nm, std::string id, std::string crs, int yr, int m1, int m2, int m3) {
    // Set strings
    name_ = nm;
    registrationId_ = id;
    course_ = crs;

    // Set int
    yearOfStudy_ = yr;
    moduleOneMark_ = m1;
    moduleTwoMark_ = m2;
    moduleThreeMark_ = m3;
}

// Utility functions
void Student::toString() {
    // Print strings
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Registration ID: " << registrationId_ << std::endl;
    std::cout << "Course: " << course_ << std::endl;

    //Print int
    std::cout << "Year of Study: " << yearOfStudy_ << std::endl;

    //Print classification
    //std::cout << CalculateClassification() << std::endl;
};

std::string Student::CalculateClassification() {
    std::string classification;
    int average = (moduleOneMark_ + moduleTwoMark_ + moduleThreeMark_) / 3;

    if(average >= 0 && average < 40)
        classification = "Fail";
    else if(average >= 40 && average < 50)
        classification = "3rd Class";
    else if(average >= 50 && average < 60)
        classification = "2-1";
    else if(average >= 60 && average < 70)
        classification = "1st Class";
    else
        classification = "1st Class";

    return classification;
}

// Setters - strings, ints
void Student::setName(std::string nm) {
    name_ = nm;
};

void Student::setRegistrationId(std::string id) {
    registrationId_ = id;
};

void Student::setCourse(std::string crs) {
    course_ = crs;
};

void Student::setYearOfStudy(int yr) {
    if(yr > 0 && yr < 6) yearOfStudy_ = yr;
};

void Student::setModuleOneMark(int m1) {
    if(m1 >= 0 && m1 <= 100) moduleOneMark_ = m1;
};

void Student::setModuleTwoMark(int m2) {
    if(m2 >= 0 && m2 <= 100) moduleTwoMark_ = m2;
};

void Student::setModuleThreeMark(int m3) {
    if(m3 >= 0 && m3 <= 100) moduleThreeMark_ = m3;
};

// Getters - strings, ints
std::string Student::getName() const {
    return name_;
};

std::string Student::getRegistrationId() const {
    return registrationId_;
};

std::string Student::getCourse() const {
    return course_;
};

int Student::getYearOfStudy() const {
    return yearOfStudy_;
};

int Student::getModuleOneMark() const {
    return moduleOneMark_;
};

int Student::getModuleTwoMark() const {
    return moduleTwoMark_;
};

int Student::getModuleThreeMark() const {
    return moduleThreeMark_;
};
