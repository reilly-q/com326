#ifndef ITEM_H
#define ITEM_H

/*
 * Item.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 17 nov 2020
 *
 * Copyright notice
 */

#include "../inc/common.hpp"

class Item {
private:
    std::string itemName_;
    int itemValue_;
    float weight_;

public:
    Item();
    Item(std::string, int, float);

    // Setters and Getters
    void SetItemName(std::string);
    std::string GetItemName() const;

    void SetItemValue(int);
    int GetItemValue() const;

    void SetItemWeight(float);
    float GetItemWeight() const;

    // Utility
    std::string ToString();
};

#endif
