//
//  Poker.h
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 5/3/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#ifndef __CS140_Lab10_Poker__Poker__
#define __CS140_Lab10_Poker__Poker__

#include "Deck.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <utility>
using namespace std;

class Poker: public Deck{
public:
    int intro(); //Start the game, get player info, prepare to "deal()"
    void inspect(); //isolates a player's hand from "playerHands", then calls "evaluate()"
    void endGame(); //determines who the winner is

private:
    string evaluate(vector<string> hand); //parses vector<string>, then calls private Poker functions
    bool isPair(multimap<int, string> playersCards);
    bool is2Pair(multimap<int, string> playersCards);
    bool is3Kind(multimap<int, string> playersCards);
    bool isStraight(multimap<int, string> playersCards);
    bool isFlush(vector<string> hand);
    bool isFullHouse(multimap<int, string> playersCards);
    bool is4Kind(multimap<int, string> playersCards);
    bool isStraightFlush(vector<string> hand, multimap<int, string> playersCards);
    bool isRoyalFlush(vector<string> hand, multimap<int, string> playersCards);
};

#endif /* defined(__CS140_Lab10_Poker__Poker__) */
