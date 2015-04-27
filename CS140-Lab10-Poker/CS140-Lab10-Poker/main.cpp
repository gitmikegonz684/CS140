//
//  main.cpp
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 4/26/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    string input, playerName;
    int numPlayers;
    
    cout<<"Want to play poker or quit? (p or q)\n";
    cin>>input;
    cout<<"How many players?\n";
    cin>>numPlayers;
    for (int i=1; i<=numPlayers; i++) {
        playerName="";
        cout<<"Enter the name of Player "<<numPlayers<<":\n";
        cin>>playerName;
        Player playerName;
    }
    
    return 0;
}
