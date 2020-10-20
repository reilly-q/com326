/*
 * Module.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../../inc/common.h"
#include "Module.h"

// Constructos
Module::Module() {

}

Module::Module(std::string mt, std::string mc, int mcr, int mm) {
    moduleTitle_ = mt;
    moduleCode_ = mc;

    moduleCredit_ = mcr;
    moduleMark_ = mm;
}

// Setters - string, int
void Module::setModuleTitle(std::string mt) {
    moduleTitle_ = mt;
}

void Module::setModuleCode(std::string mc) {
    moduleCode_ = mc;
}

void Module::setModuleCredit(int mcr) {
    moduleCredit_ = mcr;
}

void Module::setModuleMark(int mm) {
    moduleMark_ = mm;
}

// Setters - string, int
std::string Module::getModuleTitle() const {
    return moduleTitle_;
}

std::string Module::getModuleCode() const {
    return moduleCode_;
}

int Module::getModuleCredit() const {
    return moduleCredit_;
}

int Module::getModuleMark() const {
    return moduleMark_;
}
