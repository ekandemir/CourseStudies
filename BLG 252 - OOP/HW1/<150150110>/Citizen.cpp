/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  Citizen.cpp
//  OOP_HW1

#include "Citizen.h"
#include <iostream>
#include <string>
#include <cstring>
Citizen::Citizen(std::string nidNo,std::string nname, std::string nsurname,std::string nhasApp,Time* nappTime,std::string nappSlot){
    idNo = new char[nidNo.length() + 1]; strcpy(idNo, nidNo.c_str());
    name = new char[nname.length() + 1]; strcpy(name, nname.c_str());
    surname = new char[nsurname.length() + 1]; strcpy(surname, nsurname.c_str());
    hasApp = nhasApp.compare("TRUE") == 0;
    appTime = nappTime;
    appSlot = new char[nappSlot.length() + 1]; strcpy(appSlot, nappSlot.c_str());
}
Citizen::Citizen(const Citizen &toCpy){
    idNo = new char[strlen(toCpy.idNo) + 1];
    strcpy(idNo, toCpy.idNo);
    name = new char[strlen(toCpy.name) + 1]; strcpy(name, toCpy.name);
    surname = new char[strlen(toCpy.surname) + 1]; strcpy(surname, toCpy.surname);
    hasApp = toCpy.hasApp;
    appTime = toCpy.appTime;
    appSlot = new char[strlen(toCpy.appSlot) + 1]; strcpy(appSlot, toCpy.appSlot);
}
std::string Citizen::get_name(){
    return name;
}
Time* Citizen::getAppTime(){
    return appTime;
}

bool Citizen::get_hasApp(){
    return hasApp;
}
bool Citizen::operator<(const Citizen &toCmp) const{
    if(toCmp.hasApp){
        if(this->appTime->getDate()==toCmp.appTime->getDate()){
            if(strlen(this->appSlot)==strlen(toCmp.appSlot)){
                if(strcmp(this->appSlot,toCmp.appSlot)==0){
                    return (*(this->appTime) < *(toCmp.appTime));
                }
                else{
                    return (strcmp(this->appSlot,toCmp.appSlot) < 0);
                }
                
            }
            else{
                return strlen(this->appSlot)<strlen(toCmp.appSlot);
            }
        }
        else{
            return (this->appTime->getDate()<toCmp.appTime->getDate());
        }
    }
    else{
        if(*(this->appTime) < *(toCmp.appTime)){
            return true;
        }
        else{
            return false;
        }
    }
}
Citizen::~Citizen(){
    delete this->idNo;
    delete this->name;
    delete this->surname;
    delete this->appSlot;
}
