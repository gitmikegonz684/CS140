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

int main(int argc, const char * argv[]) {
    
    return 0;
}

/***** FUNCTIONS *****/

double power(int n=2, double p=1){
    double answer;
    for (int i=1, i<=p, i++){
        answer+=n*n;
    }
    return answer;
}
