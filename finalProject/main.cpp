//
//  main.cpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/4/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#include <iostream>
#include "startingMenu.h"

int main() {
    // this will be used on randomly generate contact id
    srand (time(nullptr));
    
    // this is the only function that is going to be used in main
    initialDisplay();

    return 0;
}
