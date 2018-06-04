//
//  main.cpp
//  DataStrHomework1
//
//  Created by Developing on 3.10.2017.
//  Copyright © 2017 erdinckandemir. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    //memory allocation for puzzle array
    char ** puzzleArray = new char*[225];
    for (int i=0; i < 15 ; i++) {
        puzzleArray[i] = new char[15];
    }
    puzzleArray[3][5] = 'a';
    cout << puzzleArray[3][5];
    
    
    
    //open puzzle.txt to read
    ifstream puzzle;
    puzzle.open("puzzle.txt");
    
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            puzzle >> *(*(puzzleArray+i)+j);
            
        }
    }
    cout<<puzzleArray[2][2];
    getchar();
    return 0;
    
    
    
}
