#ifndef WEAPON_H
#define WEAPON_H

/*
 * Weapon.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "../inc/common.hpp"
#include "Item.h"

class Weapon : public Item {
private:
    int weaponHitStrength_;
    int weaponHealth_;

public:
    Weapon();
    Weapon(std::string, int, float, int, int);

    // Setters and Getters
    void SetWeaponHitStrength(int);
    int GetWeaponHitStrength() const;

    void SetWeaponHealth(int);
    int SetWeaponHealth() const;

    // Utility
    std::string ToString();
};

#endif
