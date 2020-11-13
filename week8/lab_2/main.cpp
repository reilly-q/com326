// Include headers
#include <iostream>

#include "Module.h"
#include "Student.h"

// Challenge functions
void challenge1();
void challenge2();
void challenge3();
void challenge4();

// Supplementary functions


// Other functions


int main() {
	// Call challenge functions
	//challenge1();

	/*Student defStudent;
	std::cin >> defStudent;
	std::cout << defStudent;*/

	/*Student defStudent1;
	Student defStudent2;

	int i = (defStudent1 == defStudent2);

	std::cout << i << std::endl;*/

	std::vector<Module> m{ 3 };

	Student stu2("Frank Lyons");
	stu2.SetRegistrationID("B0033438656");
	stu2.SetCourse("BSc Information Technology");
	stu2.SetYearofStudy(2);

	Module tempM1{ "Fundamental of Programming", "COM149", 20, 70 };
	Module tempM2{ "Object Oriented Programming", "COM326", 20, 90 };
	Module tempM3{ "Data Structures", "COM328", 20, 90 };

	stu2.AddModule(tempM1);
	stu2.AddModule(tempM2);
	stu2++;
	std::cout << stu2 << std::endl;

	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 3, m);
	stu1.ToString();
	std::cout << "Status: " << stu1.CalculateClassification() << std::endl;

	if (stu1 == stu2) {
		std::cout << "This is the same student." << std::endl;
	} else{
		std::cout << "This is the same student." << std::endl;
	}

	// Exit Program
	return 0;
}

// Initialize challenge functions
void challenge1() {

	// Set the module for the students
	Module tempM1{ "Fundamental of Programming", "COM149", 20, 70 };
	Module tempM2{ "Object Oriented Programming", "COM326", 20, 90 };
	Module tempM3{ "Data Structures", "COM328", 20, 90 };

	std::vector<Module> m{ 3 };
	m.at(0) = tempM1;
	m.at(1) = tempM2;
	m.at(2) = tempM3;

	// Calling the custom constructor 2
	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 3, m);
	stu1.ToString();
	std::cout << "Status: " << stu1.CalculateClassification() << std::endl;

	std::cout << "\n---------------------------------------------------\n";

	// Calling the custom constructor 1
	Student stu2("Frank Lyons");
	stu2.SetRegistrationID("B0033438656");
	stu2.SetCourse("BSc Information Technology");
	stu2.SetYearofStudy(2);
	tempM1.setModuleMark(50);
	tempM2.setModuleMark(75);
	stu2.AddModule(tempM1);
	stu2.AddModule(tempM2);
	stu2.ToString();
	std::cout << "Status: " << stu2.CalculateClassification() << std::endl;

	std::cout << "\n---------------------------------------------------\n";

	// Calling default constructor
	Student stu3;
	stu3.SetName("Paul Doherty");
	stu3.SetCourse("BSc Artificial Intelligence");
	stu3.SetRegistrationID("B004556565");
	stu3.SetYearofStudy(1);
	tempM1.setModuleMark(35);
	//stu1.AddModule(tempM1);
	//stu1.ToString();
	stu3.AddModule(tempM1);
	stu3.ToString();
	std::cout << "Status: " << stu3.CalculateClassification() << std::endl;

	//Module* modPtr = &module;
	//string code = modPtr->getModuleCode();
}
