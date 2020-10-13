/*
 * Armour.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "Armour.h"

// Constructors
Armour::Armour(std::string nm, std::string des, int val, int defVal, bool eq) {
    name_ = nm;
    description_ = des;
    value_ = val;
    defensiveValue_ = defVal;
    equipped_ = eq;
}


// Setters - strings, ints
void Armour::setName(std::string) {

}

void Armour::setDescription(std::string) {

}

void Armour::setValue(int) {

}

void Armour::setDefensiveValue(int) {

}

void Armour::setWeight(int) {

}

//void setArmourType(ArmourType);
//void setArmourMaterial(ArmourMaterial);



// Getters - strings, ints
std::string Armour::getName() const {
    return name_;
}

std::string Armour::getDescription() const {
    return description_;
}

int Armour::getValue() const {
    return value_;
}

int Armour::getDefensiveValue() const {
    return defensiveValue_;
}

int Armour::getWeight() const {
    return weight_;
}

//ArmourType setArmourType();
//ArmourMaterial setArmourMaterial();
