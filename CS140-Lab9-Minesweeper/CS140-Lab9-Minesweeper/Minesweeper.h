//
//  Minesweeper.h
//  CS140-Lab9-Minesweeper
//
//  Created by Michael A. Gonzalez on 4/21/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#ifndef __CS140_Lab9_Minesweeper__Minesweeper__
#define __CS140_Lab9_Minesweeper__Minesweeper__

#include <stdio.h>
using namespace std;
#include <string>
#include <vector>

class Minesweeper {
    
public:
    
    int usrSize, usrLevel, minesCount;
    vector< vector<string> > row;
    vector< vector<bool> > boolfield;
    
    void create(int size, int level);
    void print();
    bool checkGameOver(int x, int y);
    void checkSurround(int x, int y);
    bool checkWin();
};

#endif /* defined(__CS140_Lab9_Minesweeper__Minesweeper__) */
