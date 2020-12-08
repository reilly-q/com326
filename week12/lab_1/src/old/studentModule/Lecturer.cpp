#include "Lecturer.h"

Lecturer::Lecturer() {}

Lecturer::Lecturer(std::string name, std::string email, std::string staffId, std::string subjectArea, std::vector<Module> m) :
	Person(name, email), staffId_{ staffId }, subjectArea_{ subjectArea }, modules_{ m } {

}

void Lecturer::SetStaffId(std::string staffId) {
	staffId_ = staffId;
}

std::string Lecturer::GetStaffId() const {
	return staffId_;
}

void Lecturer::SetSubjectArea(std::string subjectArea) {
	subjectArea_ = subjectArea;
}

std::string Lecturer::GetSubjectArea() const {
	return subjectArea_;
}

void Lecturer::SetModules(std::vector<Module> m) {
	modules_ = m;
}

std::vector<Module> Lecturer::GetModules() const {
	return modules_;
}

std::string Lecturer::ToString() {
	std::string strTmp{};
	strTmp.append("Lecturer: " + Person::ToString() + "\nSubject Area: " + subjectArea_ + "\n");
	strTmp.append("\nModules: \n");
	for (int index = 0; index < modules_.size(); index++) {
		strTmp.append(modules_.at(index).getModuleTitle());
		strTmp.append("\n");
	}
	return strTmp;
}
