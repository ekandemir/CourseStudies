/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  CivilRegistry.h
//  OOP_HW1

#ifndef CivilRegistry_h
#define CivilRegistry_h
#include <stdio.h>
#include <iostream>
#include <list>
#include "Citizen.h"
class CivilRegistry{
    std::list <Citizen> wApp;
    std::list <Citizen> wOutApp;
public:
    CivilRegistry();
    bool insertCitizen(Citizen*);
    bool removeCitizen(int);
    std::list<Citizen> getter(int);
    ~CivilRegistry();
};

#endif /* CivilRegistry_h */
