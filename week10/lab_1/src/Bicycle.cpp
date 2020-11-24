/*
* Bicycle.cpp
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Class definition .cpp file for the Module Class
* Copyright notice
*/

#include "Bicycle.h"

Bicycle::Bicycle(std::string type) : type_{type} {

}

void Bicycle::GetCarbonFootPrint() {
    std::cout << "0 carbon footprint\n";
}
