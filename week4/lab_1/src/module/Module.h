#ifndef COURSE_H
#define COURSE_H

/*
 * Module.h
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 13 oct 2020
 *
 * Copyright notice
 */


#include "../../inc/common.h"

class Module {
private:
    std::string moduleTitle_;
    std::string moduleCode_;

    int moduleCredit_;
    int moduleMark_;

public:
    // Constructos
    Module();
    Module(std::string, std::string, int, int);

    // Setters - string, int
    void setModuleTitle(std::string);
    void setModuleCode(std::string);
    void setModuleCredit(int);
    void setModuleMark(int);

    // Getters - string, int
    std::string getModuleTitle() const;
    std::string getModuleCode() const;
    int getModuleCredit() const;
    int getModuleMark() const;
};

#endif
