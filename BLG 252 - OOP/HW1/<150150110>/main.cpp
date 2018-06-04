/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  main.cpp
//  OOP_HW1

#include <iostream>
#include <fstream>
#include "CivilRegistry.h"
#include "Citizen.h"
#include "Time.h"
using namespace std;
int main(){
    
    ifstream file;
    file.open("input.txt");
    string idNo,name,surname,hasApp,appSlot,toAvoid;
    int year,month,day,hour,minute;
    char a;
    CivilRegistry lists;
    
    getline(file, toAvoid);
    
    while (!file.eof()) {
        file>>idNo>>name>>surname>>hasApp>>day>>a>>month>>a>>year>>appSlot>>hour>>a>>minute;
        Time *myTime =new Time(day,month,year,hour,minute);
        Citizen myCitizen(idNo , name , surname,hasApp,myTime,appSlot);
        lists.insertCitizen(&myCitizen);
    }
    list <Citizen> wApp;
    list <Citizen> wOutApp;
    wApp = lists.getter(1);
    wOutApp = lists.getter(2);
    wApp.sort();
    wOutApp.sort();
    
    cout<<"Citizens with an appointment:"<<endl;
    while(!wApp.empty()){
        cout<<wApp.front().get_name()<<endl;
        wApp.pop_front();
    }
    cout<<endl<<"Citizens without an appointment:"<<endl;
    while(!wOutApp.empty()){
        cout<<wOutApp.front().get_name()<<endl;
        wOutApp.pop_front();
    }
    file.close();
    return 0;
}
