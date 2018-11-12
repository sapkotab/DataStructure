//
//CSC 2421
//Homework 1
//Functions for random class

#include <iostream>
#include "my_random.h"

//Constructor that automatically initialize the object when class is called.

psuedorandom::psuedorandom(int userSeed, int userMultiplier, int userIncrement, int userModulus)
{
    seed = userSeed;
    multiplier = userMultiplier;
    increment = userIncrement;
    modulus = userModulus;
};

// member function
// that change the seed to user chosen number.

void psuedorandom::seedChange( int input)
{
    seed = input;
}

// function that compute the random number and change seed to new random number.

int psuedorandom::randomNumber()
{
   int tempNumber = (multiplier * seed +increment) % modulus;
    seed = tempNumber;
    return tempNumber;
}
