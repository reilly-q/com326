#ifndef ITEM_H
#define ITEM_H

/*
 * Item.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"

class Item {
private:
    std::string name_;
    std::string description_;

    int value_;

public:
    // Constructors
    Item();

    // Setters - strings, ints
    void setName(std::string);
    void setDescription(std::string);
    void setValue(int);

    // Getters - strings, ints
    std::string getName() const;
    std::string getDescription() const;
    int getValue() const;


};

#endif
