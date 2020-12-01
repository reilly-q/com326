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
#include <vector>
#include <fstream>
#include <iomanip>

#include "studentModule/Student.h"
#include "studentModule/Lecturer.h"
#include "studentModule/Module.h"

bool WriteStudentDetails(std::vector<Student>& data);
std::vector<Student> ReadStudentDetails(std::string dataFile);

int main() {

	// Set the module for the students and lecturers
	std::vector<Module> m{};
	m.push_back(Module{ "Fundamental of Programming", "COM149", 20, 70 });
	m.push_back(Module{ "Object Oriented Programming", "COM326", 20, 90 });
	m.push_back(Module{ "Data Structures", "COM328", 20, 90 });

	Student student1("Jeni Watt", "Watt-J1@ulster.ac.uk", "B10890022", "BE Engineering", 3, m);
    Student student2("Quinn Reilly", "reilly-q@ulster.ac.uk", "B00769147", "BSc Computer Science", 2, m);

    std::vector<Student> studentVector;
    studentVector.push_back(student1);
    studentVector.push_back(student2);

    if(WriteStudentDetails(studentVector)) {
        std::cout << "Write Operation Completed\n";
    }

    //WriteStudentDetails();
    std::vector<Student> readVector = ReadStudentDetails("studentData.txt");

    std::cout << "Output for Read function:\n";

    for(size_t i{0}; i < readVector.size(); i++) {
        std::cout << readVector.at(i).ToString() << std::endl;
    }

	return 0;
}

bool WriteStudentDetails(std::vector<Student>& data) {
    std::ofstream outFile {"studentData.txt"};

    if(!outFile) {
        std::cerr<< "File could not be opened!\n";
        exit(EXIT_FAILURE);
    }

    std::vector<Module> mod{};

    for(size_t i{0}; i < data.size(); i++) {
        outFile << std::quoted(data.at(i).GetName()) << std::quoted(data.at(i).GetEmail())
            << std::quoted(data.at(i).GetRegistrationID()) << std::quoted(data.at(i).GetCourse())
            << data.at(i).GetYearofStudy() << std::endl;
        outFile << data.at(i).GetModuleSize() << std::endl;

        if(data.at(i).GetModuleSize() > 0) {
            mod = data.at(i).GetModule();

            for(size_t j{0}; j < mod.size(); j++) {
                outFile << std::quoted(mod.at(j).getModuleCode()) << std::quoted(mod.at(j).getModuleTitle()) << mod.at(j).getModuleCreditPoints() << " " << mod.at(j).getModuleMark() << std::endl;
            }
        }
    }

    outFile.close();
    return true;
}

std::vector<Student> ReadStudentDetails(std::string dataFile) {
    std::ifstream inputFile{dataFile};

    if(!inputFile) {
        std::cerr << "File could not be opened!\n";
        exit(EXIT_FAILURE);
    }

    std::vector<Student> student{};
    std::vector<Module> mod{};

    std::string name, email, id, course, code, cTitle;
    int cYear, moduleNo, credit, mark;

    while(inputFile >> std::quoted(name)) {
        inputFile >> std::quoted(email) >> std::quoted(id) >> std::quoted(course) >> cYear;
        inputFile >> moduleNo;

        if(moduleNo > 0) {
            for(int i{0}; i < moduleNo; i++) {
                inputFile >> std::quoted(cTitle) >> std::quoted(code) >> credit >> mark;
                mod.push_back(Module{cTitle, code, credit, mark});
            }
        }

        student.push_back(Student{name, email, id, course, cYear, mod});
        mod.clear();
    }

    inputFile.close();

    return student;
}
