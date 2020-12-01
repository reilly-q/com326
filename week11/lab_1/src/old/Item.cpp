/*
 * Item.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "Item.h"

Item::Item() {}

Item::Item(std::string itemName, int itemValue, float weight) : itemName_{itemName}, itemValue_{itemValue}, weight_{weight} {}

// Setters and Getters
void Item::SetItemName(std::string itemName) {
    itemName_ = itemName;
}

std::string Item::GetItemName() const {
    return itemName_;
}


void Item::SetItemValue(int itemValue) {
    itemValue_ = itemValue;
}

int Item::GetItemValue() const {
    return itemValue_;
}


void Item::SetItemWeight(float weight) {
    weight_ = weight;
}

float Item::GetItemWeight() const {
    return weight_;
}

// Utility
std::string Item::ToString() {
    std::string strOut{""};
    strOut = strOut + itemName_ + " worth " + std::to_string(itemValue_) + " Gold coins";
    return strOut;
}
