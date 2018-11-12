//
//  functions.cpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/7/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#include "functions.h"

void readFromFile( AVLClass &record ){
    // input file stream
    ifstream input("database.txt",ios::in);
    
    // reading and writing to the tree until the end
    while (input.good()) {
        ItemType temp;
        input >> temp;
        record.Insert(temp);
    }
    input.close();
}

void readFromUserFile ( AVLClass &record ){
    //file name
    string fileName;
    
    cout << "Please enter the file name that you would like to load from\n";
    cin.ignore();
    getline(cin,fileName);
    // input file stream
    ifstream input(fileName,ios::in);
    
    // reading and writing to the tree until the end
    while (input.good()) {
        ItemType temp;
        input >> temp;
        record.Insert(temp);
    }
    input.close();
}

void writeToUserFileFromTree(AVLClass record){
    string fileName;
    ofstream output;
    cout << "Please enter the file name that you would like to save all database\n";
    cout << "File will be automatically saved to the \".TXT\" format\n";
    cin.ignore();
    getline(cin, fileName);
    
    //opening the file
    output.open(fileName +=".txt",ios::out);
    output << record;
    cout << "Your record is succesfully saved to the file \"" << fileName <<"\"" << endl;
    output.close();
    
}

void writeToDatabaseFromTree(AVLClass record){
    
    // writing whole tree in default database file
    ofstream output;
    output.open("database.txt",ios::out);
    output << record;
    output.close();
}

void searchContainInTree(AVLClass &record, vector<ItemType> &result){
    //calling the function in AVLClass that search contains in tree and store it in vector
    record.searchContainAndInsert(result);
}

void searchExactIntree(AVLClass &record, vector<ItemType> & result){
    //calling the function defined on bsttree class
    record.searchExactAndInsert(result);
}

void searchTree(AVLClass &record, vector<ItemType> & result){
    // combination of above two  function
    
    int choice;
    cout << "What kind of search you would like to perform?[1-2]\n";
    cout << "1: Exact\n";
    cout << "2: Contain\n";
    cin >> choice;
    
    // error prevention
    while (choice >2 || choice <1) {
        cout << "Wrong choice!\n";
        cout << "What kind of search you would like to perform?[1-2]\n";
        cout << "1: Exact\n";
        cout << "2: Contain\n";
        cin >> choice;
    }
    
    // direct towards right function call
    switch (choice) {
        case 1:
            searchExactIntree(record, result);
            break;
        case 2:
            searchContainInTree(record, result);
            break;
        default:
            break;
    }
}

