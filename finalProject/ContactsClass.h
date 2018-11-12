//
//  ContactsClass.h
//  finalProject
//
//  Created by bhuwan sapkota on 4/4/16.
//  Copyright © 2016 bhuwan sapkota. All rights reserved.
//

#ifndef ContactsClass_hpp
#define ContactsClass_hpp

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// this will create unique id if needed while adding in the tree from user


struct Affiliates{
    string firstN;
    string lastN;
    string phone;
    string AffEmail;
    //constructor that will create empty affiliate.
    Affiliates():firstN(""),lastN(""),phone(""),AffEmail(""){}
};

class ContactsClass{
    private:
        int __ID;
        // contact informations
        // all field will be string even though some of them are number because
        // we are not going to any mathematical manipulation
        // and it will be easier to search in string ( I thing I have to use cstring but it will work)
        string  __firstName;
        string  __middleName;
        string  __lastName;
        string  __companyName;
        string  __homePhone;
        string  __officePhone;
        string  __email;
        string  __mobilePhone;
        string  __streetAdd;
        string  __city;
        string  __state;
        string  __zipCode;
        string  __country;
    
    
    public:


    
        // afficiates will be stored in vector if the person has any otherwise it will be empty
        vector <Affiliates> Aff;
        //constructor
        
        ContactsClass();
        
        //setters
        
        //void setID(int ID); we don't need this one.
        
        void setFirstName(string firstName);
        void setMiddleName(string middleName);
        void setLastName(string lastName);
        void setCompanyName(string companyName);
        void setHomePhone(string homePhone);
        void setOfficePhone(string officePhone);
        void setEmail (string email);
        void setMobilePhone(string mPhone);
        void setStreetAdd(string stAdd);
        void setCity(string city);
        void setState (string state);
        void setZipCode (string zip);
        void setCountry (string country);
        
        //getters
        int    getID();
        string getFirstName();
        string getMiddleName();
        string getLastName();
        string getCompanyName();
        string getHomePhone();
        string getOfficePhone();
        string getEmail ();
        string getMobilePhone();
        string getStreetAdd();
        string getCity();
        string getState ();
        string getZipCode();
        string getCountry();
        
        
        //overloading insertion and extraction operator to read and write from/to file
        friend ostream &operator<<(ostream &, const ContactsClass &);
        friend istream &operator>>(istream &, ContactsClass &);
        
        //overloading comparision operators to give the sorting order in binary tree
        friend bool operator==(const ContactsClass &, const ContactsClass &);
        friend bool operator<(const ContactsClass &, const ContactsClass &);
    };
#endif /* ContactsClass_hpp */
