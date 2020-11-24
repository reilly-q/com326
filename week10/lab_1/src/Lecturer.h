/*
* Lecturer.h
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Header file for Module class
* Copyright notice
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Module.h"

// Task 1 Module Class declaration
class Lecturer : public Person
{
private:
	std::string staffId_;
	std::string subjectArea_;

    std::vector<Module> modules_;

public:
	Lecturer();
	Lecturer(std::string name, std::string email, std::string staffId, std::string subjectArea, std::vector<Module> m);

	// Task 1 - Adding a destructor
	~Lecturer();

	std::string getStaffId() const;
	void setStaffId(std::string);

	std::string getSubjectArea() const;
	void setSubjectArea(std::string);

	std::vector<Module> getModules() const;
	void setModules(std::vector<Module> m);

	virtual std::string ToString() override;
};
