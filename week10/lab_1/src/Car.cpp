/*
* Car.h
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Class definition .cpp file for the Module Class
* Copyright notice
*/

#include "Car.h"

Car::Car(double gallon) : gallon_{gallon} {

}

void Car::GetCarbonFootPrint() {
    int val = gallon_ * 20.0;
    std::cout << val << " carbon footprint\n";
}
