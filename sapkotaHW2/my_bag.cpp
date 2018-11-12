// Bhuwan Sapkota
// CSCI 2421
// Homework 2
// set Class implementation


//#include <algorithm>    // Provides copy function
#include <iostream>
#include <cassert>      // Provides assert function
#include "my_bag.h"

using namespace std;

namespace main_savitch_3
{
   

    bool set::erase(const value_type& target)
    {
	size_type index;    // The location of target in the data array

                // First, set index to the location of target in the data array,
                // which could be as small as 0 or as large as used-1. If target is not
                // in the array, then index will be set equal to used.
	index = 0; 
	while ((index < used) && (data[index] != target))
	    ++index;

	if (index == used)
	    return false; // target isn't in the bag, so no work to do.

            // When execution reaches here, target is in the bag at data[index].
            // So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];    
	return true;
    }
    
    // this function will look the target on the object data
    // return true if it exist
    bool set::contain(const value_type& target) const
    {
        bool answer = false;
        for (size_type i = 0; i < used; ++i)
        {
            if (target == data[i])
                answer = true;
        }
        return answer;
    }
    
    // this function will insert the entry to data
    // also increase the used number by one.
    void set::insert(const value_type& entry)
        // Library facilities used: cassert
    {
        assert(size( ) < CAPACITY);
        if (!contain(entry))
        {
            data[used] = entry;
            ++used;
        }
    }
    
   // oberloading the += and -= operator so it would
    // manipulate data also fullfill the set class requirements
    // where only one same integer is allowed.

    void set::operator +=(const set& addend)
        // Library facilities used:cassert
    {
	assert(size( ) + addend.size( ) <= CAPACITY);
        for (size_type i = 0; i < addend.size(); ++i)
        {
            insert(addend.data[i]);
        }
	
    }

    void set::operator -=(const set& subtrahend)
    // Library facilities used: algorithm, cassert
    {
        for (size_type i = 0; i < subtrahend.size(); ++i)
        {
            value_type tempVar = subtrahend.data[i];
            if (contain(subtrahend.data[i]))
                erase(tempVar);
        }
    }
    
    // function that print the data of object
    
    void set::print(const set& prt) const
    {
        for (size_type i =0; i< used; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
  
    // overloading + and - operator.

    set operator +(const set& b1, const set& b2)
    // Library facilities used: cassert
    {
        set answer;

        assert(b1.size( ) + b2.size( ) <= set::CAPACITY);

        answer += b1; 
        answer += b2;
        return answer;
    }


    set operator -(const set& b1, const set& b2)
// Library facilities used: cassert
    {
        set answer;
        
        answer += b1;
        answer -= b2;
        return answer;
    }
    
}