/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "Wizard.h"

// Constructors
Wizard::Wizard() {
    std::cout << "A wizard was just born! Via the default constructor\n";
}

// Utility functions
void Wizard::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// Settters - strings, ints, objects
void Wizard::setName(std::string nm) {
    name_ = nm;
}

void Wizard::setCharType(std::string c) {
    characterType_ = c;
}

void Wizard::setHealth(int h) {
    health_ = h;
}

void Wizard::setLevel(int l) {
    level_ = l;
}

void Wizard::setWeapon(Weapon) {

}

// Getters - strings, ints, objects
std::string Wizard::getName() const {
    return name_;
}

std::string Wizard::getCharType() const {
    return characterType_;
}

int Wizard::getHealth() const {
    return health_;
}

int Wizard::getLevel() const {
    return level_;
}

Weapon Wizard::getWeapon() const {
    return charWeapon_;
}
