//
//  startingMenu.cpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/7/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#include "startingMenu.h"
#include "functions.h"


void initialDisplay(){
   
    // creating the balanced tree that will contain main database
    AVLClass record;
    
    // this vector will store search results
    // either it is searched from the tree or from vector itself.
    vector<ItemType> result;
    
    // variable for menu
    int choiceInt = -1; // just to enter the while loop
    
    //initial promt.
    cout << "Welcome to the contact database management system\n";
    cout << "_________________________________________________\n";
    
    while(choiceInt != 0){
        
        // main menu
        cout << "Please choose from the following menu [0-7].\n";
        cout << "1: Load database from default file.\n";
        cout << "2: Load database from new file.\n";
        cout << "3: Search and Edit the record\n";
        cout << "   (This will include:\n";
        cout << "    -Adding/Editing/Deleting affiliates from record.\n";
        cout << "    -Editing record itself after search.\n";
        cout << "    -Exporting the searched result to data file.)\n";
        cout << "4: Add a new contact in record.\n";
        cout << "5: Save database to default file.\n";
        cout << "6: Export database to new file.\n";
        cout << "7: Display all record from database.\n";
        cout << "0: Exit.\n";
        
        cin >> choiceInt;
        
        // little warning before exit and option to cancel exit
        if (choiceInt == 0){
            char yesNO;
            cout << "WARNING!! if you have not saved your updated(if any) record.\n";
            cout << "Please save the record using menu 5 or 6\n";
            cout << "To cancel exit, enter[n].\n";
            cout << "Do you wish to exit the program?[y/n]\n";
            cin >> yesNO;
            if(toupper(yesNO) !='Y')
                choiceInt = -1;
            else
                cout << "Thank you very much. HAVE A WONDERFUL DAY!!!!\n";
        }
        
        
        //swich menu based on choice
        switch (choiceInt) {
                    // loads from default file
            case 1:{readFromFile(record);
                    if(record.getRoot() != NULL)
                        cout << "Database is succesfully loaded from file\n\n";
                    else
                        cout << "\nFile reading error!!. check your file and try again\n\n";                }
                    break;
            
                    // loads from user file
            case 2:{readFromUserFile(record);
                    if(record.getRoot() != NULL)
                        cout << "Database is succesfully loaded from file\n\n";
                    else
                        cout << "\nFile reading error!!. check your file and try again\n\n";
                    }
                    break;
               
                    // search in the tree and vector
            case 3:{if(record.getRoot() !=NULL){
                    searchingEditingSaving(record, result);
                    // clear the search result since may carry privious result
                    // for next result
                    // and it only needed to store searched result.
                    result.clear();
                    }
                    else
                        cout << "\nRecord is empty. Please load data first using menu 1 or 2\n\n";
                    }
                    break;
               
                    // adds new contact in record.
            case 4:{insertFromUser(record);}
                    break;
                
                    //saves updated tree to default database file
            case 5:{if(record.getRoot() !=NULL){
                    writeToDatabaseFromTree(record);
                        cout << "\nRecord is succesfully saved to dafault file\n\n";
                    }
                    else
                        cout << "\nRecord is empty. Please load data first using menu 1 or 2\n\n";
                    }
                    break;
                    //saves updated tree to user database file
            case 6:{
                    if(record.getRoot() !=NULL){
                        writeToUserFileFromTree(record);
                    }
                    else
                        cout << "\nRecord is empty. Please load data first using menu 1 or 2\n\n";
                    }
                    break;
            
                    //displays the total tree
            case 7:{if(record.getRoot() !=NULL){
                    printFromTree(record);
                    }
                    else
                        cout << "\nRecord is empty. Please load data using menu 1 or 2\n\n";
                    }
                    break;
            
            default:
                    break;
        }
        
    }
   
}
    