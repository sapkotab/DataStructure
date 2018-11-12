// Bhuwan Sapkota
//CSC 2421
//Homework 2
//set Class prototypes

#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H
#include <cstdlib>              // Provides size_t
#include <fstream>

namespace main_savitch_3
{
    class set
    {
    
    public:
            // defining type of data, number of current data
            // and maximum number of data allowed.
        
        typedef int value_type;
        typedef size_t size_type;
        enum { CAPACITY = 30 };
        
                // Default CONSTRUCTOR
        set( ) { used = 0; }
        
        
        // MODIFICATION MEMBER FUNCTIONS
        
        
        bool erase(const value_type& target);
        void insert(const value_type& entry);
        
        void operator +=(const set& addend);
        void operator -=(const set& subtrahend);
        
            // CONSTANT MEMBER FUNCTIONS
        
        size_type size( ) const
                    { return used; };
        bool contain (const value_type& target) const;
        void print (const set& prt)const;
       
    
    private:
        
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
    };
    
        // NONMEMBER FUNCTIONS for the set class
    
    set operator +(const set& b1, const set& b2);
    set operator -(const set& b1, const set& b2);
    
}

#endif

