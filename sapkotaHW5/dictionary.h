/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      5
 *  Due Date  :      Feb. 24, 201
 *******************************************************/

/* Dr. Augustine
 dictionary.h
 Last Updated:02/14/2016
 Status: Compiles and all requirements met*/

#ifndef dictionary_h
#define dictionary_h
#include <string>
#include <list>
#include <iostream>

using namespace std;
typedef string wordType;

class dictionary
{
public:
    //typedef string wordType;
    dictionary();
    wordType getWord();
    void setWord(wordType _word);
    friend bool operator <(const dictionary& first, const dictionary& second);
private:
    wordType word;
};

/*******************************/
int searchForward(list<dictionary> &wordList,wordType &findString);

int searchBackward(list<dictionary> &wordList,wordType &findString);

void revPrintList(ostream& output, list<dictionary> &wordList);

bool comp(dictionary& first, dictionary& second);



#endif /* dictionary_h */