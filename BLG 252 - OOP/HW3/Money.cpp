//
//  Money.cpp
//  HW3
//
//  Created by Erdinc Kandemir on 12.05.2018.

//

#include "Money.h"

Money::Money(int l , int k){
    if(l<0 || k<0)throw "The amount of Money can not be below zero";
    if(k>99)throw "The kurus amount of Money can not be more than 99";
    lira = l;
    kurus = k;
}
Money::Money(){
    lira = 0;
    kurus = 0;
}
Money Money:: operator+(const Money& a) const{
    int nlira = this->lira + a.lira + ((this->kurus + a.kurus)/100);
    int nkurus = (this->kurus + a.kurus)/100;
    return Money(nlira,nkurus);
}
Money Money:: operator+(int a){
    this->lira = lira+a;
    return *this;
}
Money Money:: operator-(int a){
    this->lira = lira-a;
    return *this;
}
Money Money:: operator=(int a) {
    lira=a;
    kurus = 0;
    return *this;

}
bool Money:: operator<(int a) {
    return (lira < a);
}
bool Money:: operator>(int a) {
    return (lira > a || (lira == a && kurus > 0));
}
bool Money:: operator==(int a) {
    return (lira == a && kurus == 0);
}
int Money::getLira(){return lira;}
int Money::getKurus(){return kurus;}
