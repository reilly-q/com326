#ifndef ARMOUR_H
#define ARMOUR_H

/*
 * Armour.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "../inc/common.hpp"
#include "Item.h"

enum class ArmourType{Cardboard, Leather, Wood, Iron, Steel};

class Armour : public Item {
private:
    int defence_;
    int armourHealth_;
    ArmourType armourType_;

public:
    Armour();
    Armour(std::string, int, float, int, int, ArmourType);

    // Setters and Getters
    void SetArmourDefence(int);
    int GetArmourDefence() const;

    void SetArmourHealth(int);
    int GetArmourHealth() const;

    void SetArmourType(ArmourType);
    ArmourType GetArmourType() const;

    // Utility
    std::string ToString();
};

#endif
