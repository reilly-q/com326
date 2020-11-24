/*
* Person.h
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

// Task 1 Module Class declaration
class Person
{
private:
	std::string name_;
	std::string email_;

public:
	Person();
	Person(std::string name, std::string email);

	// Task 1 - Adding a destructor
	~Person();

	std::string getName() const;
	void setName(std::string);

	std::string getEmail() const;
	void setEmail(std::string);

    virtual std::string ToString();
};
