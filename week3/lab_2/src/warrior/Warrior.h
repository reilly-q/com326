#ifndef WARRIOR_H
#define WARRIOR_H

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
#include "../weapon/Weapon.h"

class Warrior {
private:

    // Declare variables - strings, ints, objects
    std::string name_;
    std::string characterType_;

    int health_;
    int level_;

    Weapon charWeapon_;

public:

    // Constructors
    Warrior();

    // Utility functions
    void printStatus();

    // Setters - strings, ints, objects
    void setName(std::string);
    void setCharType(std::string);

    void setHealth(int);
    void setLevel(int);

    void setWeapon(Weapon);

    // Getters - strings, ints, objects
    std::string getName() const;
    std::string getCharType() const;

    int getHealth() const;
    int getLevel() const;

    Weapon getWeapon() const;

};

#endif
