#ifndef ARCHER_H
#define ARCHER_H

/*
 * common.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"
#include "../weapon/Weapon.h"

class Archer {
private:

    // Declare variables - strings, ints, objects
    std::string name_;
    std::string characterType_;

    int health_;
    int level_;

    Weapon charWeapon_;

public:

    // Constructors
    Archer();

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
