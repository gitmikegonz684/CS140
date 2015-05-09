//
//  Deck.cpp
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 5/3/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include "Deck.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <locale>
using namespace std;

void Deck::create(){
    theDeck.insert(pair<int, string>(2,"♣️"));
    theDeck.insert(pair<int, string>(2,"♦️"));
    theDeck.insert(pair<int, string>(2,"♥️"));
    theDeck.insert(pair<int, string>(2,"♠️"));
    theDeck.insert(pair<int, string>(3,"♣️"));
    theDeck.insert(pair<int, string>(3,"♦️"));
    theDeck.insert(pair<int, string>(3,"♥️"));
    theDeck.insert(pair<int, string>(3,"♠️"));
    theDeck.insert(pair<int, string>(4,"♣️"));
    theDeck.insert(pair<int, string>(4,"♦️"));
    theDeck.insert(pair<int, string>(4,"♥️"));
    theDeck.insert(pair<int, string>(4,"♠️"));
    theDeck.insert(pair<int, string>(5,"♣️"));
    theDeck.insert(pair<int, string>(5,"♦️"));
    theDeck.insert(pair<int, string>(5,"♥️"));
    theDeck.insert(pair<int, string>(5,"♠️"));
    theDeck.insert(pair<int, string>(6,"♣️"));
    theDeck.insert(pair<int, string>(6,"♦️"));
    theDeck.insert(pair<int, string>(6,"♥️"));
    theDeck.insert(pair<int, string>(6,"♠️"));
    theDeck.insert(pair<int, string>(7,"♣️"));
    theDeck.insert(pair<int, string>(7,"♦️"));
    theDeck.insert(pair<int, string>(7,"♥️"));
    theDeck.insert(pair<int, string>(7,"♠️"));
    theDeck.insert(pair<int, string>(8,"♣️"));
    theDeck.insert(pair<int, string>(8,"♦️"));
    theDeck.insert(pair<int, string>(8,"♥️"));
    theDeck.insert(pair<int, string>(8,"♠️"));
    theDeck.insert(pair<int, string>(9,"♣️"));
    theDeck.insert(pair<int, string>(9,"♦️"));
    theDeck.insert(pair<int, string>(9,"♥️"));
    theDeck.insert(pair<int, string>(9,"♠️"));
    theDeck.insert(pair<int, string>(10,"♣️"));
    theDeck.insert(pair<int, string>(10,"♦️"));
    theDeck.insert(pair<int, string>(10,"♥️"));
    theDeck.insert(pair<int, string>(10,"♠️"));
    theDeck.insert(pair<int, string>(11,"♣️")); //11 -> Jack
    theDeck.insert(pair<int, string>(11,"♦️"));
    theDeck.insert(pair<int, string>(11,"♥️"));
    theDeck.insert(pair<int, string>(11,"♠️"));
    theDeck.insert(pair<int, string>(12,"♣️")); //12 -> Queen
    theDeck.insert(pair<int, string>(12,"♦️"));
    theDeck.insert(pair<int, string>(12,"♥️"));
    theDeck.insert(pair<int, string>(12,"♠️"));
    theDeck.insert(pair<int, string>(13,"♣️")); //13 -> King
    theDeck.insert(pair<int, string>(13,"♦️"));
    theDeck.insert(pair<int, string>(13,"♥️"));
    theDeck.insert(pair<int, string>(13,"♠️"));
    theDeck.insert(pair<int, string>(14,"♣️")); //14 -> Ace
    theDeck.insert(pair<int, string>(14,"♦️"));
    theDeck.insert(pair<int, string>(14,"♥️"));
    theDeck.insert(pair<int, string>(14,"♠️"));
    
    //if index of cardA > index of cardB, then cardA has higher value.
    cardValues.push_back("");
    cardValues.push_back("");
    cardValues.push_back("2");
    cardValues.push_back("3");
    cardValues.push_back("4");
    cardValues.push_back("5");
    cardValues.push_back("6");
    cardValues.push_back("7");
    cardValues.push_back("8");
    cardValues.push_back("9");
    cardValues.push_back("10");
    cardValues.push_back("Jack");
    cardValues.push_back("Queen");
    cardValues.push_back("King");
    cardValues.push_back("Ace");
}

void Deck::deal(int hands, int cardsPerHand){
    
    srand(time(NULL));
    
    for (int i=0; i<hands; i++) {
        for (int j=0; j<cardsPerHand; j++) {
            //iterate to randm card in "theDeck"
            int card = rand()%13+2; //randm # from 2-14
            if (theDeck.find(card) == theDeck.end()) {
                int temp = card;
                while (temp == card) {
                    card = rand()%13+2;
                }
            }
            size_t range = theDeck.count(card);
            int suit = rand()%range+0; //randm # from 0->("range"-1) (range = # of suits available to choose from)
            pair<multimap<int, string>::iterator, multimap<int, string>::iterator> ret;
            ret=theDeck.equal_range(card);
            multimap<int, string>::iterator it=ret.first;
            for (int k=0; k<suit; k++) {
                it++;
            }
            //write this card to "playerHands" then remove from "theDeck"
            string info = to_string(it->first)+(it->second); //put card and suit into string "info"
            string pInfo = playerNames[i]; //get name of player from "playerHands" vector
            playerHands.insert(pair<string, string>(pInfo,info));
            theDeck.erase(it);
        }
        
    }
    
//    ////print out all contents of multimap<int,string>
//    for (multimap<string,string>::iterator iter=playerHands.begin(); iter!=playerHands.end(); ++iter){
//        cout << (*iter).first << " => " << (*iter).second << '\n';
//    }
    
    ////print out all contents of multimap<int,string> / different format
    for (int i=0; i<playerNames.size(); i++) {
        string key = playerNames[i];
        pair <multimap<string,string>::iterator, multimap<string,string>::iterator> ret;
        ret = playerHands.equal_range(key);
        cout << key << " =>";
        for (multimap<string,string>::iterator it=ret.first; it!=ret.second; ++it){
//            if ((it->second)=="11♠️") {cout<<"  J♠️\n";}
//            if ((it->second)=="11♥️") {cout<<"  J♥️\n";}
//            if ((it->second)=="11♦️") {cout<<"  J♦️\n";}
//            if ((it->second)=="11♣️") {cout<<"  J♣️\n";}
//            if ((it->second)=="12♠️") {cout<<"  Q♠️\n";}
//            if ((it->second)=="12♥️") {cout<<"  Q♥️\n";}
//            if ((it->second)=="12♦️") {cout<<"  Q♦️\n";}
//            if ((it->second)=="12♣️") {cout<<"  Q♣️\n";}
//            if ((it->second)=="13♠️") {cout<<"  K♠️\n";}
//            if ((it->second)=="13♥️") {cout<<"  K♥️\n";}
//            if ((it->second)=="13♦️") {cout<<"  K♦️\n";}
//            if ((it->second)=="13♣️") {cout<<"  K♣️\n";}
//            if ((it->second)=="14♠️") {cout<<"  A♠️\n";}
//            if ((it->second)=="14♥️") {cout<<"  A♥️\n";}
//            if ((it->second)=="14♦️") {cout<<"  A♦️\n";}
//            if ((it->second)=="14♣️") {cout<<"  A♣️\n";}
            cout<<"  "<<it->second;
        }
        cout << "\n\n";
    }
    
}
