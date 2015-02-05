//
//  main.cpp
//  CS140-IceCream
//
//  Created by Michael A. Gonzalez on 2/3/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // VARIABLES
    int numCones, numScoops, totalBill;
    char flavor;
    
    cout<<"=== Mike G's Ice Cream ===\n";
    cout<<"1 scoop           --> $3.00\n";
    cout<<"2 scoops          --> $4.00\n";
    cout<<"Additional scoops --> $1.00 each\n\n";
    
    cout<<"How many ice cream cones would you like to buy? (limit: 10)\n";
    cin>>numCones;
    if (numCones>10) {
        cout<<"Sorry no more than 10 cones per customer. Please enter a new quantitiy:\n";
        cin>>numCones;
    }
    for (int i=1; i<=numCones; i++) {
        std::stringstream ss;
        
        cout<<"How many scoops would you like for cone #"<<i<<" ?\n";
        cin>>numScoops;
        if (numScoops>5) {
            cout<<"Sorry, no more than 5 scoops per cone. Please enter a new quantity:\n";
            cin>>numScoops;
        }
        totalBill+=numScoops+2;
        for (int j=1; j<=numScoops; j++) {
            cout<<"Specify the ice cream flavor (input only one character) for scoop #"<<j<<":\n";
            cin>>flavor;
            ss<<"   ("<<flavor<<")\n";
        }
        ss<<"   \\|/\n";
        ss<<"    Y\n";
        cout<<"Here is your cone! Enjoy!!!\n";
        std::string cone=ss.str();
        cout<<cone;
    }
    cout<<"Your total comes out to $"<<totalBill<<".00\n";
    cout<<"Thank you!\n\n";
}
