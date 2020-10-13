#ifndef WIZARD_H
#define WIZARD_H

/*
 * Wizard.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 06 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"
#include "../weapon/Weapon.h"
#include "../item/Item.h"
#include "../armour/Armour.h"

class Wizard {
private:

    // Declare variables - strings, vectors, ints, objects
    std::string name_;
    std::string characterType_;

    std::vector<Item> inventory_;
    std::vector<Armour> armoury_;

    int health_;
    int level_;

    Weapon charWeapon_;

public:

    // Constructors
    Wizard();

    // Utility functions
    void printStatus();

    // This is for Item
    void PickUpItem(Item);
    void DropItem(Item);
    void ListInventory() const;

    // This is for Armour
    void PickUpArmour(Armour);
    void DropArmour(Armour);

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
