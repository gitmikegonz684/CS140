//
//  main.cpp
//  CS140-Lab3-PowerOfNumbers
//
//  Created by Michael A. Gonzalez on 2/9/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//
//  This program's purpose is to practice writing overloaded
//  functions while creating a program that takes a number
//  input from the user and raises it to a power.
//

#include <iostream>
using namespace std;


/***** VARIABLES *****/
int answerInt, selection, nInt, exponent, p;
double answerDouble, nDouble;
float answerFloat, nFloat, base, answer;
long double answerLong, nLong;


/***** CLASS *****/
class math {
public:

    void power(float base, int exponent=2){
        answer=base;
        if (exponent==0) {
            answer=1;
        }else{
            for (int i=1; i<exponent; i++) {
                answer=answer*base;
            }
        }
        cout<<"("<<base<<")"<<"^"<<exponent<<" = "<<answer<<"\n\n\n";
    }

    //    void power(double n, int p=2){
    //        answerDouble=n;
    //        for (int i=1; i<p; i++) {
    //            answerDouble=answerDouble*n;
    //        }
    //        cout<<"("<<n<<")"<<"^"<<p<<" = "<<answerDouble<<"\n";
    //    }
    //
    //    void power(int n, int p=2){
    //        answerInt=n;
    //        for (int i=1; i<p; i++) {
    //            answerInt=answerInt*n;
    //        }
    //        cout<<"("<<n<<")"<<"^"<<p<<" = "<<answerInt<<"\n";
    //    }
    //
    //    void power(float n, int p=2){
    //        answerFloat=n;
    //        for (int i=1; i<p; i++) {
    //            answerFloat=answerFloat*n;
    //        }
    //        cout<<"("<<n<<")"<<"^"<<p<<" = "<<answerFloat<<"\n";
    //    }
    //
    //    void power(long double n, int p=2){
    //        answerLong=n;
    //        for (int i=1; i<p; i++) {
    //            answerLong=answerLong*n;
    //        }
    //        cout<<"("<<n<<")"<<"^"<<p<<" = "<<answerLong<<"\n";
    //    }
};


/***** MAIN *****/
int main(int argc, const char * argv[]) {
    math p;
    
    /********* THIRD DRAFT ***********/
    float input;
    cout<<"Enter the letter (Q) at any time to quit.\n\n";
    while (!(input=='\n')) {
        cout<<"Enter the base number: ";
        cin>>input;
        base=input;
        cout<<"Enter the exponent: ";
        cin>>input;
        exponent=input;
        p.power(base, exponent);
    }
    
    
    /************ FIRST DRAFT *************/
    //    cout<<"***** WELCOME !!! *****\n";
    //    cout<<"Please enter a Double:\n";
    //    cin>>nDouble;
    //    cout<<"Please enter an exponent:\n";
    //    cin>>exponent;
    //    p.power(nDouble, exponent);
    //    cout<<"Please enter a Float:\n";
    //    cin>>nFloat;
    //    cout<<"Please enter an exponent:\n";
    //    cin>>exponent;
    //    p.power(nFloat, exponent);
    //    cout<<"Please enter an Integer:\n";
    //    cin>>nInt;
    //    cout<<"Please enter an exponent:\n";
    //    cin>>exponent;
    //    p.power(nInt, exponent);
    //    cout<<"Please enter a Long:\n";
    //    cin>>nLong;
    //    cout<<"Please enter an exponent:\n";
    //    cin>>exponent;
    //    p.power((long double) nLong, exponent);
    //    cout<<"Please enter a Interger to be squared:\n";
    //    cin>>nInt;
    //    p.power(nInt);
    return 0;
}