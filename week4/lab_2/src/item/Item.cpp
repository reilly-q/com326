/*
 * Item.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "Item.h"

// Constructors
Item::Item(){

}

// Setters - strings, ints
void Item::setName(std::string) {

}

void Item::setDescription(std::string) {

}

void Item::setValue(int) {

}


// Getters - strings, ints
std::string Item::getName() const {
    return name_;
}

std::string Item::getDescription() const {
    return description_;
}

int Item::getValue() const {
    return value_;
}
