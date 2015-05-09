//
//  Poker.cpp
//  CS140-Lab10-Poker
//
//  Created by Michael A. Gonzalez on 5/3/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include "Poker.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <utility>
using namespace std;

int Poker::intro(){
    string pName, input;
    int numPlayers; //# of players (or hands) in the game
    
    cout<<"Want to play poker or quit? (p or q)\n";
    cin>>input;
    cout<<"How many players?\n";
    cin>>numPlayers;
    for (int i=1; i<=numPlayers; i++) {
        cout<<"Enter name of Player"<<i<<":\n";
        string pName="";
        cin>>pName;
        playerNames.push_back(pName);
    }
    
    return numPlayers;
}

void Poker::inspect(){
    vector<string> temp;
    
    //for each player...
    for (int i=0; i<playerNames.size(); i++) {
        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ret;
        ret=playerHands.equal_range(playerNames[i]);
        //place their cards into vector<string>, then call "evaluate()"
        for (multimap<string, string>::iterator it=ret.first; it!=ret.second; ++it) {
            temp.push_back(it->second);
        }
        string result = Poker::evaluate(temp);
        
        //append 'result' to "playerNames"
        playerNames[i]=playerNames[i]+" has a "+result;
        
        //clear contents of "temp" to prep for next player's cards.
        temp.erase(temp.begin(), temp.end());
    }
    
    //cout FINAL contents of "playerNames" (vect)
    for (int i=0; i<playerNames.size(); i++) {
        cout<<playerNames[i]<<endl;
    }

}

string Poker::evaluate(vector<string> hand){
    //populates "handMap" with the info from "hand"
    //purpose is to have the multimap automatically put card info in increasing order
    multimap<int, string> handMap;
    for (int i=0; i<hand.size(); i++) {
        int itemp = stoi(hand[i].substr(0, hand[i].length()-6));
        string stemp = hand[i].substr(hand[i].length()-6, hand[i].length());
        handMap.insert(pair<int, string>(itemp, stemp));
    }
    
    //determines what kind of hand a player has
    string result="";
    if (Poker::isRoyalFlush(hand, handMap)) {result="ROYAL FLUSH!!!";scores.push_back(9);}
    else if (Poker::isStraightFlush(hand, handMap)) {result="Straight Flush!";scores.push_back(8);}
    else if (Poker::is4Kind(handMap)) {result="4 of a Kind!";scores.push_back(7);}
    else if (Poker::isFullHouse(handMap)) {result="Full House!";scores.push_back(6);}
    else if (Poker::isFlush(hand)) {result="Flush!";scores.push_back(5);}
    else if (Poker::isStraight(handMap)) {result="Straight!";scores.push_back(4);}
    else if (Poker::is3Kind(handMap)) {result="3 of a Kind!";scores.push_back(3);}
    else if (Poker::is2Pair(handMap)) {result="2 Pair!";scores.push_back(2);}
    else if (Poker::isPair(handMap)) {result="Pair!";scores.push_back(1);}
    else {result="WORTHLESS hand...";scores.push_back(0);}
    
    return result;
}

bool Poker::is2Pair(multimap<int, string> playersCards){
    int check=0;
    for (int i=2; i<15; i++) {
        int count=0;
        pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
        ret = playersCards.equal_range(i);
        
        for (multimap<int,string>::iterator it=ret.first; it!=ret.second; ++it){count++;}
        if (count==2) {check++;}
    }
    
    if (check==2) {return true;}
    else {return false;}
}

bool Poker::is3Kind(multimap<int, string> playersCards){
    int check=0;
    //looks for a key with 3 value inputs
    for (int i=2; i<15; i++) {
        int count=0;
        pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
        ret = playersCards.equal_range(i);
        
        for (multimap<int,string>::iterator it=ret.first; it!=ret.second; ++it){count++;}
        if (count==3) {check++;}
    }
    
    if (check>0) {return true;}
    else {return false;}
}

