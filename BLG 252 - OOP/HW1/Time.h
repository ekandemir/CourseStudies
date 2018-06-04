/****************************
 *  Erdinç Kandemir         *
 *  150150110               *
 *  CRN:21520               *
 *                          *
 ****************************/
//
//  Time.h
//  OOP_HW1
#ifndef Time_h
#define Time_h
class Time{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    public:
    Time(int, int, int, int, int);
    const char* getTime();
    int getDate();
    bool operator>(const Time&) const;
    bool operator<(const Time&) const;
    bool operator==(const Time&) const;
    ~Time();
};

#endif /* Time_h */
