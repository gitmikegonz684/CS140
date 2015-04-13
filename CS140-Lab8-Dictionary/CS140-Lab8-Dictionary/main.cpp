//
//  main.cpp
//  CS140-Lab8-Dictionary
//
//  Created by Michael A. Gonzalez on 4/6/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <locale>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream inputFile;
    string line;
    locale l;
    map<string, string> words;
    inputFile.open("list.txt");
    
    if (inputFile.fail()) {
        cout<<"Failed to access file. Goodbye.\n";
        exit(1);
    }
    inputFile.get();
    while (!inputFile.eof()) {
        cout<<line;
        inputFile.get();
    }
    
    //cout<<words["SOLUTION"];
    
    return 0;
}
