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
#include <string>
using namespace std;

/***** VARIABLES *****/
string guess, target, cpyTarget;
string g1, g2, g3, t1, t2, t3;
int rCount, yCount, gCount, compareCount;
bool p1, p2, p3; //digit places in target number.


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
        cpyTarget = target;
        
        if (g1 == t1) {
            gCount++;
            cpyTarget.replace(cpyTarget.find(t1), 1, "f");
            //t1="f";
        }
        if (g2 == t2) {
            gCount++;
            cpyTarget.replace(cpyTarget.find(t2), 1, "f");
            //t2 = "f";
        }
        if (g3 == t3) {
            gCount++;
            cpyTarget.replace(cpyTarget.find(t3), 1, "f");
            //t3 = "f";
        }
        
        if (cpyTarget.find(g1) != string::npos) {
            cpyTarget.replace(cpyTarget.find(g1), 1, "f");
            yCount++;
        }
        if (cpyTarget.find(g2) != string::npos) {
            cpyTarget.replace(cpyTarget.find(g2), 1, "f");
            yCount++;
        }
        if (cpyTarget.find(g3) != string::npos) {
            cpyTarget.replace(cpyTarget.find(g3), 1, "f");
            yCount++;
        }
        
        rCount=3-(gCount+yCount);
        
    }
};


/***** MAIN *****/
int main(int argc, const char * argv[]) {
    rygEval p;
    srand(time(NULL));
    target = to_string(rand() % 899 + 100);
    t1 = target.substr(0,1);
    t2 = target.substr(1,1);
    t3 = target.substr(2,2);
    cout<<"I'm thinking of a number between 100-999...\n\n";
    
    while (guess != target) {
        //cout<<target<<"\n";
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
    
    cout<<"WINNER WINNER PIZZA FOR DINNER !!!\n\n";
    
    return 0;
}
