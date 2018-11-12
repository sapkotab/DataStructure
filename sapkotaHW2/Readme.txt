Modify the bag1.hPreview the document and bag1.cpp to implement the "set" class for integers described in project 5 at page 149. You have to use bag1 code and extend it for this homework. To verify your set class, write a main function that takes two sets of integers from an input file input.dat, and store them into separate sets, and apply following two operations.

First, combine the two into one set by using + (union) operator, and print out the union set. The + operator must remove all duplicates and store one copy of any item. You also need to implement a subtraction operator (A-B means removing all elements of B from A) and print out the result. So the main function takes two sets of integers and print the result of + and - operation.

A sample input.dat may look like this. Note that we assume the input file includes only two sets of integer numbers, each number is separated by white spaces and sets are separated by a newline character. Note that you will probably have to use getline()  <iostream> to get each line from the file and place it into a string, then stringstream <sstream> to parse the string into individual integers.

http://www.cplusplus.com/reference/sstream/stringstream/stringstream/ (Links to an external site.)Links to an external site. is a good example of string stream. 

 3  4  5  7  5 16 7 12 11 12  3  9  9  8  1 12
15  4  3  6 1 12  3 12 7  8 19  9 11 12  8  5 -4  -100

Assume that all inputs are integers and anything else should be rejected with an error message.

Include a run-time asymptotic analysis  (Best, Worst Case in terms of Big O) of  member functions used in main in an analysis.txt file. Don't just say that it is Best Case O(n) and Worst Case O(N^2).  Describe how many constant expressions, how many n expressions (loops), how many nested loops (n^2) etc.  For Best case, describe the scenario (when x is the first value found etc.) You should submit  a single lastnameHW2.zip containing: my_bag.h, my_bag.cpp, main.cpp, makefile, Readme.txt, and analysis.txt