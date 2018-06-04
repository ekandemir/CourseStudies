/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  Time.cpp
//  OOP_HW1

#include <iostream>
#include <stdlib.h>
#include "Time.h"
using namespace std;
Time::Time(int nday,int nmonth,int nyear,int nhour,int nminute){
    day = nday;
    month = nmonth;
    year = nyear;
    hour = nhour;
    minute = nminute;
}

const char* Time::getTime(){
    string time;
    time.append(to_string(hour));
    time.append(".");
    time.append(to_string(minute));
    time.append(" ");
    time.append(to_string(day));
    time.append("/");
    time.append(to_string(month));
    time.append("/");
    time.append(to_string(year));
    const char *a = time.c_str();
    return a;
}

bool Time::operator<(const Time& cmp) const {
    if (this->year != cmp.year)
        return this->year < cmp.year;
    else if (this->month != cmp.month)
        return this->month < cmp.month;
    else if (this->day != cmp.day)
        return this->day < cmp.day;
    else if (this->hour != cmp.hour)
        return this->hour < cmp.hour;
    else if (this->minute != cmp.minute)
        return this->minute < cmp.minute;
    else
        return false;
}

bool Time::operator>(const Time& cmp) const {
    if (this->year != cmp.year)
        return this->year > cmp.year;
    else if (this->month != cmp.month)
        return this->month > cmp.month;
    else if (this->day != cmp.day)
        return this->day > cmp.day;
    else if (this->hour != cmp.hour)
        return this->hour > cmp.hour;
    else if (this->minute != cmp.minute)
        return this->minute > cmp.minute;
    else
        return false;
}
bool Time::operator==(const Time& cmp) const {
    if (this->year == cmp.year && this->month == cmp.month && this->day == cmp.day && this->hour == cmp.hour && this->minute == cmp.minute)
        return true;
    else
        return false;
}
int Time::getDate(){
    return (year*365)+(month*30)+day;
}
Time:: ~Time(){
    delete this;
}
