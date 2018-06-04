//
//  Money.hpp
//  HW3
//
//  Created by Erdinc Kandemir on 12.05.2018.

//

#ifndef Money_h
#define Money_h

#include <stdio.h>
class Money {
    int lira;
    int kurus;
public:
    Money();
    Money(int, int);
    Money operator+(const Money&) const;
    Money operator+(int);
    Money operator-(int);
    Money operator=(int);
    bool operator<(int);
    bool operator>(int);
    bool operator==(int);
    int getLira();
    int getKurus();
};



#endif /* Money_h */
