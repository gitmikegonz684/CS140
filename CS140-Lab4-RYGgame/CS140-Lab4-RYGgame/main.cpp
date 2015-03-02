//
//  main.cpp
//  CS140-Lab4-RYGgame
//
//  Created by Michael A. Gonzalez on 2/28/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/***** VARIABLES *****/
string guess, target;
string g1, g2, g3, t1, t2, t3;
int rCount, yCount, gCount;

/***** CLASS *****/
class rygEval {
public:
    void ryg(string guess){
        
        rCount=0;
        yCount=0;
        gCount=0;
        g1 = guess.substr(0,1);
        g2 = guess.substr(1,1);
        g3 = guess.substr(2,2);
        
        if (g1 == t1){
            gCount+=1;
        } else if ((target.find(g1) != string::npos) && (g1 != g2) && (g1 != g3)){
            yCount+=1;
        } else {
            rCount+=1;
        }
        
        if (g2 == t2){
            gCount+=1;
        } else if ((target.find(g2) != string::npos) && (g2 != g1) && (g2 != g3)){
            yCount+=1;
        } else {
            rCount+=1;
        }
        
        if (g3 == t3){
            gCount+=1;
        } else if ((target.find(g3) != string::npos) && (g3 != g2) && (g3 != g1)){
            yCount+=1;
        } else {
            rCount+=1;
        }
    }
};

/***** MAIN *****/
int main(int argc, const char * argv[]) {
    rygEval p;
    srand(time(NULL));
    
    target = to_string(rand() % 899 + 100);
    cout<<target<<"\n";
    t1 = target.substr(0,1);
    t2 = target.substr(1,1);
    t3 = target.substr(2,2);
    
    while (guess != target) {
        cout<<"Enter a guess: ";
        cin>>guess;
        if (guess.length()>3) {
            cout<<"Oops, please enter a guess between 100 and 999: ";
            cin>>guess;
        }
        p.ryg(guess);
        cout<<"You have: "<<rCount<<" RED\n";
        cout<<"          "<<yCount<<" YELLOW\n";
        cout<<"          "<<gCount<<" GREEN\n\n";
    }
    
    cout<<"WINNER WINNER PIZZA FOR DINNER !!!\n";
    
    return 0;
}
