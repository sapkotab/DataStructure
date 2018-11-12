/*******************************************************
 *  Name      :     Bhuwan Sapkota
 *  Student ID:     101101219
 *  Class     :     CSC 2421
 *  HW#       :     4
 *  Due Date  :     Feb. 17, 201
 *******************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"

using namespace std;

int main() {
    
    HW4::node * head_ptr = nullptr; // head pointer of the linked list
    HW4::node * cursor = nullptr;   // hold the pointer of certain nodes during execution
    HW4::node::dataType inputText;  // hold string from text file
    
    // definging input/output stream
    ifstream inputFile;
    ofstream outputFile;
    
    // opening input and output file
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    
    //reading each line of textfile and storing in the node of link list
    
    while (!inputFile.eof())
    {
        cursor = head_ptr;
        getline(inputFile,inputText);
        
        if(cursor == nullptr)
            HW4::insertAtFront(head_ptr, inputText);
        else
        {
            for (int i = 0;i < HW4::listLength(head_ptr)-1; ++i)
                cursor = cursor->getNextPtr();
            HW4::insertAfterNode(cursor, inputText);
        }
    }
    
    // removing the first node
        
    HW4::removeAtFront(head_ptr);
    
    //removing the last node
    
    cursor = head_ptr;
    for (int i = 0; i < HW4::listLength(head_ptr)-2; ++i)
    cursor = cursor->getNextPtr();
    
    HW4::removeAtNode(cursor);
    
    // printing the string from remaining node
    
    HW4::printList(outputFile, head_ptr);
    
    // saving node strings in the outputfile
    
    cursor =head_ptr;
    while (cursor !=nullptr)
    {
        outputFile << cursor->getData() << endl;
        cursor = cursor->getNextPtr();
    }
    //closing input/output file
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}