/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      5
 *  Due Date  :      Feb. 24, 201
 *******************************************************/

#include <iostream>
#include <fstream>
#include <list>
#include "dictionary.h"

using namespace std;

int main() {
    
    list <dictionary> wordList; // declaring wordlist
    string text;                // holds the temporary text to read and write
    
    // input/output stream
    ifstream inputFile;
    ofstream outputFile;
    
    // opening files to read and write
    inputFile.open("dictionary.txt");
    outputFile.open("revsorted.txt");
    
    // reading the word from dictionary file;
    while (inputFile >> text) {
        dictionary temp;
        temp.setWord(text);
        
        wordList.push_back(temp);
    }
    wordList.sort();    // sorting words
    inputFile.close();  // closing the disctionary file
    inputFile.open("findwords.txt");    // opening the new file that has words need to be serched in the dictionary
    
    // seaching the word in wordlist
    while (inputFile >> text) {
        int wordPosition = searchForward(wordList, text);
        
        // if word is not found add that word in the list
        if (wordPosition == -1)
        {
            dictionary temp;
            temp.setWord(text);
            wordList.push_back(temp);
            wordList.sort();
        }
        
        // printing the number of searchs from front and back if it is found in the list
        else{
            cout << "Number of search to find the word \"" << text << "\" from front of the list is: " << wordPosition << endl;
            wordPosition = searchBackward(wordList, text);
            cout << "Number of search to find the word \"" << text << "\" from back of the list is: " << wordPosition << endl;
        
        }
    }
    
    // writing the list in file in reavese order
    
    revPrintList(outputFile, wordList);
    
    // close opend file
    outputFile.close();
    inputFile.close();
    
    
    return 0;
}
