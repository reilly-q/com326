#ifndef STUDENT_H
#define STUDENT_H

/*
 * common.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

#include "../../inc/common.h"

class Student {
private:

    // Declare variables - strings, ints
    std::string name_;
    std::string registrationId_;
    std::string course_;

    int yearOfStudy_;
    int moduleOneMark_;
    int moduleTwoMark_;
    int moduleThreeMark_;

public:

    // Constructors
    Student();
    Student(std::string, std::string, std::string, int, int, int, int);

    // Utility functions
    void toString();
    std::string CalculateClassification();

    // Setters - strings, ints
    void setName(std::string);
    void setRegistrationId(std::string);
    void setCourse(std::string);

    void setYearOfStudy(int);
    void setModuleOneMark(int);
    void setModuleTwoMark(int);
    void setModuleThreeMark(int);

    // Getters - strings, ints
    std::string getName() const;
    std::string getRegistrationId() const;
    std::string getCourse() const;

    int getYearOfStudy() const;
    int getModuleOneMark() const;
    int getModuleTwoMark() const;
    int getModuleThreeMark() const;
};

#endif
