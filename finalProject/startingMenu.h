//
//  startingMenu.hpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/7/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#ifndef startingMenu_hpp
#define startingMenu_hpp

#include "avltree.h"
#include "ContactsClass.h" // this also include affiliate struct.
#include "functions.h"

//This function will display the main menu based on switch statment
// more or less of following
//1. read from file ( this will read and store data on avl tree)
//2. search in tree (this will have two sub menu, exact search and contain search on user defined field)
//3. Add new contact
//4. write to file (this will ask the file name to save and write in the file)

// in addition this will define avl tree

void initialDisplay();

// all the functions that will be called in this function will be on functions.h
// some function will have sub functions to read, write, display and search

#endif /* startingMenu_h */
