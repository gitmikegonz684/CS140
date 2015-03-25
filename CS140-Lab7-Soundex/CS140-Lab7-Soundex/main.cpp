//
//  main.cpp
//  CS140-Lab7-Soundex
//
//  Created by Michael A. Gonzalez on 3/23/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>
#include <locale>
using namespace std;

//***** FUNCTIONS *****//
string convert(char letter){
    switch (letter) {
        case 'B': case 'F': case 'P': case 'V':
            return "1";
            break;
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
            return "2";
        case 'D': case 'T':
            return "3";
        case 'L':
            return "4";
        case 'M': case 'N':
            return "5";
        case 'R':
            return "6";
        case 'H': case 'W':
            return "*";
        default:
            return "";
            break;
    }
}

string soundex(string name){
    string prev, code, value, capName; // previous value, code translation for name, current value, uppercase name
    locale l;
    prev="*";
    for (int i=0; i<name.length(); i++) {
        capName = capName + toupper(name[i], l);
    }
    code=capName.substr(0,1);
    for (int i=1; i<capName.length(); i++) {
        value = convert(capName.at(i));
        if ((value.length()>0) && !(value == prev)) {
            code = code + value;
        }
        prev = value;
    }
    
    string output = (code + "000");
    
    size_t n = output.find("*");
    if (n!=string::npos) { //takes care of 'h' and 'w' special cases
        if (output.at(n-1)==output.at(n+1)) {
            output.replace(n, 2, "");
        } else {
            output.replace(n, 1, "");
        }
    }

    return output.substr(0, 4);
}

int main(int argc, const char * argv[]) {
    string input;
    while (input!="x") {
        cout<<"Enter a name:\n";
        cin>>input;
        cout<<soundex(input)<<"\n\n";
    }
    
    return 0;
}
