For this assignment, you will implement dictionary.hPreview the document to create a dictionary that reads in a list of unsorted words into a <list> STL (which is an implementation of a doubly linked list.) from a file called dictionary.txt.  Next, you must sort the data (which the list STL has a member function for).  Now, you will read a list of words from a file called findwords.txt.  For each word in findwords.txt, you will search that list from the beginning of the list and if found, print (to the screen) how many searches you had to make to find the word.  Then if found, you will search from the back of the list and print how many searches you had to make. If not found you will insert the item into the back of the list.  Then once again, sort the list.

This will help you visualize that a Doubly Linked List might on average cut your search time in half by sorting the data, then choosing which end to start the search.

When complete print out each word on a new line in a file called revsorted.txt. Start at the back of the list so you end up with a reverse sorted list (words starting with z's first).

For this assignment, you should have setup a class called dictionary that holds a word as type string, with a single private value, a default constructor and appropriate get/set functions.  This way you could (in the future) expand the definition

Some Important tips (please read):
http://www.cplusplus.com/reference/list/list/ (Links to an external site.)Links to an external site.

- Remember like a vector, you have a list of a particular type (dictionary in this case)

- A list<dictionary>::iterator is a pointer to a list containing dictionary items.  Not every operator is defined, but ++ and -- are defined, so you can increment or decrement the pointer.

- There are member functions for a list   .begin() which is pointing to the first item on the list and .end() which is the last pointer NULL.  So, you generally want to loop from .begin() to != .end()

To start at the back (tail pointer) and work you way to the front you want to reverse the process.  so instead of an iterator (which points to the head of the list), you want to use reverse_iterator.  And instead of .begin() to != .end(), you want to go from .rbegin() to != .rend()

In order to use the .sort() function for lists, you must overload the operator <, as a friend function of the class.  The .sort() function uses this operator to sort.

Remember if you are looking at the VALUE of what the pointer points to, you must dereference the pointer.  If you are pointing to a class with a public member function called findValue, you would write that as xPtr->getWords(), or (*xPtr).getWords  NOT xPtr.findValue.