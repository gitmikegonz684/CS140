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
#include <vector>
#include "Dictionary.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Dictionary d;
    int usrAction=9;
    string word;
    
    d.create("list.txt");
    d.display();
    
    while (usrAction!=0) {
        cout<<"\nEnter the number of your next action:\n1. ADD a word to your dictionary\n2. REMOVE a word from your dictionary\n3. FIND a word in your dictionary\n4. DISPLAY your dictionary\n";
        cin>>usrAction;
        switch (usrAction) {
            case 1:
                cout<<"Write the word you would like to add:\n";
                word="";
                cin>>word;
                d.add(word);
                //d.display();
                break;
            case 2:
                cout<<"Write the word you would like to remove:\n";
                word="";
                cin>>word;
                d.remove(word);
                //d.display();
                break;
            case 3:
                cout<<"Write the word you would like to find:\n";
                word="";
                cin>>word;
                d.find(word);
                //d.display();
                break;
            case 4:
                d.display();
            default:
                break;
        }

    }
    cout<<"\n\n//***** GOODBYE *****//";
    return 0;
}
