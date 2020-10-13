#ifndef ARMOUR_H
#define ARMOUR_H

/*
 * Armour.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"

enum class ArmourType {Helmet, Shield, Gloves, Chest, Leg, Arms};
enum class ArmourMaterial {Steel, Iron, Leather, Wood, Cloth, Paper};

class Armour {
private:
    std::string name_;
    std::string description_;

    int value_;
    int defensiveValue_;
    int weight_;

    bool equipped_;

    ArmourType armourType_;
    ArmourMaterial armourMaterial_;

public:
    // Constructors
    Armour(std::string, std::string, int, int, bool);

    // Setters - strings, ints
    void setName(std::string);
    void setDescription(std::string);
    void setValue(int);
    void setDefensiveValue(int);
    void setWeight(int);
    //void setArmourType(ArmourType);
    //void setArmourMaterial(ArmourMaterial);



    // Getters - strings, ints
    std::string getName() const;
    std::string getDescription() const;
    int getValue() const;
    int getDefensiveValue() const;
    int getWeight() const;
    //ArmourType setArmourType();
    //ArmourMaterial setArmourMaterial();


};

#endif
