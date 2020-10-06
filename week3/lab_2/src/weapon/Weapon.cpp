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
#include "Weapon.h"

// Constructors
Weapon::Weapon() {
    std::cout << "An awesome weapon has once more been crafted by master blacksmith Shane\n";
};

// Setters - strings, ints
void Weapon::setType(std::string t) {
    type_ = t;
};

void Weapon::setDamage(int d) {
    damage_ = d;
};

void Weapon::setLevel(int l) {
    level_ = l;
};

// Getters - strings, ints
std::string Weapon::getType() const {
    return type_;
};

int Weapon::getDamage() const {
    return damage_;
};

int Weapon::getLevel() const {
    return level_;
};
