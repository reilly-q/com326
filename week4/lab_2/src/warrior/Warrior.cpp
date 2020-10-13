/*
 * Warrior.cpp
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

    //(std::string nm, std::string des, int val, int defVal, bool eq)
    Armour a1{"coin", "protects against 1 damage", 1, 1, 1};
    armoury_.push_back(a1);
}

// Utility functions
void Warrior::printStatus() {
    std::cout << name_ << " is the " << characterType_ << " and currently is at " << health_ << " health." << std::endl;
}

// This is for Item
void Warrior::PickUpItem(Item item) {
    inventory_.push_back(item);
}

void Warrior::DropItem(Item item) {
    for(int i = 0; i < inventory_.size(); i++) {
        if(inventory_.at(i).getName() == item.getName()) {
            inventory_.erase(inventory_.begin() + i);
        }
    }
}

void Warrior::ListInventory() const {
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
void Warrior::PickUpArmour(Armour armour) {
    armoury_.push_back(armour);
}

void Warrior::DropArmour(Armour armour) {
    for(int i = 0; i < armoury_.size(); i++) {
        if(armoury_.at(i).getName() == armour.getName()) {
            armoury_.erase(armoury_.begin() + i);
        }
    }
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
