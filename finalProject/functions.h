//
//  functions.hpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/7/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "avlnode.h"
#include "avltree.h"
#include "ContactsClass.h"

using namespace std;

// reading the default data file and storing them in record AVLtree
void readFromFile(AVLClass &record);

// reading the data file and storing them in record AVLtree
void readFromUserFile(AVLClass &record);

// writing the data file to user defined file
void writeToUserFileFromTree(AVLClass record);

// writing the date to main database from tree
// which would update any changes user has made.
void writeToDatabaseFromTree(AVLClass record);

// to search in the tree and store in vector
void searchExactIntree(AVLClass &record, vector<ItemType> & result);

// to search in the tree and store in vector
void searchContainInTree(AVLClass &record, vector<ItemType> &result);

//this function will ask user what kind of search they would like to use
// and uses above two functions.
void searchTree(AVLClass &record, vector<ItemType> & result);

//exact search in vector
void searchExact(vector<ItemType> &result); // to search in vector

//contain search in vector
void searchContain(vector<ItemType> &result); // to serch in vector

//this function will ask user what kind of search they would like to use
// and uses above two functions.
void searchInSearch(vector<ItemType> & result);

// this function sort the vector according to user need.
// promts are inside the function.
void sortVector(vector <ItemType> & result);

// this function output to the file from vector according to user need.
// promts are inside the function.
void saveToFileByField(vector<ItemType> result);

// this function will output print whole vector to the file
void saveToFile(vector<ItemType> result);

//this functions will edit record in the tree and update the vector
// which will include to edit/delete the affiliates.
void editRecord(AVLClass &record, vector<ItemType> &result, int index);

// this function will collect the data from user and insert in the tree.
void insertFromUser(AVLClass &record);

// printing vector
void printSearch(vector<ItemType> result);

// printing tree name and cell phone only
void printFromTree(AVLClass &result);

//searching from the tree and doing more search/ editing nodes on tree
//printing and so on
// following function may use one or more function above.
void searchingEditingSaving(AVLClass &record, vector<ItemType> & result);

// this function the single contact in console with field names
void printContact(ItemType contact);

// this function will vector of contanct  in console with field name
void printSearchDetail(vector<ItemType> &result);

#endif /* functions_h */
