//
//  main.cpp
//  HW3
//
//  Created by Erdinc Kandemir on 12.05.2018.
//  Copyright © 2018 theorgasination. All rights reserved.
//

#include <iostream>
#include "Money.h"
#include "genericArray.h"
using namespace std;
int main(int argc, const char * argv[]) {
    try{
        Money d(-3,5);//negative exception
    }catch(const char* result){
        cout<< result<<endl;
    }
    try{
        Money d(3,105);//kurus is greater than 99 exception
    }catch(const char* result){
        cout<< result<<endl;
    }
    Money a(50,0);
    Money b(50,0);
    
    Money c(51,0);
    Money d(50,0);
    
    Money e(49,0);
    Money f(50,0);
    
    genericArray<Money>mEqual(2);
    genericArray<Money>mGreater(2);
    genericArray<Money>mLess(2);
    genericArray<int>mInt(2);
    genericArray<double>mDouble(2);
    
    mEqual.elements[0]=a;
    mEqual.elements[1]=b;
    
    mGreater.elements[0]=c;
    mGreater.elements[1]=d;
    
    mLess.elements[0]=e;
    mLess.elements[1]=f;
    
    
    mInt.elements[0]=30;
    mInt.elements[1]=20;
    
    mDouble.elements[0]= 90.1;
    mDouble.elements[1]= 20.5;
    
    mEqual.total = mEqual.sum();
    mGreater.total = mGreater.sum();
    mLess.total = mLess.sum();
    mInt.total = mInt.sum();
    mDouble.total = mDouble.sum();

    return 0;
}
