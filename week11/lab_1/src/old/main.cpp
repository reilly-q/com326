//include classes and headers
#include "../inc/common.hpp"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"

int main() {
    Item item("Map", 10, 0.05f);
    std::cout << item.ToString() << std::endl;

    Weapon weapon("Dagger", 10, 0.5f, 100, 100);
    std::cout << weapon.ToString() << std::endl;

    Armour armour("Full body", 50, 5.0f, 100, 100, ArmourType::Steel);
    std::cout << armour.ToString() << std::endl;
}
