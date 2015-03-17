//
//  main.cpp
//  CS140-Lab5-MagicSquare
//
//  Created by Michael A. Gonzalez on 3/12/15.
//  Copyright (c) 2015 Michael A. Gonzalez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

/***** VARIABLES *****/
int n, i, j, current, counter;

/***** CLASS *****/
class square {
    vector< vector<int> > row;
    int i=(n/2);
    int j=0;
    int counter=1;
    
public:
    // function to create and populate the magic square:
    void magic (int n) {
        for (int i=0; i<n; i++) {
                vector<int> col(n);
                row.push_back(col);
        }
        
        while (counter<=n*n) {
            if (row[j][i]==0) {
                row[j][i]=counter;
            } else {
                mvDown();
                row[j][i]=counter;
            }
            mvUpRight();
            counter++;
        }
    }
    
    // function for displaying magic square:
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<row[i][j];
                cout<<"\t";
            }
            cout<<"\n\n";
        }
    }
    
    // function for moving up
    void mvUp() {
        if (j>0) {
            j--;
        } else {
            j=n-1;
        }
    }
    
    // function for moving right
    void mvRight() {
        if (i!=(n-1)) {
            i++;
        } else {
            i=0;
        }
    }
    
    // function for moving Up and Right
    void mvUpRight() {
        mvUp();
        mvRight();
    }
    
    // function for moving Down
    void mvDown() {
        if ((j==(n-1)) && (i==0)) {
            j=1;
            i=(n-1);
        } else if (j!=(n-1)) {
            j+=2;
            i--;
        } else {
            j=0;
        }
    }
};


/***** MAIN *****/
int main(int argc, const char * argv[]) {
//    cout<<"Pick a number between 1 and 15:\n";
//    cin>>n;
    n=7;
    square s;
    s.magic(n);
    s.display();
    cout<<"\n\n";
    return 0;
}
