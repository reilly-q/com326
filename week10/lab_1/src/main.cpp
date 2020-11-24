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
#include "Module.h"
#include "Lecturer.h"
#include "CarbonFootPrint.h"
#include "Bicycle.h"
#include "Building.h"
#include "Car.h"

int main() {

    /*

	// Set the module for the students
	//Module tempM2;
	//Module tempM3{ "Data Structures", "COM328", 20, 90 };

	std::vector<Module> m{};
	m.push_back(Module{ "Fundamental of Programming", "COM149", 20, 70 });

	// Calling the custom constructor 2
	Student stu1("Jeni Watt", "email@email.com", "B004568656", "BSc Computing", 1, m);

    Person* personPtr = &stu1;
    std::cout << personPtr->ToString() << std::endl;
	//stu1.ToString();
	//cout << "Status: " << stu1.CalculateClassification() << endl;

    // Set lecturer object

    Lecturer lecturer("Effirul Ramlan", "e.ramlan@ulster.ac.uk", "s999999", "Biological Computing", m);
    personPtr = &lecturer;
    std::cout << personPtr->ToString() << std::endl;

	cout << "\n---------------------------------------------------\n";

    */

    std::vector<CarbonFootPrint*> cfpPtr;
    cfpPtr.push_back(new Bicycle("Road Bike"));
    cfpPtr.push_back(new Building(50000));
    cfpPtr.push_back(new Car(50));

    for(size_t i{0}; i < cfpPtr.size(); i++) {
        cfpPtr.at(i)->GetCarbonFootPrint();
    }

    for(size_t i{0}; i < cfpPtr.size(); i++) {
        delete cfpPtr.at(i);
    }

    /*
	// Calling the custom constructor 1
	Student stu2("Frank Lyons");
	stu2.SetRegistrationID("B0033438656");
    stu2.setEmail("email@email.com");
	stu2.SetCourse("BSc Information Technology");
	stu2.SetYearofStudy(2);
	stu2.AddModule("Fundamental of Programming", "COM149", 20, 70);
	stu2.AddModule(Module{ "Object Oriented Programming", "COM326", 20, 90 });

	//stu2.ToString();
	//cout << "Status: " << stu2.CalculateClassification() << endl;

	cout << "\n---------------------------------------------------\n";

	// Calling default constructor
	Student stu3;
	//cin >> stu3;
	//cout << stu3;

	if (stu1 == stu1) {
		cout << "Identical student\n";
	}
	else {
		cout << "Different student\n";
	}

	stu1++;
	stu1.ToString();

	++stu1;
	stu1.ToString();

	//stu3.SetName("Paul Doherty");
	//stu3.SetCourse("BSc Artificial Intelligence");
	//stu3.SetRegistrationID("B004556565");
	//stu3.SetYearofStudy(1);
	//tempM1.setModuleMark(35);
	//stu1.AddModule(tempM1);
	//stu1.ToString();
	//cout << "Status: " << stu3.CalculateClassification() << endl;

	//Module* modPtr = &module;
	//string code = modPtr->getModuleCode();

    */

	return 0;
}
