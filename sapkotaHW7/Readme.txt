 Refer to the documenting and submitting homework from Programming Guidelines.

Develop a recursive function to determine the number of distinct ways in which a given amount of money in cents could be changed into quarters, dimes, nickels, and pennies. For example, if the amount is 17 cents, then there are six ways to make changes. Here is the sample output:

1) 1 dime, 1 nickel, and 2 pennies
2) 1 dime and 7 pennies
3) 3 nickels, and 2 pennies
4) 2 nickels, and 7 pennies
5) 1 nickels, and 12 pennies
6) 17 pennies


Here is the function interface:

// precondition: denomination = 1 (for penny), 2 (for nickel), 3 (for dime), or 4 (for quarter).
//
// postcondtion: If amount < 0, then 0 has been returned. Otherwise, the value returned is the
//               number of ways that amount can be changed into coins whose denomination is
//               no larger than denomination
int ways (int amount, int denomination);


For the sake of simplifying the ways function, develop a function coins that return the value of each denomination.

Thus coins(1) returns 1, coins(2) returns 5, coins(3) returns 10, and coins(4) returns 25.

Develop a main driver function that takes the user input of initial amount in cents and outputs the entire number of ways that amount can be changed into quarters, dimes, nickels, and pennies.

Also printout an optimal way (with coin count) that minimize the number of coins for the specified amount of cents.