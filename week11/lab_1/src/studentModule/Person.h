#pragma once
#include <iostream>

class Person
{
private:
	std::string name_;
	std::string email_;

public:
	Person();
	Person(std::string name, std::string email);

	void SetName(std::string name);
	std::string GetName() const;

	void SetEmail(std::string email);
	std::string GetEmail() const;

	virtual std::string ToString();
};

