#ifndef WEAPON_H
#define WEAPON_H

/*
 * Weapon.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"

class Weapon {
private:

    // Declare variables - strings, ints
    std::string type_;

    int damage_;
    int level_;

public:

    // Constructors
    Weapon();

    // Setters - strings, ints
    void setType(std::string);

    void setDamage(int);
    void setLevel(int);

    // Getters - strings, ints
    std::string getType() const;

    int getDamage() const;
    int getLevel() const;

};

#endif
