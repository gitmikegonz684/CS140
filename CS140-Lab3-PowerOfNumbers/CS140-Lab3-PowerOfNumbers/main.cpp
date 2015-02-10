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
int answerInt, selection, nInt, exponent;
double answerDouble, nDouble;
float answerFloat, nFloat;
long double answerLong, nLong;


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
    cout<<"***** WELCOME !!! *****\n";
    cout<<"Please enter a Double:\n";
    cin>>nDouble;
    cout<<"Please enter an exponent:\n";
    cin>>exponent;
    p.power(nDouble, exponent);
    cout<<"Please enter a Float:\n";
    cin>>nFloat;
    cout<<"Please enter an exponent:\n";
    cin>>exponent;
    p.power(nFloat, exponent);
    cout<<"Please enter an Integer:\n";
    cin>>nInt;
    cout<<"Please enter an exponent:\n";
    cin>>exponent;
    p.power(nInt, exponent);
    cout<<"Please enter a Long:\n";
    cin>>nLong;
    cout<<"Please enter an exponent:\n";
    cin>>exponent;
    p.power((long double) nLong, exponent);
    cout<<"Please enter a Interger to be squared:\n";
    cin>>nInt;
    p.power(nInt);
    return 0;
}