#include "Person.h"

Person::Person() {}
Person::Person(std::string name, std::string email) :
	name_{ name }, email_{ email } {

}

void Person::SetName(std::string name) {
	name_ = name;
}

std::string Person::GetName() const {
	return name_;
}

void Person::SetEmail(std::string email) {
	email_ = email;
}

std::string Person::GetEmail() const {
	return email_;
}

std::string Person::ToString() {
	return (name_ + " " + email_);
}

