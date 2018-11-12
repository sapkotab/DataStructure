//
//CSC 2421
//Homework 1
//random Class prototypes

#ifndef MY_RANDOM_H
#define MY_RANDOM_H

//class defintion

class psuedorandom
{
  public:
    //Constructor
    psuedorandom(int userSeed =1,
           int defaultMultiplier = 40,
           int defaultIncrement = 725,
           int defaultModulus = 729);
    
    // member function prototypes
    
    void seedChange (int seed);
    int randomNumber();

    
  private:
    // private data variable to store different variable for random number.
    int seed;
    int multiplier;
    int increment;
    int modulus;
};

#endif
