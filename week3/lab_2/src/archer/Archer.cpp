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
#include "Archer.h"

// Constructors
Archer::Archer() {
    std::cout << "An archer was just born! Via the default constructor\n";
}

// Utility functions
void Archer::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// Settters - strings, ints, objects
void Archer::setName(std::string nm) {
    name_ = nm;
}

void Archer::setCharType(std::string c) {
    characterType_ = c;
}

void Archer::setHealth(int h) {
    health_ = h;
}

void Archer::setLevel(int l) {
    level_ = l;
}

void Archer::setWeapon(Weapon) {

}

// Getters - strings, ints, objects
std::string Archer::getName() const {
    return name_;
}

std::string Archer::getCharType() const {
    return characterType_;
}

int Archer::getHealth() const {
    return health_;
}

int Archer::getLevel() const {
    return level_;
}

Weapon Archer::getWeapon() const {
    return charWeapon_;
}
