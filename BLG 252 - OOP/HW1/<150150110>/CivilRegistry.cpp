/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  CivilRegistry.cpp
//  OOP_HW1

#include "CivilRegistry.h"

CivilRegistry::CivilRegistry(){
    
}
bool CivilRegistry::insertCitizen(Citizen *citizen){
    if(citizen->get_hasApp()){
        wApp.push_front(*citizen);
        return true;
    }
    else{wOutApp.push_front(*citizen);
        return true;
    }
    return false;
}
bool CivilRegistry::removeCitizen(int listNo){
    if(listNo==1){
        wApp.pop_front();
        return true;
    }
    else{
        wOutApp.pop_front();
        return true;
    }
    return false;
}

std::list<Citizen> CivilRegistry::getter(int list){
    
    if(list == 1){
        return wApp;
        
    }
    else{
        return wOutApp;
    }
    
}
CivilRegistry::~CivilRegistry(){
    while(!wApp.empty()){
        wApp.pop_front();
    }
    while(!wOutApp.empty()){
        wOutApp.pop_front();
    }
}
