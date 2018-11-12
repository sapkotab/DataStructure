/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      7
 *  Due Date  :      March 16, 2016
 *******************************************************/

#include <iostream>
#include <vector>
#include "function.h"
using namespace std;


// main function

int main() {
    int totalCents;
    const int denominations = 4;
    
    // asking user how much total cents
    cout << "Please enter the amount in US currency (cents) to change:" << endl;
    cin >> totalCents;
    
    // calling the function that do the rest
    ways(totalCents, denominations);
    return 0;
}
