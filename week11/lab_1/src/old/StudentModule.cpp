/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson & Dr. Effirul Ramlan
* Date: 8/10/2017 || Modified: 29/09/2019
* Description: Driver to test the student class
* Copyright notice
*/

#include <iostream>
#include "Student.h"
#include "Lecturer.h"
#include "Module.h"

using namespace std;

int main() {

	// Set the module for the students and lecturers
	std::vector<Module> m{};
	m.push_back(Module{ "Fundamental of Programming", "COM149", 20, 70 });
	m.push_back(Module{ "Object Oriented Programming", "COM326", 20, 90 });
	m.push_back(Module{ "Data Structures", "COM328", 20, 90 });

	Student student("Jeni Watt", "Watt-J1@ulster.ac.uk", "B10890022", "BSc Computer Science", 3, m);
	Lecturer lecturer("Mark Gonzales", "m.gonzales@ulster.ac.uk", "E1800444", "Data Analytics", m);

	Person* personPtr = nullptr;
	
	cout << "Testing virtual - override on Student\n";
	personPtr = &student;
	cout << personPtr->ToString() << endl;

	cout << "\nTesting virtual - override on Lecturer\n";
	personPtr = &lecturer;
	cout << personPtr->ToString() << endl;

	return 0;
}

