//
//  Dictionary.h
//  CS140-Lab8-Dictionary
//
//  Created by Michael A. Gonzalez on 4/16/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#ifndef __CS140_Lab8_Dictionary__Dictionary__
#define __CS140_Lab8_Dictionary__Dictionary__

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <locale>
#include <vector>
using namespace std;
#include <string>

class Dictionary{
    
public:
    
    ifstream inputFile;
    string line, word, capsWord;
    locale l;
    vector<string> list;
    map<string, string> capsList;
    map<string, string>::iterator iter;

    
    void create(string filename);
    void display();
    void toFile();
    void add(string word);
    void remove(string word);
    void find(string word);
};

#endif /* defined(__CS140_Lab8_Dictionary__Dictionary__) */
