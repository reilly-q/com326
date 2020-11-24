/*
* Person.h
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Class definition .cpp file for the Module Class
* Copyright notice
*/

#include "Person.h"

Person::Person() {

}

Person::Person(std::string name, std::string email) : name_{name}, email_{email} {

}

// Task 1 - Adding a destructor
Person::~Person() {

}

std::string Person::getName() const {
    return name_;
}

void Person::setName(std::string name) {
    name_ = name;
}

std::string Person::getEmail() const {
    return email_;
}

void Person::setEmail(std::string email) {
    email_ = email;
}

std::string Person::ToString() {
    return (name_ + " " + email_);
}