bool Poker::is4Kind(multimap<int, string> playersCards){
    int check=0;
    //looks for a key w/ 4 value inputs
    for (int i=2; i<15; i++) {
        int count=0;
        pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
        ret = playersCards.equal_range(i);
        
        for (multimap<int,string>::iterator it=ret.first; it!=ret.second; ++it){count++;}
        if (count==4) {check++;}
    }
    
    if (check>0) {return true;}
    else {return false;}
}

bool Poker::isFlush(vector<string> hand){
    vector<string> suitsInHand;
    int count=0;
    //goes through "hand" and compares the 1st suit with the others until it finds a mismatch
    for (int c=0; c<hand.size(); c++) {
        string suit = hand[c].substr(hand[c].length()-6, hand[c].length());
        if (suit == hand[c+1].substr(hand[c+1].length()-6, hand[c+1].length())) {
            count++;
        } else {
            c=hand.size();
        }
    }
    //returns true only if the suit of the first card in "hand" found 4 matches
    if (count==4) {return true;}
    else {return false;}
}

bool Poker::isFullHouse(multimap<int, string> playersCards){
    int check=0;
    int prev=0;
    //checks for 3ofAkind; if found, assigns the card value to "prev" and increments "check"
    for (int i=2; i<15; i++) {
        int count=0;
        multimap<int,string>::iterator it;
        pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
        ret = playersCards.equal_range(i);
        for (it=ret.first; it!=ret.second; ++it){count++;}
        if (count==3) {
            prev=it->first;
            check++;
        }
    }
    
    //looks for a pair only if 3ofAkind was found; if found, checks against "prev" to make sure they are not the same
    if (check>0) {
        for (int i=2; i<15; i++) {
            int count=0;
            multimap<int,string>::iterator it;
            pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
            ret = playersCards.equal_range(i);
            
            for (it=ret.first; it!=ret.second; ++it){count++;}
            if ((count==2)&&(prev!=it->first)) {check=99;} //check=99 => FullHouse detected
        }

    }
    
    //report if FullHouse was found
    if (check==99) {return true;}
    else {return false;}
}

bool Poker::isPair(multimap<int, string> playersCards){
    int check=0;
    //looks for a key w/ 2 value inputs
    for (int i=2; i<15; i++) {
        int count=0;
        pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
        ret = playersCards.equal_range(i);
        
        for (multimap<int,string>::iterator it=ret.first; it!=ret.second; ++it){count++;}
        if (count==2) {check++;}
    }
    
    if (check>0) {return true;}
    else {return false;}
}

bool Poker::isRoyalFlush(vector<string> hand, multimap<int, string> playersCards){
    if (Poker::isFlush(hand)) {
        if (Poker::isStraight(playersCards)) {
            int check=0;
            
            //checks that the straight begins at 10
            for (int i=0; i<1; i++) {
                int count=0;
                multimap<int,string>::iterator it;
                pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
                ret = playersCards.equal_range(i);
                for (it=ret.first; it!=ret.second; ++it){if ((it->first)==10) {count++;}}
                if (count>0) {check++;}
            }
            
            //RoyalFlush is found if check>0
            if (check>0) {return true;}
            else {return false;}
        }
        else {return false;}
    }
    else {return false;}
}

bool Poker::isStraight(multimap<int, string> playersCards){
    int prev=0;
    int check=0;
    bool straight=false;
    pair <multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
    multimap<int,string>::iterator it;
    
    for (it=playersCards.begin(); it!=playersCards.end(); ++it){
        //if the card is the next one in sequence, increment "check"; else reset "check"
        if ((it->first)==(prev+1)) {check++;}
        else {check=0;}
        prev=it->first;
        if (check==4) {straight=true;}
    }
    //if check==4
    return straight;
}

bool Poker::isStraightFlush(vector<string> hand, multimap<int, string> playersCards){
    if (Poker::isFlush(hand)) {
        if (Poker::isStraight(playersCards)) {return true;}
        else {return false;}
    }
    else {return false;}
}

void Poker::endGame(){
    int max=0;
    int who=0;
    for (int i=0; i<scores.size(); i++) {
        if (scores[i]>max) {
            max=scores[i];
            who=i;
        }
    }
    cout<<"\n✨🎉✨ "<<playerNames[who]<<" WINNER!!!!! ✨🎉✨\n\n\n";
}