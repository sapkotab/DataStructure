/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      9
 *  Due Date  :      April 20, 2016
 *******************************************************/


#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_set>

using namespace std;

int main() {
    //declaring and setting the initial bucket size
    unordered_multiset<string> dictHash;
    
    // setting the size to 1373
    dictHash.reserve(1373);
    
    // input stream for dictionary
    ifstream inputDict;
    
    // opening the dictionary
    inputDict.open("dict.dat");
    
    // reading the file and storing in hash table(unordered_multiset)
    while (inputDict.good()) {
        string temp;
        inputDict >> temp;
        dictHash.insert(temp);
    }
    
    // closing dictionary file.
    inputDict.close();
    
    // name of the file user will want to read and check spellings
    string fileName;
    
    // input file stream
    ifstream inputFile;
    
    // promt.
    cout << "Welcome to the spell check program!!!" << endl;
    cout << "Please enter the name of the file" << endl;
    
    // filename from user.
    cin >> fileName;
    
    // number of wrongly spelled words
    int wrongSpellCount = 0;
    // opening user file
    inputFile.open(fileName);
    
    //reading user file and checking spelling and printing as we go.
    while (inputFile.good()) {
        
        string temp; // word as user file has
        string lowertemp;   // this variable will store lowercase and puntuationless word.
        
        // read word
        inputFile >> temp;
        
        // convering word into lowercase and punctuationless word
        for (int i=0; i<temp.length(); ++i) {
            if(isalpha(temp[i]))
                lowertemp +=tolower(temp[i]);
        }
        
        // defining iterator for finding the word is in the hash table
        unordered_multiset<string>::iterator it = dictHash.find(lowertemp);
        
        // if word is not in hash table iterator will return endof iterator.
        if(it == dictHash.end()){
            wrongSpellCount++; // count wrongly spelled wordl
            
            // print header if at least one misspelled word. only one time.
            if(wrongSpellCount == 1){
                cout << "Following are the the missspelled words \n";
                cout << "----------------------------------------\n";
            }
            
            // print wrongly spelled word.
            cout << wrongSpellCount <<") " << lowertemp << endl;
        }
    }
        return 0;
}
