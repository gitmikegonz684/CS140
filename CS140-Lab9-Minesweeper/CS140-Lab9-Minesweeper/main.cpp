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
    int size, level, x, y;
    Minesweeper game;

    cout<<"What size map?\n";
    cin>>size;
    cout<<"What level difficulty?\n1. Easy\n2. Medium\n3. Hard\n";
    cin>>level;
    game.create(size, level);
    game.print();
    x=0;
    y=0;
    while ((x!=99)&&(y!=99)) {
        cout<<"What cell would you like to check?\nRow: ";
        cin>>x;
        cout<<"Column: ";
        cin>>y;
        if(game.checkGameOver(x, y)){
            cout<<"\n\n❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌\n";
            cout<<"❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌\n";
            game.print();
            cout<<"❌ ❌ ❌ GAME OVER ❌ ❌ ❌\n";
            cout<<"❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌ ❌\n";
            x=99;
            y=99;
        } else if (game.checkWin()){
            cout<<"\n\n⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️\n";
            cout<<"⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️\n";
            game.print();
            cout<<"⭐️ ⭐️ ⭐️ YOU WIN! ⭐️ ⭐️ ⭐️\n";
            cout<<"⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️ ⭐️\n";
            x=99;
            y=99;
        } else{
            game.print();
        }
    }
    
    cout<<"\n🚫  G O O D B Y E  🚫";
    
    return 0;
}
