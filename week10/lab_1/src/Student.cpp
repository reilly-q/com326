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

// Challenge 4 - Task 1
std::istream& operator>>(std::istream& input, Student& student) {
    std::string name{""};

	std::cout << "Please enter the following details: \n";
	std::cout << "Your name: ";
	std::getline(input, name);

    student.SetName(name);

	std::cout << "Registration id: ";
	input >> student.registrstionID_;

	std::cout << "Enter your course name: ";
	input.ignore();	// required to clear buffer from the first getline
	std::getline(input, student.course_);

	std::cout << "Enter your Year of Study: ";
	input >> student.yearofStudy_;
	return input;
}

// Challenge 4 - Task 2
std::ostream& operator<<(std::ostream& output, Student& student) {
	output << "\nStudent " << student.GetEnrolled() << " Details" << std::endl;
	output << "Name: " << student.GetName() << std::endl;
	output << "Registration: " << student.GetRegistrationID() << std::endl;
	output << "Course: " << student.GetCourse() << std::endl;
	output << "Year of study: " << student.GetYearofStudy() << std::endl;
	return output;
}

// Challenge 4 - Task 3
bool operator==(Student& lhs, Student& rhs) {
	if (lhs.Person::getName() == rhs.Person::getName()) {
		if (lhs.GetRegistrationID() == rhs.GetRegistrationID()) {
			if (lhs.GetModule() == rhs.GetModule()) {
				if (lhs.GetYearofStudy() == rhs.GetYearofStudy()) {
					return true;
				}
			}
		}
	}/*
	else {
		return false;
	}*/

    return false;
}

// Challenge 4 - Task 4
void operator++(Student& student) {
	switch (student.GetYearofStudy()) {
		case 1:	student.AddModule("Object Oriented Programming", "COM326", 20, 0);
			break;
		case 2: student.AddModule("Date Structure", "COM328", 20, 0);
			break;
	}
	++student.yearofStudy_;
}

void operator++(Student& student, int) {
	switch (student.GetYearofStudy()) {
	case 1:	student.AddModule("Object Oriented Programming", "COM326", 20, 0);
		break;
	case 2: student.AddModule("Date Structure", "COM328", 20, 0);
		break;
	}
	student.yearofStudy_++;
}

// Task 1 - Initialised the static data member
int Student::numberOfStudents_{ 0 };

//Default constuctor
//Note how we use the scope resolution operator ::
//We do that to specify which class the member functions belong to
//Class_Name::Member_Function
Student::Student() {
	std::cout << "The default Student class constructor was called to create an empty student" << std::endl;
	numberOfStudents_++;
	yearofStudy_ = GetYearofStudy();
}

Student::Student(std::string name) : yearofStudy_{ 0 } {
    SetName(name);
	std::cout << "The first custom Student class constructor was called to create " << Person::getName() << std::endl;
	numberOfStudents_++;
}

//This constructor creates and initialises it by copying the data from each variable
//into the specified data member. We use an initializer list but we could also initialize each
//variable by using assignment statements in the main body of the function
Student::Student(std::string name, std::string email, std::string registration, std::string course, int yearofStudy, std::vector<Module> m)
	: Person(name, email), registrstionID_{ registration }, course_{ course }, yearofStudy_{ yearofStudy }, moduleMarks_{ m }
{
	std::cout << "The second custom Student class constructor was called to create " << Person::getName() << std::endl;
	numberOfStudents_++;
	//we could assign the values of the parameters to the data members like this
	//name_ = name;
}

// Task - 1 Adding a destructor
Student::~Student() {
	std::cout << "Destructor of the insert Student class called on " << GetName() << std::endl;
	numberOfStudents_--;
}

//Getters and setters
void Student::SetName(std::string name) {
	Person::setName(name);
}

//Make getters const so that it tells the compiler to complain if we accidentlly
//try to change a data member
std::string Student::GetName() const {
	return Person::getName();
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

// Task 6 - Need to modify the class to incorporate the use of vector
// To print the module name and marks for each module
std::string Student::ToString() {
	std::string output = GetName() + " " + Person::getEmail() + " " + registrstionID_ + " " + course_ + " " + std::to_string(yearofStudy_) + " " + "\n";
	for (int index = 0; index < moduleMarks_.size(); index++) {
		output = output + "\nModule Code: " + moduleMarks_.at(index).getModuleCode() + "\nModule Name: " + moduleMarks_.at(index).getModuleTitle() + "\n";
	}
	return output;
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

int Student::GetModule() const {
	return (int)moduleMarks_.size();
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

// Task 1 - write static function
int Student::GetEnrolled() {
	return numberOfStudents_;
}
