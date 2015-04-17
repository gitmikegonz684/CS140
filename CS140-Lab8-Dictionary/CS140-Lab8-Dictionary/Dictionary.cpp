//
//  Dictionary.cpp
//  CS140-Lab8-Dictionary
//
//  Created by Michael A. Gonzalez on 4/16/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include "Dictionary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <locale>
#include <vector>
using namespace std;

void Dictionary::create(string filename)
{
    inputFile.open(filename);
    
    //Test if file openned successfuly
    if (inputFile.fail()) {
        cout<<"Failed to access file. Goodbye.\n";
        exit(1);
    }
    
    //Read lines in txt file and insert into vector
    while (!inputFile.eof()) {
        getline(inputFile, line);
        list.push_back(line);
    }
    
    //Iterate through vector to populate map
    string tempLine;
    string capsLine;
    for (int i=0; i<list.size(); i++) {
        tempLine=list[i];
        capsLine="";
        for (int j=0; j<tempLine.length(); j++) {
            capsLine = capsLine + toupper(tempLine[j], l);
        }
        capsList[capsLine]=capsLine;
    }
}
    
void Dictionary::display()
{
    cout<<"\n//***** YOUR DICTIONARY *****//\n";
    //Display map contents
    for (map<string, string>::iterator it=capsList.begin(); it!=capsList.end(); it++){
        cout<<it->second<<endl;
    }
    cout<<"//* * * * * * * * * *//\n";

}

void Dictionary::toFile()
{
    
}

void Dictionary::add(string word)
{
    capsWord="";
    for (int j=0; j<word.length(); j++) {
        capsWord = capsWord + toupper(word[j], l);
    }
    capsList[capsWord]=capsWord;
}

void Dictionary::remove(string word)
{
    capsWord="";
    for (int j=0; j<word.length(); j++) {
        capsWord = capsWord + toupper(word[j], l);
    }
    capsList.erase(capsWord);
}

void Dictionary::find(string word)
{
    map<string, string>::iterator iter;
    capsWord="";
    
    for (int j=0; j<word.length(); j++) {
        capsWord = capsWord + toupper(word[j], l);
    }

    iter=capsList.find(capsWord);
    if (iter != capsList.end()) {
        cout<<"FOUND\n";
    }
    else{
        cout<<"NOT FOUND\n";
    }
}