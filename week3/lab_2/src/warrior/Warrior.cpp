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
#include "Warrior.h"

// Constructors
Warrior::Warrior() {
    std::cout << "A warrior was just born! Via the default constructor\n";
}

// Utility functions
void Warrior::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// Settters - strings, ints, objects
void Warrior::setName(std::string nm) {
    name_ = nm;
}

void Warrior::setCharType(std::string c) {
    characterType_ = c;
}

void Warrior::setHealth(int h) {
    health_ = h;
}

void Warrior::setLevel(int l) {
    level_ = l;
}

void Warrior::setWeapon(Weapon) {

}

// Getters - strings, ints, objects
std::string Warrior::getName() const {
    return name_;
}

std::string Warrior::getCharType() const {
    return characterType_;
}

int Warrior::getHealth() const {
    return health_;
}

int Warrior::getLevel() const {
    return level_;
}

Weapon Warrior::getWeapon() const {
    return charWeapon_;
}
