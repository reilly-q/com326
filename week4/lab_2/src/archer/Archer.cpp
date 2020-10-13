/*
 * Archer.cpp
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

    //(std::string nm, std::string des, int val, int defVal, bool eq)
    Armour a1{"coin", "protects against 1 damage", 1, 1, 1};
    armoury_.push_back(a1);
}

// Utility functions
void Archer::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// This is for Item
void Archer::PickUpItem(Item item) {
    inventory_.push_back(item);
}

void Archer::DropItem(Item item) {
    for(int i = 0; i < inventory_.size(); i++) {
        if(inventory_.at(i).getName() == item.getName()) {
            inventory_.erase(inventory_.begin() + i);
        }
    }
}

void Archer::ListInventory() const {
    std::cout << "The archer is carrying: \n";
    std::cout << "Weapon: " << charWeapon_.getType() << " level: " << charWeapon_.getLevel() << " with damage: " << charWeapon_.getDamage();
    std::cout << "Equipped with armour:\n";
    for(int i = 0; i < armoury_.size(); i++) {
        std::cout << armoury_.at(i).getName() << std::endl;
        std::cout << armoury_.at(i).getDescription() << std::endl;
        std::cout << armoury_.at(i).getValue() << std::endl;
    }

    for(int i = 0; i < inventory_.size(); i++) {
        std::cout << inventory_.at(i).getName() << std::endl;
        std::cout << inventory_.at(i).getDescription() << std::endl;
        std::cout << inventory_.at(i).getValue() << std::endl;
    }
}

// This is for Armour
void Archer::PickUpArmour(Armour armour) {
    armoury_.push_back(armour);
}

void Archer::DropArmour(Armour armour) {
    for(int i = 0; i < armoury_.size(); i++) {
        if(armoury_.at(i).getName() == armour.getName()) {
            armoury_.erase(armoury_.begin() + i);
        }
    }
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
