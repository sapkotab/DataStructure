This programming homework is to develop a simple spelling checker. The file dict.datPreview the document contains 25,025 frequently used words, each on a separate line in lowercase. Read the file, and insert the words into a hash table with 1373 buckets. 
Prompt for the name of an input text file to check. This file will contain a number of words. You choose to use an STL, you should also account for " in the first letter of the word, and , . ? ! " in the last letter.  (Strings have a .back member function).  Read the document, and separate it into a sequence of words (sets of characters and numbers separated by one of more spaces) converted to lowercase.  Use http://www.cplusplus.com/reference/locale/tolower/ (Links to an external site.)Links to an external site. as an example way to convert. 

Using a hash table/function, print out a list of words that appear to be misspelled.

A hash table contains buckets into which an object (data item) can be placed. When a hash function is applied to an object, a hash value is generated. The hash value is used to determine which bucket the object is assigned to. Hashed associated containers in STL have a constructor that takes the number of buckets and guarantees the bucket count will be at least that number.

A bucket is a cluster (or a sub container) that holds a set of data items that hash to the same table location. Obviously, you can not store 25K words in 1373 slots and you need to use some kind of chaining schemes such as linear probing or the second hashing. The size of a bucket is independent from the number of data items you put into the hash. So if you have too many buckets, the hash will not have many collisions but you may waste the storage and you may have to deal with a rather complex hash function and longer keys. If you have too small number of buckets, then you have to deal with frequent collisions. Finding a good bucket number would play an important role in reducing collisions. That's why we usually pick a prime number for the number of bucket. We picked 1373 for the bucket number.

You can use an  STL for this project.  Make sure to use the unordered versions (implemented as hash table) not the ordered versions (implemented as trees).

You will find unordered_map and unordered_set act the same, but the unordered_map requires that you map relates two items together.  This assigment requires that you insert a single item (a word)  into a hash table, so you would expect to use an unordered_set
 http://www.cplusplus.com/reference/unordered_set/unordered_set/ (Links to an external site.)Links to an external site.

Since you are dealing with strings, you could use the standard hash function for strings (will happen by default).  (If you wanted a different function, you would need to overload the ( ) operator.  To set the starting hash table size, you would use .rehash().  According to documentation, an unordered set will automatically increase the number of the buckets as required.

OR

you can use an unordered multiset.  The difference here is that the number of buckets is automatically increased, based on the number of collisions, but still allows some collisions, that you can access with iterators pointing in a linked list to the next collision.

http://www.cplusplus.com/reference/unordered_set/unordered_multiset/ (Links to an external site.)Links to an external site. (Make sure to compile with std=C++11). 

OR

You can implement your own hash, based on the textbook implementation but you need to come up with a scheme to include buckets (clusters) and collision resolution. Hash set from STL makes this very easy by using a constructor with a bucket value, although the exact bucket count may be reevaluated and altered by the library (it's OK for the homework. you don't have to constrain the program to use 1373 buckets)

If you're implementing your own hash, here's a sample function to create a key from a string. Basically it uses a prime number and the character ascii values for the % function.

class HFstring
{
  public:
  unsigned int operator()(const string& item) const
  {
    unsigned int prime = 2049982463;

    int n = 0, i;

    for (i = 0; i < item.length(); i++)
    n = n*8 + item[i];

  return n > 0 ? (n % prime) : (-n % prime);
  }
};

You don't have to interpret verb tense, plurals, conjugations etc. All you have to do is to check with each word with the dictionary.