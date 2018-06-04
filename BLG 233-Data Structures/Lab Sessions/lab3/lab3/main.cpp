//
//  main.cpp
//  lab3
//
//  Created by Developing on 4.10.2017.
//  Copyright © 2017 erdinckandemir. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;



struct person{

    char name[100];
    char number[20];



};
person **personArray;
void add(int a){
    *(personArray+a) = new person;
    char name[15];
    
    cin>> name;
    strcpy(*(*(personArray+a))->name,name);
    cin>> *(*(personArray+a))->number;


}

int main(int argc, const char * argv[]) {
    int count = 0;
    int temp=0;
    int operation = 0;
    
    
    
    cin>>operation;
    switch (operation) {
        case 1://add
            
            add(count);
            count++;
            //add func
            break;
            
        case 2://remove
            
            //a
            break;
        case 3://list
            for (int i = 0; i < count; i++) {
                cout<< *(*(personArray+i))->name;
                cout<< *(*(personArray+i))->number;
            }
            //
            break;
            
        default:
            break;
    }
    
    
    
    return 0;
}
