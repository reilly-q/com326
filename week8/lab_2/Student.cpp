/*
* Student.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson & Dr. Effirul Ramlan
* Date: 8/10/2017 || Modified: 29/09/2019
* Description: Class definition .cpp file for the Student Class
* Copyright notice
*/

#include "Student.h"

int Student::numberOfStudents_{ 0 };

int Student::GetEnrolled() {
	return numberOfStudents_;
}

std::istream& operator>>(std::istream& input, Student& student) {
	std::cout << "Enter the following details:\n";
	std::cout << "Name: ";
	getline(input, student.name_);

	std::cout << "Registration ID: ";
	input >> student.registrstionID_;
	
	std::cout << "Course Name: ";
	input.ignore();
	getline(input, student.course_);

	std::cout << "Year of Study: ";
	input >> student.yearofStudy_;

	return input;
}

std::ostream& operator<<(std::ostream& output, Student& student) {
	output << "Student Details: \n";
	output << "Name: " << student.GetName() << std::endl;
	output << "Registration ID: " << student.GetRegistrationID() << std::endl;
	output << "Course: " << student.GetCourse() << std::endl;
	output << "Year of Study: " << student.GetYearofStudy() << std::endl;

	return output;
}

// Ch04 - Task 3
bool operator==(Student& student1, Student& student2) {
	if (student1.GetName() == student2.GetName()) {
		if (student1.GetRegistrationID() == student2.GetRegistrationID()) {
			if (student1.GetCourse() == student2.GetCourse()) {
				if (student1.GetYearofStudy() == student2.GetYearofStudy()) {
					return 1;
				}
			}
		}
	}

	return 0;
}

void operator++(Student& student) {
	switch (student.GetYearofStudy()) {
	case 1: student.AddModule("Object Oriented Programming", "COM 326", 20, 0);
		break;
	case 2: student.AddModule("Data Structure", "COM 328", 20, 2);
		break;
	}

	++student.yearofStudy_;
}

void operator++(Student& student, int) {
	switch (student.GetYearofStudy()) {
	case 1: student.AddModule("Object Oriented Programming", "COM 326", 20, 0);
		break;
	case 2: student.AddModule("Data Structure", "COM 328", 20, 2);
		break;
	}

	student.yearofStudy_++;
}

//Default constuctor
//Note how we use the scope resolution operator ::
//We do that to specify which class the member functions belong to
//Class_Name::Member_Function
Student::Student() {
	std::cout << "The default Student class constructor was called" << std::endl;
	//yearofStudy_ = GetYearofStudy();
	yearofStudy_ = 0;
	numberOfStudents_++;
}

Student::Student(std::string name) {
	name_ = name;
	std::cout << "The first custom Student class constructor was called" << std::endl;
	numberOfStudents_++;
}

//This constructor creates and initialises it by copying the data from each variable
//into the specified data member. We use an initializer list but we could also initialize each
//variable by using assignment statements in the main body of the function
Student::Student(std::string name, std::string registration, std::string course, int yearofStudy, std::vector<Module> m)
	: name_{ name }, registrstionID_{ registration }, course_{ course }, yearofStudy_{ yearofStudy }, moduleMarks_{ m }
{
	std::cout << "The second custom Student class constructor was called" << std::endl;
	//we could assign the values of the parameters to the data members like this
	//name_ = name;
	numberOfStudents_++;

}

// Task 1 - destructor
Student::~Student() {
	std::cout << "Destructor of the Student class called on " << name_ << std::endl;
	numberOfStudents_--;

}

//Getters and setters
void Student::SetName(std::string name) {
	name_ = name;
}

//Make getters const so that it tells the compiler to complain if we accidentlly 
//try to change a data member 
std::string Student::GetName() const {
	return name_;
}

void Student::SetRegistrationID(std::string registrstionID) {
	registrstionID_ = registrstionID;
}
std::string Student::GetRegistrationID() const {
	return registrstionID_;
}

void Student::SetCourse(std::string course) {
	course_ = course;
}
std::string Student::GetCourse() const {
	return course_;
}

void Student::SetYearofStudy(int year) {
	yearofStudy_ = year;
}
int Student::GetYearofStudy() const {
	return yearofStudy_;
}

void Student::SetModuleMarks(std::vector<Module> mMarks) {
	moduleMarks_ = mMarks;
}

std::vector<Module> Student::GetModuleMarks() const {
	return moduleMarks_;
}

// Task 6 - Need to modify the class to incorporate the use of vector
// To print the module name and marks for each module
void Student::ToString() const {
	std::string output = name_ + " " + registrstionID_ + " " + course_ + " " + std::to_string(yearofStudy_) + " " + "\n";
	for (int index = 0; index < moduleMarks_.size(); index++) {
		output = output + "\nModule Code: " + moduleMarks_.at(index).getModuleCode() + "\nModule Name: " + moduleMarks_.at(index).getModuleTitle() + "\n";
	}
	std::cout << output << std::endl;
}

std::string Student::CalculateClassification() const {

	int average = 0;
	int totalMark = 0;
	int index = 0;

	for (index; index < moduleMarks_.size(); index++) {
		totalMark += moduleMarks_.at(index).getModuleMark();
	}

	// To avoid division by zero - for student with only 1 course
	if (index > 0)
		average = totalMark / index;
	else
		average = totalMark / 1;

	if (average < 40) {
		return "fail";
	}
	else if (average >= 40 && average <= 49) {
		return "3rd class";
	}
	else if (average >= 50 && average <= 59) {
		return "2nd class";
	}
	else if (average >= 60 && average <= 69) {
		return "2-1";
	}
	else
		return "1st class";
}

void Student::AddModule(Module m) {
	moduleMarks_.push_back(m);
}

void Student::AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	Module m(moduleTitle, moduleCode, moduleCreditPoints, moduleMark);
	moduleMarks_.push_back(m);

}

void Student::DeleteModule(std::string moduleCode) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.erase(moduleMarks_.begin() + index);
		}
	}
}

void Student::UpdateModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.at(index).setModuleCreditPoints(moduleCreditPoints);
			moduleMarks_.at(index).setModuleTitle(moduleTitle);
			moduleMarks_.at(index).setModuleMark(moduleMark);
		}
	}
}

