/*
 * Armour.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "Armour.h"

Armour::Armour() {}

Armour::Armour(std::string itemName, int itemValue, float weight, int defence, int health, ArmourType armourType) : Item{itemName, itemValue, weight}, defence_{defence}, armourHealth_{health}, armourType_{armourType} {}

// Setters and Getters
void Armour::SetArmourDefence(int defence) {
    defence_ = defence;
}

int Armour::GetArmourDefence() const {
    return defence_;
}

void Armour::SetArmourHealth(int health) {
    armourHealth_ = health;
}

int Armour::GetArmourHealth() const {
    return armourHealth_;
}

void Armour::SetArmourType(ArmourType armourType) {
    armourType_ = armourType;
}

ArmourType Armour::GetArmourType() const {
    return armourType_;
}


// Utility
std::string Armour::ToString() {
    std::string strOut{""};
    strOut = strOut + "Armour: " + Item::ToString() + ", Defence: " + std::to_string(defence_) + ", Armour health: " + std::to_string(armourHealth_) + " Armour Material: ";
    switch(armourType_) {
        case ArmourType::Cardboard:
            strOut += "Cardboard\n";
            break;
        case ArmourType::Leather:
            strOut += "Leather\n";
            break;
        case ArmourType::Wood:
            strOut += "Wood\n";
            break;
        case ArmourType::Iron:
            strOut += "Iron\n";
            break;
        case ArmourType::Steel:
            strOut += "Steel\n";
            break;
    }

    return strOut;
}
