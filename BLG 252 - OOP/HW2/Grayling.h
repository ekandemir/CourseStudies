//
//  Grayling.h
//  HW2
//
//

#ifndef Grayling_h
#define Grayling_h

class Grayling{
protected:
    short age;
    std::string name;
    char gender;
    bool alive;
    bool mutant;
    std::string mutatedTo;
    double mpi;
    double mp;
    double mutateAt;
public:
    Grayling();
    Grayling(char, std::string, double, double);
    Grayling(const Grayling&,char,std::string);
    virtual void print();
    virtual void givebirth();
    virtual void aging();
    
};
class Grayling1 : public Grayling{
public:
    Grayling1();
    Grayling1(char , std::string);
    Grayling1(const Grayling1&,char,std::string);
    void print();
    void aging();
    void givebirth();
};
class Grayling2 : public Grayling{
public:
    Grayling2();
    Grayling2(char gender, std::string name);
    Grayling2(const Grayling2&,char,std::string);
    void print();
    void aging();
    void givebirth();
};
class Grayling3 : public Grayling{
public:
    Grayling3();
    Grayling3(char gender, std::string name);
    Grayling3(const Grayling3&,char,std::string);
    void print();
    void aging();
    void givebirth();
};
#endif /* Grayling_h */
