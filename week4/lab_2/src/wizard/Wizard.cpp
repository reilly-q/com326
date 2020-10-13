/*
 * Wizzard.cpp
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

    //(std::string nm, std::string des, int val, int defVal, bool eq)
    Armour a1{"coin", "protects against 1 damage", 1, 1, 1};
    armoury_.push_back(a1);
}

// Utility functions
void Wizard::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// This is for Item
void Wizard::PickUpItem(Item item) {
    inventory_.push_back(item);
}

void Wizard::DropItem(Item item) {
    for(int i = 0; i < inventory_.size(); i++) {
        if(inventory_.at(i).getName() == item.getName()) {
            inventory_.erase(inventory_.begin() + i);
        }
    }
}

void Wizard::ListInventory() const {
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
void Wizard::PickUpArmour(Armour armour) {
    armoury_.push_back(armour);
}

void Wizard::DropArmour(Armour armour) {
    for(int i = 0; i < armoury_.size(); i++) {
        if(armoury_.at(i).getName() == armour.getName()) {
            armoury_.erase(armoury_.begin() + i);
        }
    }
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
