//
//  GenericArray.hpp
//  HW3
//
//  Created by Erdinc Kandemir on 12.05.2018.
//  Copyright © 2018 theorgasination. All rights reserved.
//

#ifndef genericArray_h
#define genericArray_h
#include <stdio.h>
#include "Money.h"

template <class T>
class genericArray {
    int size;
public:
    T* elements;
    //int size;
    genericArray(int);
    T total;
    T sum();
};

template <class T>
genericArray<T>::genericArray(int _size){
    this->size = _size;
    elements = new T[_size];
}
template <>
Money genericArray<Money>::sum(){
    Money tot;
    tot = 0;
    for(int i = 0; i < size ; i++){
        tot = tot + elements[i];
    }
        std::cout<<"Your total amount of money objects array "<< tot.getLira() <<" lira :"<<tot.getKurus()<<"kurus"<<std::endl;
    if(tot>100){
        tot = tot+5;
        std::cout<<"You have won 5 tl bonus, your new amount is "<< tot.getLira() <<" lira :"<<tot.getKurus()<<" kurus"<<std::endl;
    }
    else if(tot<100){
        tot = tot-5;
        if(tot.getLira()<0){
            tot = 0;
            std::cout<<"You have been punished 5 tl , your new amount is 0"<< std::endl;
            
        }
        else{
        std::cout<<"You have been punished 5 tl , your new amount is "<< tot.getLira() <<" lira :"<<tot.getKurus()<<" kurus"<<std::endl;
        }
    }
    else if(tot==100){
        std::cout<<"You still have the same money , your amount is "<< tot.getLira() <<" lira :"<<tot.getKurus()<<" kurus"<<std::endl;
    }
    return tot;
}

template<>
int genericArray<int>::sum(){
    int tot;
    tot = 0;
    for(int i = 0; i < size ; i++){
        tot = tot + elements[i];
    }
    std::cout<<"The total of integer array is "<< tot<<std::endl;
    if(tot>100){
        tot = tot+5;
        std::cout<<"You have won 5 points bonus new total is "<< tot<<std::endl;
    }
    else if(tot<100){
        tot = tot-5;
        std::cout<<"You have lost 5 points new total is "<< tot<<std::endl;
    }
    else if(tot<100){
        std::cout<<"You still have "<< tot<<std::endl;
    }
        
    
    return tot;
}

template<>
double genericArray<double>::sum(){
    double tot;
    tot = 0;
    for(int i = 0; i < size ; i++){
        tot = tot + elements[i];
    }
    std::cout<<"The total of double array is "<< tot<<std::endl;
    if(tot>100){
        tot = tot+5;
        std::cout<<"You have won 5 points bonus new total is "<< tot<<std::endl;
    }
    else if(tot<100){
        tot = tot-5;
        std::cout<<"You have lost 5 points new total is "<< tot<<std::endl;
    }
    else if(tot<100){
        std::cout<<"You still have "<< tot<<std::endl;
    }
    
    
    return tot;
}
#endif /* GenericArray_h */
