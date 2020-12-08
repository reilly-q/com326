/*
* Module.h
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
class Module
{
private:
	std::string moduleTitle_;
	std::string moduleCode_;
	int moduleCreditPoints_;
	int moduleMark_;

public:
	Module();
	Module(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);

	// Task 1 - Adding a destructor
	~Module();

	std::string getModuleTitle() const;
	void setModuleTitle(std::string);

	std::string getModuleCode() const;
	void setModuleCode(std::string);

	int getModuleMark() const;
	void setModuleMark(int mark);

	int getModuleCreditPoints() const;
	void setModuleCreditPoints(int creditPoints);


};

