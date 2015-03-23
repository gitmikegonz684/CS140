//
//  main.cpp
//  CS140-Lab6-MoneyCounter
//
//  Created by Michael A. Gonzalez on 3/19/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

//***** VARIABLES *****//
int maxLimit, current;

//***** CLASS *****//
class Counter{
public:
    
    void bigMax(){
        maxLimit = 9999;
        current=0;
        cout<<"Maximum value of the counter is "<<maxLimit<<".\n";
        cout<<"Current value of the counter is "<<current<<".\n";
    }
    void varMax(int max){
        maxLimit = max;
        current=0;
        cout<<"Maximum value of the counter is "<<maxLimit<<".\n";
        cout<<"Current value of the counter is "<<current<<".\n";
    }
    void reset(){
        current=0;
    }
    
    int valuesMap(string thekey){
        map<string, int> valuesMap;
        valuesMap["a1"]=1;
        valuesMap["a2"]=2;
        valuesMap["a3"]=3;
        valuesMap["a4"]=4;
        valuesMap["a5"]=5;
        valuesMap["a6"]=6;
        valuesMap["a7"]=7;
        valuesMap["a8"]=8;
        valuesMap["a9"]=9;
        valuesMap["s1"]=10;
        valuesMap["s2"]=20;
        valuesMap["s3"]=30;
        valuesMap["s4"]=40;
        valuesMap["s5"]=50;
        valuesMap["s6"]=60;
        valuesMap["s7"]=70;
        valuesMap["s8"]=80;
        valuesMap["s9"]=90;
        valuesMap["d1"]=100;
        valuesMap["d2"]=200;
        valuesMap["d3"]=300;
        valuesMap["d4"]=400;
        valuesMap["d5"]=500;
        valuesMap["d6"]=600;
        valuesMap["d7"]=700;
        valuesMap["d8"]=800;
        valuesMap["d9"]=900;
        valuesMap["f1"]=1000;
        valuesMap["f2"]=2000;
        valuesMap["f3"]=3000;
        valuesMap["f4"]=4000;
        valuesMap["f5"]=5000;
        valuesMap["f6"]=6000;
        valuesMap["f7"]=7000;
        valuesMap["f8"]=8000;
        valuesMap["f9"]=9000;
        return valuesMap[thekey];
    }
    
    void checkOverflow(int current){
        bool overflow=false;
        if (current>maxLimit) {
            overflow=true;
        }
        if (overflow) {
            cout<<"Foul! There is overflow!\n";
        } else {
            cout<<"Safe! No overflow.\n";
        }
    }
};

///***** MAIN *****//
int main(int argc, const char * argv[]) {
    
    Counter moneyBag;
    string strinput, o;
    int varMaxInput;
    
    //*** Start Round 1 ***//
    moneyBag.bigMax();
    cout<<"\nEnter a key, either a, s, d, f, followed by 1-9, or o for overflow.\n";
    cout<<"KEY:  a=cents, s=dimes, d=dollars, f=tens of dollars\n\n";
    strinput="0";
    while (strinput != "o") {
        cin>>strinput;
        current+=moneyBag.valuesMap(strinput);
    }
    moneyBag.checkOverflow(current);
    cout<<"Current amount: "<<current<<"\n\n";
    
    
    //*** Start Round 2 ***//
    //moneyBag.reset();
    cout<<"\nEnter a key, either a, s, d, f, followed by 1-9, or o for overflow\n";
    cout<<"a=cents, s=dimes, d=dollars, f=tens of dollars\n\n";
    //moneyBag.bigMax();
    strinput="0";
    while (strinput != "o") {
        cin>>strinput;
        current+=moneyBag.valuesMap(strinput);
    }
    moneyBag.checkOverflow(current);
    cout<<"Current amount: "<<current<<"\n\n";
    
    
    //*** Start Round 3 ***//
    moneyBag.reset();
    cout<<"Please enter an integer amount less than 9999 to initialize the counter.\n";
    cin>>varMaxInput;
    moneyBag.varMax(varMaxInput);
    strinput="0";
    while (strinput != "o") {
        cin>>strinput;
        current+=moneyBag.valuesMap(strinput);
    }
    moneyBag.checkOverflow(current);
    cout<<"Current amount: "<<current<<"\n\n";

    return 0;
}

