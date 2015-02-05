//
//  main.cpp
//  CS140-METS
//
//  Created by Michael A. Gonzalez on 1/26/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    float METS, weight, time, calories;
    cout<<"Please enter the number of the activity you would like to select:\n";
    cout<<"1. SLEEPING\n2. WALKING\n3. BASKETBALL\n";
    cin>>METS;
    cout<<"Please enter your weight in pounds (lbs):\n";
    cin>>weight;
    cout<<"Please enter the amount of time (in minutes) spent doing the activity:\n";
    cin>>time;
    if (METS==1) {
        calories = 0.0175*METS*(weight/2.2)*time;
    } else if (METS==2){
        calories = 0.0175*METS*(weight/2.2)*time;
    } else {
        METS=8;
        calories = 0.0175*METS*(weight/2.2)*time;
    }
    cout<<"The number of calories burned "<<calories<<"\n";
    
    return 0;
}
