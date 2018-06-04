/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  Citizen.hpp
//  OOP_HW1

#ifndef Citizen_h
#define Citizen_h

#include "Time.h"
#include <stdio.h>
#include <iostream>
#include <string>

class Citizen{
    char *idNo;
    char *name;
    char *surname;
    bool hasApp;
    Time *appTime;
    char *appSlot;
public:
    Citizen(std::string, std::string, std::string, std::string,Time*,std::string);
    Citizen(const Citizen&);
    Time* getAppTime();
    bool get_hasApp();
    std::string get_name();
    bool operator<(const Citizen&) const;
    ~Citizen();
};

#endif /* Citizen_h */
