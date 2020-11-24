/*
* Lecturer.h
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Class definition .cpp file for the Module Class
* Copyright notice
*/

#include "Lecturer.h"

Lecturer::Lecturer() {

}

Lecturer::Lecturer(std::string name, std::string email, std::string staffId, std::string subjectArea, std::vector<Module> m) : Person(name, email), staffId_{staffId}, subjectArea_{subjectArea}, modules_{m} {

}

// Task 1 - Adding a destructor
Lecturer::~Lecturer() {

}

std::string Lecturer::getStaffId() const {
    return staffId_;
}

void Lecturer::setStaffId(std::string staffId) {
    staffId_ = staffId;
}

std::string Lecturer::getSubjectArea() const {
    return subjectArea_;
}

void Lecturer::setSubjectArea(std::string subjectArea) {
    subjectArea_ = subjectArea;
}

std::vector<Module> Lecturer::getModules() const {
    return modules_;
}

void Lecturer::setModules(std::vector<Module> m) {
    modules_ = m;
}

std::string Lecturer::ToString()  {
    std::string output = Person::ToString() + " " + staffId_ + " " + subjectArea_ + " " + "\n";
	for (int index = 0; index < modules_.size(); index++) {
		output = output + "\nModule Code: " + modules_.at(index).getModuleCode() + "\nModule Name: " + modules_.at(index).getModuleTitle() + "\n";
	}
	return output;
}
