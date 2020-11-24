/*
* Car.h
*
* Version information v0.1
* Author: Dr.Shane Wilson & Dr.Effirul Ramlan
* Date : 8 / 10 / 2017 || Modified : 29 / 09 / 2019
* Description: Header file for Module class
* Copyright notice
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "CarbonFootPrint.h"

// Task 1 Module Class declaration
class Car : public CarbonFootPrint
{
private:
	double gallon_;

public:
	Car(double gallon);

	virtual void GetCarbonFootPrint() override;
};
