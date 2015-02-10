//
//  main.cpp
//  CS140-Lab3-PowerOfNumbers
//
//  Created by Michael A. Gonzalez on 2/9/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//
//  This program reads an int n and a double p from the user.
//  Then executes n^p.
//

#include <iostream>
using namespace std;


/***** VARIABLES *****/
int answerInt;
double answerDouble;
float answerFloat;
long double answerLong;


/***** CLASS *****/
class math {
public:
    
    void power(double n, int p=2){
        answerDouble=n;
        for (int i=1; i<p; i++) {
            answerDouble=answerDouble*n;
        }
        cout<<n<<" to the power of "<<p<<" equals: "<<answerDouble<<"\n";
    }
    
    void power(int n, int p=2){
        answerInt=n;
        for (int i=1; i<p; i++) {
            answerInt=answerInt*n;
        }
        cout<<n<<" to the power of "<<p<<" equals: "<<answerInt<<"\n";
    }
    
    void power(float n, int p=2){
        answerFloat=n;
        for (int i=1; i<p; i++) {
            answerFloat=answerFloat*n;
        }
        cout<<n<<" to the power of "<<p<<" equals: "<<answerFloat<<"\n";
    }
    
    void power(long double n, int p=2){
        answerLong=n;
        for (int i=1; i<p; i++) {
            answerLong=answerLong*n;
        }
        cout<<n<<" to the power of "<<p<<" equals: "<<answerLong<<"\n";
    }
};


/***** MAIN *****/
int main(int argc, const char * argv[]) {
    math p;
    cout<<"#1\n";
    p.power(5.2761, 5);
    cout<<"#2\n";
    p.power(3.5, 4);
    cout<<"#3\n";
    p.power(2, 20);
    cout<<"#4\n";
    p.power((long double) 121, 10);
    cout<<"#5\n";
    p.power(256);
    return 0;
}