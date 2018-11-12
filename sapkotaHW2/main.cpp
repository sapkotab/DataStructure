/*******************************************************
*  Name      :  Bhuwan Sapkota
*  Student ID:  101101219
*  Class     :  CSC 2421
*  HW#       :  2
*  Due Date  :  Feb. 3, 201
*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include "my_bag.h"

using namespace std;

int main()

{
    
    // defining objects of class set
    main_savitch_3::set setA;
    main_savitch_3::set setB;
    main_savitch_3::set setA_PlusSetB;
    main_savitch_3::set setA_MinusSetB;
    
    ifstream input; // defining input stream
    string string1; // string that hold first set
    string string2; // string that hold second set
    
    // defining stringstreams to put the string to integer array of objects
    stringstream sstream1;
    stringstream sstream2;
    
    // opening data file and storing them accordingly
    input.open("input.dat");
    getline(input,string1);
    input.ignore();
    getline(input,string2);
    
    sstream1 << string1;
    
    while (!sstream1.fail())
    {
        int tempInt;
        sstream1 >> tempInt;
        setA.insert(tempInt);
    }
    // it will execute if these is non integer before end of file.
    if (!sstream1.eof())
    {
        cout << "string stream failed becasue input has non interger charactor" <<endl;
        exit(1);
    }
    
    sstream2 << string2;
    int tempInt;
    while (!sstream2.fail())
    {
        sstream2 >> tempInt;
        setB.insert(tempInt);
    }
    
     // it will execute if these is non integer before end of file.
    if (!sstream2.eof())
    {
        cout << "string stream failed becasue input has non interger charactor" <<endl;
        exit(1);
    }
    
    
    // printing setA
    cout << "setA contain following integers" << endl;
    setA.print(setA);
   
    // printing setB
    cout << "setB contain following integers" << endl;
    setB.print(setB);
    
    // adding setA,setB and priting
    cout << "setA+setB contain following integers" << endl;
    setA_PlusSetB = setA + setB;
    setA_PlusSetB.print(setA_PlusSetB);
    
    // subtracting setB from setA
    cout << "setA-setB contain following integers" << endl;
    setA_MinusSetB = setA - setB;
    setA_MinusSetB.print(setA_MinusSetB);
    
    
    return 0;
}
