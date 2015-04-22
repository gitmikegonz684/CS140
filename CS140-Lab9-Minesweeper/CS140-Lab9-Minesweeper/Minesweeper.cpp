//
//  Minesweeper.cpp
//  CS140-Lab9-Minesweeper
//
//  Created by Michael A. Gonzalez on 4/21/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include "Minesweeper.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <time.h>
using namespace std;

void Minesweeper::create(int size, int level){
    usrSize=size;
    usrLevel=level;
    srand(time(NULL));
    
    //Create the minefield to be displayed
    for (int i=0; i<size; i++) {
        vector<string> col(size);
        row.push_back(col);
    }

    //Create the boolean minefield (not displayed)
    for (int i=0; i<size; i++) {
        vector<bool> boolfieldCol(size);
        boolfield.push_back(boolfieldCol);
    }
    
    //Switch statement places mines on random (x,y) coordinates of boolean field
    int xMines; //Target # of mines

    switch (level) {
        case 1://easy
            xMines=((size*size)/6)+2;
            for (int i=0; i<xMines; i++) {
                int randmX=(rand()%size+0);
                int randmY=(rand()%size+0);
                boolfield[randmX][randmY]=true;
            }
            break;
        case 2://medium
            xMines=((size*size)/3)+3;
            for (int i=0; i<xMines; i++) {
                int randmX=(rand()%size+0);
                int randmY=(rand()%size+0);
                boolfield[randmX][randmY]=true;
            }
            break;
        case 3://hard
            xMines=((size*size)/2)+6;
            for (int i=0; i<xMines; i++) {
                int randmX=(rand()%size+0);
                int randmY=(rand()%size+0);
                boolfield[randmX][randmY]=true;
            }
            break;
        default:
            break;
    }
    
    //Determine # of mines generated and populate minefiled for display
    minesCount=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (boolfield[i][j]) {
                minesCount++;
                row[i][j]="⎕";
            } else {
                row[i][j]="⎕";
            }
        }
    }
    
}

void Minesweeper::print(){
    //Print column header
    cout<<"\nMines left: "<<minesCount<<"\n\n";
    cout<<" \t";
    for (int i=1; i<usrSize+1; i++) {
        cout<<i<<"\t";
    }
    cout<<"\n\n";
    
    //Print rows with headers and footers
    for (int i=0; i<usrSize; i++) {
        cout<<i+1<<"\t";
        for (int j=0; j<usrSize; j++) {
            cout<<row[i][j];
            cout<<"\t";
        }
        cout<<i+1<<"\n\n";
    }
    
    //Print column footer
    cout<<" \t";
    for (int i=1; i<usrSize+1; i++) {
        cout<<i<<"\t";
    }
    cout<<"\n\n";
}