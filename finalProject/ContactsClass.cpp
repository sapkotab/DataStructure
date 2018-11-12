//
//  ContactsClass.cpp
//  finalProject
//
//  Created by bhuwan sapkota on 4/4/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#include "ContactsClass.h"


ContactsClass::ContactsClass() {
    
    // create random 9 digit id. not nessarily a unique in terms of database.
    // But insertFromUser function in function.cpp/h will have a condition that will
    // prevent from having duplicate IDs in different record.
    __ID = rand()%900000000+100000000;
    
    // everything will be blank.
    __firstName = "";
    __middleName = "";
    __lastName = "";
    __companyName = "";
    __homePhone = "";
    __officePhone = "";
    __email = "";
    __mobilePhone = "";
    __streetAdd = "";
    __city = "";
    __state = "";
    __zipCode = "";
    __country = "";
    
}



// setters for all field exept affiliates.

void ContactsClass::setFirstName(string firstName) {
    __firstName = firstName;
}

void ContactsClass::setMiddleName(string middleName) {
    __middleName = middleName;
}

void ContactsClass::setLastName(string lastName) {
    __lastName = lastName;
}

void ContactsClass::setCompanyName(string companyName) {
    __companyName = companyName;
}

void ContactsClass::setHomePhone(string homePhone) {
    __homePhone = homePhone;
}

void ContactsClass::setOfficePhone(string officePhone) {
    __officePhone = officePhone;
}

void ContactsClass::setEmail(string email) {
    __email = email;
}

void ContactsClass::setMobilePhone(string mPhone) {
    __mobilePhone = mPhone;
}

void ContactsClass::setStreetAdd(string stAdd) {
    __streetAdd = stAdd;
}

void ContactsClass::setCity(string city) {
    __city = city;
}

void ContactsClass::setState(string state) {
    __state = state;
}

void ContactsClass::setZipCode(string zip) {
    __zipCode = zip;
}

void ContactsClass::setCountry(string country) {
    __country = country;
}

// getter member functions for each field.
int ContactsClass::getID() {
    return __ID;
}

string ContactsClass::getFirstName() {
    return __firstName;
}

string ContactsClass::getMiddleName() {
    return __middleName;
}

string ContactsClass::getLastName() {
    return __lastName;
}

string ContactsClass::getCompanyName() {
    return __companyName;
}

string ContactsClass::getHomePhone() {
    return __homePhone;
}

string ContactsClass::getOfficePhone() {
    return __officePhone;
}

string ContactsClass::getEmail() {
    return __email;
}

string ContactsClass::getMobilePhone() {
    return __mobilePhone;
}

string ContactsClass::getStreetAdd() {
    return __streetAdd;
}

string ContactsClass::getCity() {
    return __city;
}

string ContactsClass::getState() {
    return __state;
}

string ContactsClass::getZipCode() {
    return __zipCode;
}

string ContactsClass::getCountry() {
    return __country;
}

ostream &operator<<(ostream & output, const ContactsClass & contact) {
    
    // outputing all the fields
    output << contact.__ID << endl;
    output << contact.__firstName << endl;
    output << contact.__middleName << endl;
    output << contact.__lastName << endl;
    output << contact.__companyName << endl;
    output << contact.__homePhone << endl;
    output << contact.__officePhone << endl;
    output << contact.__email << endl;
    output << contact.__mobilePhone << endl;
    output << contact.__streetAdd << endl;
    output << contact.__city << endl;
    output << contact.__state << endl;
    output << contact.__zipCode << endl;
    output << contact.__country << endl;
    
    // outputing all affiliates until they are availabe in affiliate vector
    for (int i = 0; i < contact.Aff.size(); ++i) {
        output << contact.Aff[i].firstN << ' ' << contact.Aff[i].lastN;
        if(contact.Aff[i].phone != ""){
            output << ","<< contact.Aff[i].phone;
        }
        if(contact.Aff[i].phone != ""){
            output << ","<< contact.Aff[i].AffEmail;
        }
        output << ";" << endl;
    }
    
    // deliminiter for one record.
    output << "|";
    return output;
}

istream &operator>>(istream & input,ContactsClass & contact) {
    
    input >> contact.__ID;
    
//    // following three step will keep id generator with unique number.
//    --contact.id_Generator;     //since program generated ID is not used, rewind it and check the validity
//    if(contact.id_Generator <= contact.__ID)
//        contact.id_Generator = contact.__ID+1; // making the id biggest among IDs
//    
    // reading all the personal info
    input.ignore();
    getline(input,contact.__firstName);
    getline(input,contact.__middleName);
    getline(input,contact.__lastName);
    getline(input,contact.__companyName);
    getline(input,contact.__homePhone);
    getline(input,contact.__officePhone);
    getline(input,contact.__email);
    getline(input,contact.__mobilePhone);
    getline(input,contact.__streetAdd);
    getline(input,contact.__city);
    getline(input,contact.__state);
    getline(input,contact.__zipCode);
    getline(input,contact.__country);
    
    // affiliate part
    string tempLine;
    getline(input,tempLine); // reading next line
    while (tempLine != "|"){  // this will never go to the loop if next line is '|'
        
        Affiliates tempAff;
        stringstream line(tempLine); // stringstream based on alreaded read tempLine
        string lineWithoutSemicolon;
        getline(line,lineWithoutSemicolon,';');
        stringstream ss(lineWithoutSemicolon);
        
        getline (ss,tempAff.firstN, ' '); // reading name

        getline(ss,tempAff.lastN,','); // reading last name before comma
        
        // reading phone and email if they exist.
        if(!ss.eof()){
            getline(ss,tempAff.phone,',');
        }
        if(!ss.eof()){
            getline(ss,tempAff.AffEmail,';');
        }
        
        contact.Aff.push_back(tempAff);// pushing the affiliates to the vector.
        getline(input,tempLine); // reading another affiliates or '|'.
    }
    return input;
}

// comparing record based on ID
bool operator==(const ContactsClass & lhs, const ContactsClass & rhs) {
    bool equal = false;
    if(lhs.__ID == rhs.__ID){
        equal = true;
    }
    return equal;
}

// comparing record based on ID
bool operator<(const ContactsClass & lhs, const ContactsClass & rhs) {
    bool equal = false;
    if(lhs.__ID < rhs.__ID){
        equal = true;
    }
    return equal;
}



