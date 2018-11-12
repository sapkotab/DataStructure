/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      5
 *  Due Date  :      Feb. 24, 201
 *******************************************************/

#include "dictionary.h"

// constructor, getter and setters;

dictionary::dictionary(){
    word = "";
}

wordType dictionary::getWord(){
    return word;
}
void dictionary::setWord(wordType _word){
    word = _word;
}

// compare the words weather they one is smaller than other
bool operator <(const dictionary& first, const dictionary& second){
    
    bool answer = false;
    if (first.word < second.word)
    {
        answer = true;
    }
    return answer;
}

// search the word from the list and return number of searches from front
int searchForward(list<dictionary> &wordList,wordType &findString){
    
    int answer =0;
    for (list<dictionary>::iterator it=wordList.begin() ; it !=wordList.end(); ++it){
        ++answer;
        if (it->getWord() == findString) {
            return answer;
        }
    }
    return -1;
}
// search the word from the list and return number of searches from back

int searchBackward(list<dictionary> &wordList,wordType &findString){
        wordList.reverse();
        int answer =0;
        for (list<dictionary>::iterator it=wordList.begin() ; it !=wordList.end(); ++it){
            ++answer;
            if (it->getWord() == findString) {
                wordList.reverse();
                return answer;
        }
       
    }
    wordList.reverse();
    return answer;

}

// revesing the list and streaming
void revPrintList(ostream& output, list<dictionary> &wordList){
    
    wordList.reverse();
    for (list<dictionary> ::iterator it = wordList.begin(); it != wordList.end(); it++) {
        output << it->getWord() << endl;
    }

}

// comparing two works weather they are same or not

bool comp(dictionary& first, dictionary& second){
    bool answer = false;
    if (first.getWord() == second.getWord()){
        answer = true;
    }
    return answer;
}