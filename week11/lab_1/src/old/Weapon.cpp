/*
 * Weapon.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(std::string itemName, int itemValue, float weight, int strength, int health) : Item{itemName, itemValue, weight}, weaponHitStrength_{strength}, weaponHealth_{health} {}

// Setters and Getters
void Weapon::SetWeaponHitStrength(int strength) {
    weaponHitStrength_ = strength;
}

int Weapon::GetWeaponHitStrength() const {
    return weaponHitStrength_;
}


void Weapon::SetWeaponHealth(int health) {
    weaponHealth_ = health;
}

int Weapon::SetWeaponHealth() const {
    return weaponHealth_;
}

// Utility
std::string Weapon::ToString() {
    std::string strOut{""};
    strOut = strOut + "Weapon: " + Item::ToString() + ", Hit strength: " + std::to_string(weaponHitStrength_) + ", Weapon health: " + std::to_string(weaponHealth_) + "\n";
    return strOut;
}
