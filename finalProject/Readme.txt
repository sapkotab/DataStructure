Final Project
Overview
The Final Project is to develop a simple database system. The database is to handle multiple records, each composed of several fields.  The database will store its information to a file, addition and deletion of records, field modifications, and it will allow users to sort records based on the selected keys, and produce reports (output) according to predefined criteria.

Some definitions:
A database is a collection of information, or data, that you can organize, update, sort, search through, and print as needed.  A database does not just hold information; you use a database to organize and analyze information so that you understand its significance.
A database file consists of one or more records.  Each record holds all the information about one subject item.  In C++, the class data type provides an efficient way to represent and manipulate records.
Each piece of information in a record is called a field.  Fields store the data that has been entered or calculated.  In C++ parlance, fields are nothing more than the member variables defined for a particular class.
Given the requirements as a rough specification, you're supposed to design the class and implement the database. So you can consider the requirements below as an outcome from a meeting with a client. You are in full control of the choice of data structures (except the main data structure of AVL tree, more detail below), algorithms, internal file format, and detailed user interface scheme. 

You're designing and implementing a database for an address book. Users should be able to browse, search their contacts, by any field (last name, first name, zip code etc.) from the database, and organize their chosen contacts to their liking and print out a report.  Each contact information includes followings:

Unique ID number. ID is a 9 digit number
First name
Middle name (or initial)
Last name
Company name  
Home phone
Office phone
Email
Mobile number
Street address
City
State
Zip code
Country
List of affiliates (such as family members or associates name). Each affiliate has first name, and last name.  They may have one individual mobile phone number and one email. Note that all affiliates will share the rest of the contact info, and you need to make sure that the shared info is not duplicated. The total number of affiliates is unknown.
Requirements
Database overall management

