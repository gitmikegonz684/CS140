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

Minesweeper m;

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
    cout<<"\n \t";
    for (int i=1; i<usrSize+1; i++) {
        cout<<"|"<<i<<"|\t";
    }
    cout<<"\n\n";
    
    //Print rows with headers and footers
    for (int i=0; i<usrSize; i++) {
        cout<<"|"<<i+1<<"| \t";
        for (int j=0; j<usrSize; j++) {
            cout<<" "<<row[i][j];
            cout<<"\t";
        }
        cout<<"|"<<i+1<<"|\n\n";
    }
    
    //Print column footer
    cout<<" \t";
    for (int i=1; i<usrSize+1; i++) {
        cout<<"|"<<i<<"|\t";
    }
    cout<<"\n\nNumber of mines: "<<minesCount<<"\n\n";
}

bool Minesweeper::checkGameOver(int x, int y){
    x=x-1;
    y=y-1;
    //Checks for "Game Over"
    if (boolfield[x][y]) {
        for (int i=0; i<usrSize; i++) {
            for (int j=0; j<usrSize; j++) {
                if (boolfield[i][j]) {
                    row[i][j]="✖︎";
                }
            }
        }

    } else {
        checkSurround(x, y);
    }
    return boolfield[x][y];
}

void Minesweeper::checkSurround(int x, int y){
    //Check cells surrounding the cell selected by the user
    int x2, y2;
    int count=0; //count of mines found around selected cell
    for (int i=-1; i<2; i++) {
        for (int j=-1; j<2; j++) {
            x2=x+i;
            y2=y+j;
            if ((x2>=0)&&(x2<usrSize)&&(y2>=0)&&(y<usrSize)) {
                if (boolfield[x2][y2]) {
                    count++;
                }
            }
        }
    }
    row[x][y]=to_string(count);
}

bool Minesweeper::checkWin(){
    int winCount=0; //count used to determine if all safe cells have been discovered
    for (int i=0; i<usrSize; i++) {
        for (int j=0; j<usrSize; j++) {
            if (!boolfield[i][j]) {
                if (row[i][j]!="⎕") {
                    winCount++;
                }
            }
        }
    }
    if (winCount==((usrSize*usrSize)-minesCount)) {
        return true;
    } else{
        return false;
    }
}