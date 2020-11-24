/*
* Building.cpp
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Class definition .cpp file for the Module Class
* Copyright notice
*/

#include "Building.h"

Building::Building(int squarefeet) : squareFeet_{squarefeet} {

}

void Building::GetCarbonFootPrint() {
    int val = squareFeet_ * (50 + 20 + 47 + 17);
    std::cout << val << " carbon footprint\n";
}
