//
//  Grayling.cpp
//  HW2
//
//  Created by Erdinc Kandemir on 21.04.2018.
//  Copyright © 2018 theorgasination. All rights reserved.
//
#include<iostream>
#include "Grayling.h"

//constructors
//default
Grayling::Grayling(){
    alive = false;
}
Grayling1::Grayling1():Grayling(){}
Grayling2::Grayling2():Grayling(){}
Grayling3::Grayling3():Grayling(){}

//consts
Grayling::Grayling(char gender, std::string name, double mpi, double mutateAt){
    this->name = name;
    this->gender = gender;
    this->age = 0;
    this->alive = true;
    this->mutant = false;
    this->mutatedTo = "";
    this->mpi = mpi;
    this->mp = 0;
    this->mutateAt = mutateAt;
}
Grayling1::Grayling1(char gender, std::string name):Grayling(gender,name,30,60){}
Grayling2::Grayling2(char gender, std::string name):Grayling(gender,name,40,80){}
Grayling3::Grayling3(char gender, std::string name):Grayling(gender,name,50,100){}

//copy consts
Grayling::Grayling(const Grayling& tocpy,char gender,std::string name){
    this->name = name;
    this->gender = gender;
    this->age = tocpy.age;
    this->alive = tocpy.alive;
    this->mutant = tocpy.mutant;
    this->mutatedTo = tocpy.mutatedTo;
    this->mpi = tocpy.mpi;
    this->mp = tocpy.mp;
    this->mutateAt = tocpy.mutateAt;
}
Grayling1::Grayling1(const Grayling1& tocpy,char gender,std::string name):Grayling(tocpy,gender,name){}
Grayling2::Grayling2(const Grayling2& tocpy,char gender,std::string name):Grayling(tocpy,gender,name){}
Grayling3::Grayling3(const Grayling3& tocpy,char gender,std::string name):Grayling(tocpy,gender,name){}

//print funcs
void Grayling::print(){
    std::cout<<"Age: "<<age<<" Nname: "<<name<<" G: "<<gender<<" MPI: "<<mpi<<" MP"<<" Mutate at: "<<mutateAt<<std::endl;
}
void Grayling1::print(){
    std:: cout<<"- Grayling 1 -> ";
    Grayling::print();
    
}
void Grayling2::print(){
    std:: cout<<"- Grayling 2 -> ";
    Grayling::print();
}
void Grayling3::print(){
    std:: cout<<"- Grayling 3 -> ";
    Grayling::print();
}

//aging funcs
void Grayling::aging(){
    age++;
    mp=mp+mpi;
}
void Grayling1::aging(){
    
    Grayling::aging();
    
    if(alive){
        if(age == 4){//4 because there is no possiblity to die before mutation and grayling-2 death year is 4
            //dead
            alive = false;
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
            std::cout<<"- "<< name<<" is dead because of AGING!"<<std::endl;
        }
        else if(mutant && mp >= 100){
           
                //dead
                alive = false;
                std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
                std::cout<<"- "<< name<<" is dead because of HIGH MUTATION RATE!"<<std::endl;
            
        }
        else{
            //live
            if(mp >= mutateAt && !mutant){
                //mutate
                std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
                mutatedTo="Grayling2";
                mutant = true;
                mp = 0;
                mpi = 40;
                std::cout<<"- Mutated TO: "<<mutatedTo<<std::endl;
            }
            else{
                std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
                
            }
        }
    }
    else{
        std::cout<<"Trying to AGING BUT "<<name<<" is not alive"<<std::endl;
    }
}
void Grayling2::aging(){
    Grayling::aging();
    if(alive){
        if(age == 3){//3 because there is no possiblity to die before mutation and grayling-3 death year is 3
            //dead
            alive = false;
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
            std::cout<<"- "<< name<<" is dead because of AGING!"<<std::endl;
        }
        else if(mutant && mp >= 100){
            
            //dead
            alive = false;
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
            std::cout<<"- "<< name<<" is dead because of HIGH MUTATION RATE!"<<std::endl;
            
        }
        
        else{
            //live
            if(mp >= mutateAt){
                //mutate
                std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
                mutatedTo="Grayling3";
                mutant = true;
                mp = 0;
                mpi=50;
                std::cout<<"- Mutated TO: "<<mutatedTo<<std::endl;
            }
            else{
                std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
                
            }
        }
    }
    else{
        std::cout<<"_ Trying to AGING BUT "<<name<<" is not alive"<<std::endl;
    }
}
void Grayling3::aging(){
    Grayling::aging();
    if(alive){
        if(age == 3){
            //dead
            alive = false;
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
            std::cout<<"- "<< name<<" is dead because of AGING!"<<std::endl;
        }
        else if(mp >= 100 && !mutant){
            //dead
            alive = false;
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
            std::cout<<"- "<< name<<" is dead because of HIGH MUTATION RATE!"<<std::endl;
        }
        else{
            //live
            std::cout<<"- AGING name: "<<name<<"-> "<<mutatedTo<<" Age: "<<age<<" MPI: "<< mpi <<" MP "<< mp << std::endl;
        }
    }
    else{
        std::cout<<"_ Trying to AGING BUT "<<name<<" is not alive"<<std::endl;
    }
}

//givingbirth functions
void Grayling::givebirth(){
    
}
void Grayling1::givebirth(){
    if(!alive){
        if(gender == 'm'){
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive and male!"<<std::endl;
        }
        else{
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive!"<<std::endl;
        }
    }
    else if(gender == 'm'){
        std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is male!"<<std::endl;
        
    }
    else{
        std::cout<<"_ "<<name<<" is gave birth to 2 offspring!"<<std::endl;
    }
}
void Grayling2::givebirth(){
    if(!alive){
        if(gender == 'm'){
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive and male!"<<std::endl;
        }
        else{
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive!"<<std::endl;
        }
    }
    else if(gender == 'm'){
        std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is male!"<<std::endl;
        
    }
    else{
        std::cout<<"_ "<<name<<" is gave birth to 1 offspring!"<<std::endl;
    }
}

void Grayling3::givebirth(){
    if(!alive){
        if(gender == 'm'){
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive and male and No abbility to give birth!"<<std::endl;
        }
        else{
            std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is not alive and No abbility to give birth!"<<std::endl;
        }
    }
    else if(gender == 'm'){
        std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" is male and No abbility to give birth!"<<std::endl;
        
    }
    else{
        alive = false;//die try to give birth
        std::cout<<"_ Trying to GIVE BIRTH BUT "<<name<<" died because No ability to give birth!"<<std::endl;
    }
}

