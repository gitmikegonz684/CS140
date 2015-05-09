//
//  main.cpp
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 4/26/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include "Poker.h"
#include "Deck.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int count=0;
    while (count<99) {
        Poker p;
        p.create();
        int howMany=p.intro(); //howMany players in the game
        p.deal(howMany); //deal 5 cards to "howMany" # of players
        p.inspect();
        p.endGame();
        count++;
    }
    return 0;
}
