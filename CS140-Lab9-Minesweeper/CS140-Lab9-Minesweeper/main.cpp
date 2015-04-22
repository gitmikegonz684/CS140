//
//  main.cpp
//  CS140-Lab9-Minesweeper
//
//  Created by Michael A. Gonzalez on 4/20/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Minesweeper.h"

int main(int argc, const char * argv[]) {
    int size, level;
    Minesweeper m;

    cout<<"What size map?\n";
    cin>>size;
    cout<<"What level difficulty?\n1. Easy\n2. Medium\n3. Hard\n";
    cin>>level;
    
    m.create(size, level);
    m.print();
    //gameplay method takes two numbers. checks booltable for 'true' (aka game over).
    //include a game over method that displays all mine locations
    //if (x,y) coordinates reveal 'false' in booltable begin to CHECK SURROUNDINGS :(
    return 0;
}
