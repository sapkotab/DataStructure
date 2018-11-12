//Bhuwan Sapkota 101101219
//CSC 2421
//Homework 1
//01/27/2019
// This program will compute three random numbers

#include <iostream>
#include "my_random.h"
using namespace std;

int main()
{
    // creating the object of class psuedorandom.
    psuedorandom someClass;
    
    // variable to store user given first seed
    int initialSeed;
    
    // asking the user for seed
    
    cout << "Please enter a random number so this program will give three random number " << endl;
    cin >> initialSeed;
    
    // changing the seed
    someClass.seedChange(initialSeed);
    
    // printing three random number using member function of class object.
    
    for (int i =0; i < 3; ++i)
    {
        cout << "Random number: " << i+1 << endl;
        cout << someClass.randomNumber() << endl;
    }
    
    return 0;
    
}