// this function will search within vector and return
// change the vector to newly searched vector
// old data will be cleared.
void searchExact(vector<ItemType> &result){
    
    // this will be the vector that will hold searched record
    // end of the function result will be cleared and result vector will be assigned from
    //temporary vector.
    vector<ItemType> temporary;
    
    // user menu to exact search
    int field;
    string content;
    cout << "choose the field you would like to search[1-13]\n";
    cout << " 1: First Name\n";
    cout << " 2: Middle Name\n";
    cout << " 3: Last Name\n";
    cout << " 4: Company Name\n";
    cout << " 5: Home Phone\n";
    cout << " 6: Office Phone\n";
    cout << " 7: Email\n";
    cout << " 8: Mobile Phone\n";
    cout << " 9: Street Address\n";
    cout << " 10: City\n";
    cout << " 11: state\n";
    cout << " 12: Zip Code\n";
    cout << " 13: Country\n";
    cin >> field;
    
    // wrong entry prevention
    while(field > 13 || field < 1){
        cout << "wrong choice, Please enter the valid choice number.\n";
        cin >> field;
    }
    
    // asking the content they are lookin for
    cout << "Please enter the word/number you are searching for on requested field.\n";
    cin.ignore();
    getline(cin,content);
    
    //converting to lower case
    
    transform( content.begin(), content.end(), content.begin(), ::tolower );
    
    //goint through the vector to do the sub search.
    for (int i = 0; i < result.size(); ++i) {
        switch (field) {
            case 1:{
                string temp = result[i].getFirstName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 2:{
                string temp = result[i].getMiddleName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }

            }
                break;
            case 3:{
                string temp = result[i].getLastName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 4:{
                string temp = result[i].getCompanyName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 5:{
                string temp = result[i].getHomePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 6:{
                string temp = result[i].getOfficePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 7:{
                string temp = result[i].getEmail();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 8:{
                string temp = result[i].getMobilePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }

            }
                break;
            case 9:{
                string temp = result[i].getStreetAdd();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 10:{
                string temp = result[i].getCity();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 11:{
                string temp = result[i].getState();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 12:{
                string temp = result[i].getZipCode();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 13:{
                string temp = result[i].getCountry();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp == content){
                    temporary.push_back(result[i]);
                }
            }
                break;
                
            default:
                break;
        }

    }
    result.clear();
    result = temporary;
}

// this function will search within vector and return
// change the vector to newly searched vector
// old data will be cleared.

void searchContain(vector<ItemType> &result){
    
    // this will be the vector that will hold searched record
    // end of the function result will be cleared and copy temporaty to result vector
    vector<ItemType> temporary;

    // user menu to exact search
    int field;
    string content;
    cout << "choose the field you would like to search[1-13]\n";
    cout << " 1: First Name\n";
    cout << " 2: Middle Name\n";
    cout << " 3: Last Name\n";
    cout << " 4: Company Name\n";
    cout << " 5: Home Phone\n";
    cout << " 6: Office Phone\n";
    cout << " 7: Email\n";
    cout << " 8: Mobile Phone\n";
    cout << " 9: Street Address\n";
    cout << " 10: City\n";
    cout << " 11: state\n";
    cout << " 12: Zip Code\n";
    cout << " 13: Country\n";
    cin >> field;
    
    // wrong entry prevention
    while(field > 13 || field < 1){
        cout << "wrong choice, Please enter the valid choice number.\n";
        cin >> field;
    }
    
    // asking the content they are lookin for
    cout << "Please enter the part of word/number you are searching for on requested field.\n";
    cin.ignore();
    getline(cin,content);
    
    //converting to lower case
    
    transform( content.begin(), content.end(), content.begin(), ::tolower );
    
    //goint through the vector to do the sub search.
    for (int i = 0; i < result.size(); ++i) {
        switch (field) {
            case 1:{
                string temp = result[i].getFirstName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 2:{
                string temp = result[i].getMiddleName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 3:{
                string temp = result[i].getLastName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 4:{
                string temp = result[i].getCompanyName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 5:{
                string temp = result[i].getHomePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 6:{
                string temp = result[i].getOfficePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 7:{
                string temp = result[i].getEmail();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 8:{
                string temp = result[i].getMobilePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 9:{
                string temp = result[i].getStreetAdd();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 10:{
                string temp = result[i].getCity();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 11:{
                string temp = result[i].getState();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 12:{
                string temp = result[i].getZipCode();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
            case 13:{
                string temp = result[i].getCountry();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // push the value if it match the search
                if(temp.find(content) != string::npos){
                    temporary.push_back(result[i]);
                }
            }
                break;
                
            default:
                break;
        }
        
    }
    result.clear();
    result = temporary;
}

// this function is the combination of above two function
void searchInSearch(vector<ItemType> & result){
    
    int choice;
    cout << "What kind of search within the search you would like to perform\n";
    cout << "1: Exact\n";
    cout << "2: Contain\n";
    
    // error prevension
    while (choice < 1 || choice > 2) {
        cout << "Wrong entry try again!\n";
        cout << "What kind of search within the search you would like to perform\n";
        cout << "1: Exact\n";
        cout << "2: Contain\n";
    }
    cin >> choice;
    
    // calling the right function
    switch (choice) {
        case 1:
            searchExact(result);
            break;
        case 2:
            searchContain(result);
            break;
        default:
            cout << "Exiting without doing anything";
            break;
    }
}

void sortVector(vector<ItemType> & result)
{
    // user menu for the sort field
    int field;
    cout << "choose the field you would like to sort on[1-13]\n";
    cout << " 1: First Name\n";
    cout << " 2: Middle Name\n";
    cout << " 3: Last Name\n";
    cout << " 4: Company Name\n";
    cout << " 5: Home Phone\n";
    cout << " 6: Office Phone\n";
    cout << " 7: Email\n";
    cout << " 8: Mobile Phone\n";
    cout << " 9: Street Address\n";
    cout << " 10: City\n";
    cout << " 11: state\n";
    cout << " 12: Zip Code\n";
    cout << " 13: Country\n";
    cin >> field;
    
    // wrong entry prevention
    while(field > 13 || field < 1){
        cout << "wrong choice, Please enter the valid choice number\n";
        cin >> field;
    }

    // this function will sort vector based on field number

   sort(result.begin(),result.end(), [field] (ItemType a, ItemType b){
       if(field == 1)
           return (a.getFirstName() < b.getFirstName());
       if(field == 2)
           return (a.getMiddleName() < b.getMiddleName());
       if(field == 3)
           return (a.getLastName() < b.getLastName());
       if(field == 4)
           return (a.getCompanyName() < b.getCompanyName());
       if(field == 5)
           return (a.getHomePhone() < b.getHomePhone());
       if(field == 6)
           return (a.getOfficePhone() < b.getOfficePhone());
       if(field == 7)
           return (a.getEmail() < b.getEmail());
       if(field == 8)
           return (a.getMobilePhone() < b.getMobilePhone());
       if(field == 9)
           return (a.getStreetAdd() < b.getStreetAdd());
       if(field == 10)
           return (a.getCity() < b.getCity());
       if(field == 11)
           return (a.getState() < b.getState());
       if(field == 12)
           return (a.getZipCode() < b.getZipCode());
       if(field == 13)
           return (a.getCountry() < b.getCountry());
       return false;

   });
    
}

void saveToFileByField(vector<ItemType> result){
   
    // array contain what field will be stremed to the user
    bool field[14];
    for (int j = 0; j <14; ++j) {
        field[j] = false;
    }
    //user will input the numbers with space
    // it will read as a string and parse to indivisual number
    // to set the field array index true
    int value;
    string entry;
    string fileName;
    
    //file stream to output file.
    ofstream output;
    cout << "Please enter the file name that you want to save the record with only info you would like\n";
    cout << "You don't have to enter the file extension.\n";
    cin.ignore();
    getline(cin,fileName);
    output.open(fileName+=".txt");
    
    // user menu for the print field
    cout << "Choose the fields from record that you would like to save to your file.[1 to 13]\n";
    cout << "   e.g, 5 12 6\n";
    cout << " Entry need to be seperated by space\n";
    cout << " 1: First Name\n";
    cout << " 2: Middle Name\n";
    cout << " 3: Last Name\n";
    cout << " 4: Company Name\n";
    cout << " 5: Home Phone\n";
    cout << " 6: Office Phone\n";
    cout << " 7: Email\n";
    cout << " 8: Mobile Phone\n";
    cout << " 9: Street Address\n";
    cout << " 10: City\n";
    cout << " 11: state\n";
    cout << " 12: Zip Code\n";
    cout << " 13: Country\n";
    cout << " 14: Affiliates\n";
    getline(cin,entry);
    
    stringstream ss(entry);
    while (ss.good()) {
        ss >> value;
        if(value > 14 || value < 1){
            cout << "There was a wrong entry, please start again\n";
            return;
        }
        field[value-1] = true;
    }
    
    // streaming will depends on what index is true in the field array.
    for (int i= 0; i < result.size(); ++i) {
        output << i+1 << ":" << endl;
        if(field[0]== true)
            output << result[i].getFirstName() << endl;
        if(field[1]== true)
            output << result[i].getMiddleName() << endl;
        if(field[2]== true)
            output << result[i].getLastName() << endl;
        if(field[3]== true)
            output << result[i].getCompanyName() << endl;
        if(field[4]== true)
            output << result[i].getHomePhone() << endl;
        if(field[5]== true)
            output << result[i].getOfficePhone() << endl;
        if(field[6]== true)
            output << result[i].getEmail() << endl;
        if(field[7]== true)
            output << result[i].getMobilePhone() << endl;
        if(field[8]== true)
            output << result[i].getStreetAdd() << endl;
        if(field[9]== true)
            output << result[i].getCity() << endl;
        if(field[10]== true)
            output << result[i].getState() << endl;
        if(field[11]== true)
            output << result[i].getZipCode() << endl;
        if(field[12]== true)
            output << result[i].getCountry() << endl;
        
        // streaming affiliates
        if(field[13]== true){
            for(int k = 0; k < result[i].Aff.size(); ++k){
                output << result[i].Aff[k].firstN << ' ' << result[i].Aff[k].lastN;
                if(result[i].Aff[k].phone != ""){
                    output << ','<< result[i].Aff[k].phone;
                }
                if(result[i].Aff[k].phone != ""){
                    output << ','<< result[i].Aff[k].AffEmail;
                }
                output << ';' << endl;
            }
        }
        output << endl;
    }
    cout << "record is succesfully saved on your file name \"" << fileName <<"\""<< endl;
    
}

void saveToFile(vector<ItemType> result){
    string fileName;
    
    //file stream to output file.
    ofstream output;
    cout << "Please enter the file name that you want to save the record with only info you would like\n";
    cout << "You don't have to enter the file extension.\n";
    
    //file name
    cin.ignore();
    getline(cin,fileName);
    output.open(fileName+".txt");
    
    for (int i=0; i < result.size()-1; ++i) {
        output << result[i] << endl;
    }
    // this will ensure last record will not have endl;
    for (int j = (result.size()-1); j <result.size(); ++j) {
        output << result[j];
    }
    cout << "record is succesfully saved on your file name \"" << fileName <<"\""<< endl;
}

void editRecord(AVLClass &record, vector<ItemType> &result, int index){
    
    int choice;
    cout << "Detail of the record you are going to edit\n";
    
    // displaying indivisual record in detail what is going to be changed
    printContact(result[index]);
    
    //what kind of change in record
    cout << "What would like to do with following record?\n";
    cout << "1: edit the personal information in record\n";
    cout << "2: add/delete or change the affiliates information\n";
    cin >> choice;
    
    
    // wrong entry prevention
    while(choice > 2 || choice < 1){
        cout << "wrong choice, Please enter the valid choice number\n";
        cout << "What would like to do with following record?\n";
        cout << "1: edit the personal information in record\n";
        cout << "2: add/delete or change the affiliates information\n";
        cin >> choice;
    }

    
    switch (choice) {
        
        // following statements not only edit the records on tree but also update same
            // record in searched vector.
        case 1:{
            //casting to AVLNodePtr from BSTNodePtr
            AVLNodePtr temp = static_cast<AVLNodePtr> (record.editNode(result[index]));
            temp->GetInfo(result[index]);
        }
            break;
        case 2:{
            AVLNodePtr temp = static_cast<AVLNodePtr> (record.editAffiliate(result[index]));
            temp->GetInfo(result[index]);
        }
            break;
        default:
            break;
    }
}

void insertFromUser(AVLClass &record){
    
    // creating temp record
    ItemType temp;
    
    // This may go to inifinity loop if there is no room in record
    // or all 9 digit IDs are  occupied
    // This should not be a problem in this assignemnt since this is a requirement
    // of assignment
    while(record.Find(temp) !=NULL){
        // create temporary record and assign to temp so it will change the random ID
        // and check if that exist in the record. since record check presense only based on ID
        // it will keep creating new record until unique ID is created by ContactClass constructor
        ItemType temp1;
        temp = temp1;
    }
    
    //creating new affiliate
    Affiliates affiliate;
    string info;
    
    cout << "Please enter the First Name" << endl;
    cin.ignore();
    getline(cin,info);
    temp.setFirstName(info);
    
    cout << "Please enter the Middle Name" << endl;
    getline(cin,info);
    temp.setMiddleName(info);

    cout << "Please enter the Last Name" << endl;
    getline(cin,info);
    temp.setLastName(info);

    cout << "Please enter the Company Name" << endl;
    getline(cin,info);
    temp.setCompanyName(info);

    cout << "Please enter the Home Phone" << endl;
    // parsing the user input to standard phone form.
    getline(cin,info);
    if(info.length() >9){
        info.insert(0,"(");
        info.insert(4,")");
        info.insert(8,"-");
        if(info.length() > 13)
            info.insert(13," x");
    }
    
    temp.setHomePhone(info);

    cout << "Please enter the Office Phone" << endl;
    getline(cin,info);
    // parsing the user input to standard phone form.
    if(info.length() >9){
        info.insert(0,"(");
        info.insert(4,")");
        info.insert(8,"-");
        if(info.length() > 13)
            info.insert(13," x");
    }
    temp.setOfficePhone(info);

    cout << "Please enter the Email" << endl;
    getline(cin,info);
    temp.setEmail(info);

    cout << "Please enter the Mobile Phone" << endl;
    getline(cin,info);
    // parsing the user input to standard phone form.
    if(info.length() > 9){
        info.insert(0,"(");
        info.insert(4,")");
        info.insert(8,"-");
        if(info.length() > 13)
            info.insert(13," x");
    }
    temp.setMobilePhone(info);

    cout << "Please enter the street address" << endl;
    getline(cin,info);
    temp.setStreetAdd(info);

    cout << "Please enter the City Name" << endl;
    getline(cin,info);
    temp.setCity(info);

    cout << "Please enter the State Name" << endl;
    getline(cin,info);
    temp.setState(info);

    cout << "Please enter the Zip Code" << endl;
    getline(cin,info);
    temp.setZipCode(info);

    cout << "Please enter the Country Name" << endl;
    getline(cin,info);
    temp.setCountry(info);
    
    cout << "Would you like to add affiliates[y/n]\n";;
    
    char choice;
    cin >> choice;
    while (tolower(choice) == 'y') {
        // creating temporary affiliate
        
        cout << "Enter the first name of Affiliate\n";
        cin.ignore();
        getline(cin,info);
        affiliate.firstN = info;
        
        cout << "Enter the last name of Affiliate\n";
        getline(cin,info);
        affiliate.lastN = info;
        
        cout << "Enter the phone number of Affiliate\n";
        getline(cin,info);
        // parsing the user input to standard phone form.
        if(info.length() >9){
            info.insert(0,"(");
            info.insert(4,")");
            info.insert(8,"-");
            if(info.length() > 13)
                info.insert(13," x");
        }
            affiliate.phone = info;
        
        cout << "Enter the email of Affiliate\n";
        getline(cin,info);
        affiliate.AffEmail= info;
        
        // pushing affiliates to Aff vector of ContactClass
        temp.Aff.push_back(affiliate);
        cout << "Would you like to add affiliates[y/n]\n";
        cin >> choice;
    }
    
    record.Insert(temp);
    cout << "Record has been succesfully addeded to the database\n";
}


void printSearch(vector<ItemType> result){
    // printing all vector with field name
    for (int i = 0; i < result.size(); ++i) {
        cout << "Record No."<< i+1 << ")" << endl;
        cout << "Name: " <<result[i].getFirstName() << " " << result[i].getLastName() << endl;
        cout << "Phone: " <<result[i].getMobilePhone() << endl << endl;
    }
}

void searchingEditingSaving(AVLClass &record, vector<ItemType> & result){
        
        char choiceChar; // variale for choices below;
        
        // searching withing the tree
        // following function will have its own promts
        searchTree(record, result);
        
        // if search vector is empty
        if(result.size() == 0){
            cout << "No record is found to match your search\n";
            cout << "Would you like to search again[y/n]\n";
            cin >> choiceChar;
            
            // as long as user want to keep searching let them search
            while (toupper(choiceChar) == 'Y') {
                searchTree(record, result);
                if(result.size() == 0){
                    cout << "No record is found to match your search\n";
                    cout << "Would you like to search in database again\n[y/n]";
                    cin >> choiceChar;
                    if(toupper(choiceChar) != 'Y')
                        break;
                }
                else {
                    cout << "list of the matched result\n";
                    cout << "__________________________\n";
                    
                    //printing the result only name and cell phone.
                    printSearch(result);
                    
                    cout << "Would you like to display above record in detail?[y/n]\n";
                    
                    cin >> choiceChar;
                    if(toupper(choiceChar) == 'Y')
                        printSearchDetail(result);
                    // asking if they want different search on database
                    cout << "Would you like to do fresh search in the database.\n";
                    cout << "If you do fresh search current search result will be lost.[y/n]\n";
                    cin >> choiceChar;
                    if(toupper(choiceChar) != 'Y')
                        break;
                }
                
            }
        }
            // asking user for search withing the search if search vector has something
            if(result.size() != 0){
                printSearch(result);
                
                cout << "Would you like to display above record in detail?[y/n]\n";
                cin >> choiceChar;
                if(toupper(choiceChar) == 'Y')
                    printSearchDetail(result);

                // searching withing the search
                cout << "Would you like to search within the search? [y/n]\n";
                cin >> choiceChar;
                while(toupper(choiceChar) == 'Y'){
                    searchInSearch(result);
                    if(result.size() == 0){
                        cout << "No record is found to match your search\n";
                        break;
                    }
                    else{
                        cout << "Search Result\n";
                        cout << "______________\n";
                        // simple print
                        printSearch(result);
                        
                        // detail print of the search
                        cout << "Would you like to display above record in detail?[y/n]\n";
                        cin >> choiceChar;
                        if(toupper(choiceChar) == 'Y')
                            printSearchDetail(result);

                        cout << "Would you like to search within the search?[y/n]\n";
                        cin >> choiceChar;
                    }
                }
            }
            
            // editing the records including editing and deleting affiliates of record.
            // deleting a record is not allowed.
            if(result.size() !=0){
                cout << "Would you like to edit the record from your search?[y/n]\n";
                cin >> choiceChar;
                while(toupper(choiceChar) == 'Y'){
                    
                    // for the record number
                    int recordNo;
                    cout << "List of record you will able to edit.\n";
                    
                    //simple print
                    printSearch(result);
                    
                    // print detail
                    cout << "Would you like to display above record in detail?[y/n]\n";
                    cin >> choiceChar;
                    if(toupper(choiceChar) == 'Y')
                        printSearchDetail(result);
                    
                    // choice to edit the data
                    cout << "Please choose from above which record you like to edit.";
                    cout << "[1-" << result.size() << "]\n";
                    cin >> recordNo;
                    if(recordNo >result.size() ||recordNo <1){
                        cout << "Wrong entry!!! please choose the right one.\n";
                        cin >> recordNo;
                    }
                    
                    // editining the requested index in vector and tree
                    editRecord(record, result, recordNo-1);
                    cout << "Updated record is as follows.\n";
                    printContact(result[recordNo-1]);
                    
                    // giving another choice to edit
                    cout << "Would you like to edit another record from your search?[y/n]\n";
                    cin >> choiceChar;
                        
                }
                
            }
    
    // if user want to sort based on their peference
        if(result.size() != 0){
            cout << "Would you like to sort your search according to your perference?[y/n]\n";
            cin >> choiceChar;
            
            // if they want to search
            if(toupper(choiceChar)=='Y'){
                sortVector(result);
                cout << "Your search is sorted accordingly,\n";
                
                //simple print
                printSearch(result);
                
                //detail print if user want
                cout << "Would you like to display above record in detail?[y/n]\n";
                cin >> choiceChar;
                if(toupper(choiceChar) == 'Y')
                    printSearchDetail(result);

            }
           
        }
    
    // saving the searched data if user want
        if (result.size() != 0) {
            
            cout << "Would you like to save the search to your data file?\n";
            cout << "If you don't save the data, it will be lost[y/n]\n";
            cin >> choiceChar;
            
            // if they want to save
            if(toupper(choiceChar)=='Y'){
                int saveType;
                cout << "How would you like to save the file[1-2]\n";
                cout << "1: Everything in records\n";
                cout << "2: Only selected fields from record\n";
                cin >> saveType;
                
                // detail save or selected field save
                if (saveType == 1)
                    
                    // calling function
                    saveToFile(result);
                if (saveType == 2)
                    
                    // calling function
                    saveToFileByField(result);
                
                // display saved resutl
                printSearch(result);
                
                // display saved result in detail if user want
                cout << "Would you like to display above record in detail?[y/n]\n";
                cin >> choiceChar;
                if(toupper(choiceChar) == 'Y')
                    printSearchDetail(result);

            }

        }
}

void printFromTree(AVLClass &record){
    // calling print function on AVLClass
    record.printTree();
 
}

// Displaying a single contact with field name.
void printContact(ItemType contact){
    
    cout << "Name:        " << contact.getFirstName()<<" ";
    cout << contact.getMiddleName() <<" "<< contact.getLastName() << endl;
    cout << "Company:     " <<contact.getCompanyName() << endl;
    cout << "Home Phone:  " <<contact.getHomePhone() << endl;
    cout << "Office Phone:" <<contact.getOfficePhone() << endl;
    cout << "Email:       " <<contact.getEmail() << endl;
    cout << "Mobel Phone: " <<contact.getMobilePhone() << endl;
    cout << "st. Address  " <<contact.getStreetAdd() << endl;
    cout << "City:        "<< contact.getCity()<< endl;
    cout << "State:       "<< contact.getState() << endl;
    cout << "ZipCode      "<< contact.getZipCode() << endl;
    cout << "Country      "<< contact.getCountry() << endl;
    
    // outputing all affiliates until they are availabe in affiliate vector
    cout << "Affiliates:\n";
    for (int i = 0; i < contact.Aff.size(); ++i) {
        cout <<"        Name: " << contact.Aff[i].firstN << ' ' << contact.Aff[i].lastN << endl;
        if(contact.Aff[i].phone != ""){
            cout << "       Phone: "<< contact.Aff[i].phone << endl;
        }
        if(contact.Aff[i].phone != ""){
            cout << "       Email: "<< contact.Aff[i].AffEmail << endl;
        }
    }
    cout << endl;
}

// Displaying whole record in vector using above function.
void printSearchDetail(vector<ItemType> &result){
    for (int i = 0; i < result.size(); ++i) {
        cout << "Record No. " << i+1 << endl;
        printContact(result[i]);
    }
}