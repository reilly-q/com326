#pragma once
#include "Person.h"
#include "Module.h"
#include <vector>

class Lecturer :
	public Person
{
private:
	std::string staffId_;
	std::string subjectArea_;
	std::vector<Module> modules_;

public:
	Lecturer();
	Lecturer(std::string name, std::string email, std::string staffId, std::string subjectArea, std::vector<Module> m);

	void SetStaffId(std::string staffId);
	std::string GetStaffId() const;

	void SetSubjectArea(std::string subjectArea);
	std::string GetSubjectArea() const;

	void SetModules(std::vector<Module> m);
	std::vector<Module> GetModules() const;

	virtual std::string ToString() override;
};