Use a text based menu for users to choose available features. Program should have a main menu at the beginning and sub menus depending on the task.
You should allow users to read and write data to a text-based database file. The format of the text-based database file is following:
All information is stored in ASCII text format.
Records are divided by a | character
Each field is distinguished by a new line.
Submit a sample data file  with at least 50 records. (Let's post at least 10 contacts (not necessarily real personal info, imaginary contacts) on the final project Q&A and share)
When reading from a data file, your program must test the input file to ensure that data is of valid format (basic error detection).
The database is primarily organized with the ID# as a key. You have to use AVL tree for the base data structure.  
Each component of the overall program should be fairly modular.
Each menu item, for example, should be a separate function. The menu feature should be handled by a separate function and not by main( ).
Program should be fairly fault tolerant of user input (both when the user is entering data, and making menu choices).  Provide appropriate user prompts and on-screen directions
Split the program into multiple files based on the roughly categorized functionality.
Data Retrieval and Modification

Users should be able to search records based on the field information in two modes: exact and contains. For example, search contacts by last name "Smith", search contacts with an email domain name that contains "ucdenver", etc.  So in the search sub menu, users have to pick the search mode and field. Of course users should type in the search item.
Quite often, search may generate a relatively big output. Users should be able to search again within the search result (secondary search) or start all over again from scratch (new search).
Since the entire data is structures in a AVL tree with the ID# key, any search (except using ID#) should traverse the entire tree.
Users should be able to delete a record. So, in the delete record sub menu, users should be able to search and pick a delete candidate record. After deletion, the AVL tree should be rebalanced.
Users should be able to modify fields in a record, with the same condition above. 
Users should be able to insert new records. There should be no restriction to the number of records in the database. So, in other words, you should not consider a fixed array for the record data structure.
Users can modify records, so the user should be able to write back to file (overwrite to current file or to a new file name similar to "save as").  
Output Generation

Output generation is responsible for the re-organizing the final result to a user's liking by displaying appropriate fields and sorted records. The final output is a report in ASCII-text format.
After a series of data retrieval and modification, finally there is a list of contacts to be an output. Users should be able to further organize the contact and convey them to the output by choosing only the fields they want to print in desired order. So users should be able to pick fields to be finally shown in the output. And users should be able to sort the final output contacts by selecting a field as a key.
Users should be able to perform a secondary sorting with the second sort key (e.g., sort by company name, and then last name).
Output file generation in text file format.
Users should be able to generate a report output in ASCII text format. Note that this output file is different from the database file in ASCII text format.
Keep in mind that an output may not include all fields and records.
Submission Guideline
You need to submit following items (all zipped together): 

Source code with reasonable comments
Makefile that works (and is tested) on the csegrid.
A final report that includes:
Summary of provided functions. This should be matched with the requirements
Design document that shows the overall program structures, and the explanation of key algorithms. A description of user interface scheme is required to explain the menu items at top level and items in sub menus and how to navigate through menus. A detailed instruction and sample skeleton is available from Design Document.Preview the document
Accurate status of the program, what's done, and what's not completely implemented.
Accurate status of testing on the csegrid.
The final report should be in MS Word, or PDF format. 
Note:  You must use the following AVL code for your AVL tree.  You may not use every function associated with this code.  You should not need to change this code, but you will need to read it to see something that is included that may need to be added.
avlnode.cppPreview the document

avlnode.hPreview the document

avltree.cppPreview the document

avltree.hPreview the document

bstnode.cppPreview the document

bstnode.hPreview the document

bstree.cppPreview the document

bstree.hPreview the document

itemtype.hPreview the document

and then a driver file to show you how to use these files:

avltest.cppPreview the document

Grading Criteria
Submitting a working program that provides all of the required features will result in a maximum grade of 80%.
Documentation explained above will result in 20% of the grade.
Any or all of the following will result in point deductions of up to 5% for each infraction.
Poor and/or inconsistent programming style.  This includes the following:
Improper use of indentation.
Overuse of global variables.
Failure to keep functions modular and reusable (possibly applicable to other programs).
Insufficient comments.
Insufficient menu prompts
Program is not reasonably( not absolutely) fault tolerant.
Test to ensure that your program cannot be crashed or sent into an infinite loop by a user who is not following directions.
Include a reasonable input file integrity check. Rejecting any non-conforming file is fine. You need to provide a sample database file with at least 50 records. 
Partial credit may be awarded.
You may get partial credit for non-working modules (functions) by explaining (in the separate document) where you think the problem lies.
Up to 10% could be lost for each required feature that is not provided.
Submitting a program that does not compile on csegrid.ucdenver.pvt may result in a deduction of at least 30%.  Additional points will be lost for each required feature that is not adequately addressed. 
Q & A
Q: What's the input file format?

A: Something like this

ID#
First name 
Middle name 
Last name
Company name   
Home phone
Office phone
Email
Mobile number
Street address 
City
State
Zip code 
Country
Affiliate name 1;  (this can be family members, office affiliates, etc.)
Affiliate name 2,  own phone number, own email;  
Affiliate name 3; 
Affiliate name 4,  own phone number, own email;  (number of affiliates are unknown)

(each affiliate is delimited by ;. In case an affiliate has its own phone number and own email, those are delimited by comma , . )

| <- record divider
 

next record starts here.

First name
Middle name
Last name....
 

For this final project, we can reasonably assume that every record has every field information. But just in case, for instance someone does not have a mobile number, fill up the field with "NULL" string.

 

Q: Assignment states that "A database file consists of one or more records." Does it mean that database is not allowed to be empty (zero records)?

A: Well, if there's no record, then it's not a database either. Allowing it as a database or not is a matter of a program design decision. You may think that you can create a database file first (building the structures) and add records one by one. But until it gets the first record, it doesn't serve as a database, except it has record structures. So I assume that there should be at least one record to make a database.
You can make your program to take a database file with at least a record as an input parameter. Otherwise, it simply stops running.

Q: The following requirement seems backwards:
Records are divided by a | character…Each field is distinguished by a new line.
Shouldn’t it be:
FIELDS are divided by a | character…Each RECORD is distinguished by a new line.

A: No. If you put the entire record in one line, it could be very long and the word-wrap in a window would make the document very hard to read on typical text editors. Technically, there's nothing wrong with your scheme, though. But having a special character at the end of contact list (which is the end of the record) may make the programming a little easier.
 

Q: Should the final report be one document or a series of documents?

A: One MS word or pdf document.
 

Q: Do we need to give our users an ability to search on any field of the contacts? Should we also give the ability to search on everything including affiliates?

A: Yes, search (both exact and contain) function should be equally applied to all fields including affiliates. If your search function finds a target in the list of affiliates, assume that all main contact info is shared except for those people who have their own phone numbers and emails. For example, you're searching for a person with last name "Smith". The main database may not include someone with "Smith" but "Smith" could be found from affiliates of one or multiple records. 
 

Q: Do we have to provide an infinite number of sub-searches? The assignment describes a requirement that we need to allow 1 sub-search. Do we have to have allow an infinite number of them?
 

A: Sub-searches, either it's the first level or further refined, should be same. Once you get the first search done, the current search result becomes another dataset from which you should be able to perform the first sub-search. Then the result of this routine should be in a same format just like the original search. So given the same format of dataset, you should be able to run the exactly same sub-searches, more like a recursion.   

Q: The project says: Users should be able to search records based on the field information in two modes: exact and contains. For example, search contacts by last name "Smith", search contacts with an email domain name that contains "cudenver", etc.  So in the search sub menu, users have to pick a search mode and field, as well as the search key. 

What a contact company is "first level technology" and the user typed "first technology" . Does "first level technology" contain "first technology" or not?

Or, to be considered contained it has to be ether "first level" or "level technology" or "first level technology"?
 

A: I consider "first level technology" does not contain "first technology" since we're operating a string matching, not word by word containment relations.

 

 

Q: When a user modifies a record, can s/he change the number of affiliates on a particular contact? or only existing fields can be modified? Can the user delete a particular affiliate from the contact record?

A: Yes to both questions. Normally it's a super-user's job but for this project we consider all users have the privileges.
 

Q: what's the format of the report that to be displayed on the screen?
 

A: Table format with the column/row alignment is fine.


Q: When a user deletes records what happens to the affiliates?

A: Delete a record means delete an entire contact information including all affiliates.

