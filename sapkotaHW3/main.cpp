//
//  main.cpp
//  sapkotaHW3
//
//  Created by bhuwan sapkota on 2/7/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "mystring.h"
using namespace std;

int main() {
    
    
    // defining streams;
    
    ifstream inputFile;
    ofstream outputFile;
    
    // creating array object
    hw4::my_string resulting;
    
    // holds lenth of column
    size_t columnLength;

    // opening data files to import and export
    inputFile.open("data.txt");
    outputFile.open("data.out");
   
    // reading the datafile until the end
    while (!inputFile.eof())
    {
        hw4::my_string lineText;
    
        char space = ' ';
        hw4::getline(inputFile,lineText);
        lineText +=space;
        resulting +=lineText;
    }
    cout << "Plese enter the length of the column for the formated text" << endl;
    cin >> columnLength;
    
    // editing the object with newline and hypen
    
    resulting.insertHypenNewline(columnLength);
    
    //saving data on file
    outputFile << resulting;
    
    //printing object in console
    cout << "\"Here is the formated text\"" << endl;
    cout << " ----------------------------" << endl;
    cout << resulting << endl << endl;

    
    
    inputFile.close();
    outputFile.close();
    return 0;
}
