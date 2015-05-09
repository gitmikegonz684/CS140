//
//  Deck.h
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 5/3/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#ifndef __CS140_Lab10_Poker__Deck__
#define __CS140_Lab10_Poker__Deck__

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <utility>
using namespace std;

class Deck{
public:
    
    multimap<int, string> theDeck; //container for cards in the deck
    
    vector<string> cardValues; //container for card types, where index = value of card
    
    multimap<string, string> playerHands; //contains name of player as the key and cards as the values.
    
    vector<string> playerNames; //used to store names of players and eventually their hand type (ie. full house, pair, muck, etc.)
    
    vector<string> handCards; //(re)used to build a 'hand' using "deal()", calculate the score of the hand, then load into "playerHands" (vect)
    
    vector<int> scores;
    
    void create(); //create the deck of cards
    
    void deal(int hands, int cardsPerHand=5); //deal specified # of cards randomly
};

#endif /* defined(__CS140_Lab10_Poker__Deck__) */
