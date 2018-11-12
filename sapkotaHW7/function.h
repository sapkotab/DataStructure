/*******************************************************
 *  Name      :      Bhuwan Sapkota
 *  Student ID:      101101219
 *  Class     :      CSC 2421
 *  HW#       :      6
 *  Due Date  :      March 16, 2016
 *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

#ifndef function_h
#define function_h

// function that return the cents
int coin(int num){
    if (num == 1) {
        return 1;
    }
    else if (num == 2){
        return 5;
    }
    else if (num ==3){
        return 10;
    }
    else if (num ==4){
        return 25;
    }
    return 0;
}

// functionn that print all optimal combination and all possible combination
void print(vector<int> smallest, int &count){
    
    // don't print if vector is empty
    if ( smallest.size() == 0) {
        return;
    }
    
    // translating the vector to coin and number of coin
    int penny = 0;
    int neckle = 0;
    int dime = 0;
    int quater = 0;
    
    for (int i = 0; i < smallest.size(); ++i) {
        if (smallest[i] == 1) {
            penny++;
        }
        if (smallest[i] == 5) {
            neckle++;
        }
        if (smallest[i] == 10) {
            dime++;
        }
        if (smallest[i] == 25) {
            quater++;
        }
    }
    
    
    count++;
    // print the optimal way.
    if (count ==1) {
        cout << "Optimal Combination: { " << quater << " quater, " << dime << " dime, ";
        cout << neckle << " neckle, " << penny << " penny} Total: " << smallest.size() << endl << endl;
        
        cout << "List of all possible combinations" << endl;
        
    }
    
    // print rest of the combinations
    cout << "[" << count << "] {";
    cout << quater << " quater, " << dime << " dime, ";
    cout << neckle << " neckle, " << penny << " penny} Total: " << smallest.size() << endl;
}

// recursive function that find all possible combination of coins

void way_recursive(int amount, int denomination, int & count, vector<int> &smallest){
    // base case
    if (amount == 0) {
        // printing output only when combination reach the base case.
        print(smallest,count);
        return;
    }
    // base case
    if (denomination == 0) {
        return;
    }
    // if amount is smaller than coin it reduce the denomination to next smaller one
    if ((coin(denomination)) > amount) {
        way_recursive(amount,denomination-1,count,smallest);
    }
    else
        // find the denomination with and without bigger coins
        while (denomination != 0) {
            smallest.push_back(coin(denomination));
            way_recursive(amount-coin(denomination), denomination, count, smallest);
            smallest.pop_back();
            denomination--;
        }
    }

// aggregative function that take care of all above functions
int ways(int amount, int denomination){
    vector<int> smallest;
    int count = 0;
    way_recursive(amount, denomination, count, smallest);
    cout << endl << "Total distinct coin combinations: " << count << endl;
    return count;
}


#endif /* function_h */
