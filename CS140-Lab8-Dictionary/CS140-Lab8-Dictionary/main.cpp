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
//#include "input.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream inputFile;
    string line;
    locale l;
    //Input no;
    map<string, string> words;
    inputFile.open("list.txt");
    
    if (inputFile.fail()) {
        cout<<"Failed to access file. Goodbye.\n";
        exit(1);
    }
    size_t n;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        n = line.find("a");
        line.replace(n, 1, "$");
//        for (int i=0; i<line.length(); i++) {
//            line = line + toupper(line[i], l);
//        }
        //in case of "/" at end of lines use code below
        //line = line
        //line.erase(line.end());
        words[line]=line;
    }
    for (map <string, string> :: iterator it = words.begin(); it!=words.end(); it++){
        cout<<it->second<<endl;
    }
    
    //cout<<words["SOLUTION"];
    cout<<"\ndone";
    
    return 0;
}
