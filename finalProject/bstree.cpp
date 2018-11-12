/* Filename:  BSTree.cpp

   Programmer:  Br. David Carlson

   Date:  October 10, 1997

   Modified:  August 8, 1998.

   Modified:  June 9, 1999 so that ClearTree only tries to do any work
   if the root pointer is non-null.

   This file implements the functions for the BSTClass as set up in
   the header file bstree.h.
*/

#include "bstree.h"
#include "ContactsClass.h" //Bhuwan Added


/* Given:  Nothing,
   Task:   This is the constructor to initialize a binary search tree as empty.
   Return: Nothing directly, but it creates the implicit BSTClass object.
*/
BSTClass::BSTClass(void)
   {
   Root = NULL;
   Count = 0;
   }


/* Given:  Nothing (other than the implicit BSTClass object).
   Task:   This is the destructor.  It's job is to wipe out all data
           storage used by this binary search tree.
   Return: Nothing directly, but the implicit BSTClass object is destroyed.
*/
BSTClass::~BSTClass(void)
   {
   ClearTree();
   }


/* Given:  Nothing (other than the implicit BSTClass object).
   Task:   To clear out all nodes of the implicit binary search tree.
   Return: Nothing directly, but the implicit BSTClass object is modified
           to be an empty binary search tree.
*/
void BSTClass::ClearTree(void)
   {
   if (Root != NULL)
      {
      ClearSubtree(Root);
      Root = NULL;
      Count = 0;
      }
   }


/* Given:  Current   A pointer to a node in the implicit BSTClass object.
   Task:   To wipe out all nodes of this subtree.
   Return: Nothing directly, but the implicit BSTClass object is modified.
*/
void BSTClass::ClearSubtree(BSTNodePtr Current)
   {
   //  Use a postorder traversal:
   if (Current != NULL)
      {
      ClearSubtree(Current->Left);
      ClearSubtree(Current->Right);
      FreeNode(Current);
      }
   }


/* Given:  Item      A data item to place into a new node.
           LeftPtr   The pointer to place in the left field of the node.
           RightPtr  The pointer to place in the right field of the node.
   Task:   To create a new node containing the above 3 items.
   Return: A pointer to the new node.
*/
BSTNodePtr BSTClass::GetNode(const ItemType & Item,
   BSTNodePtr LeftPtr, BSTNodePtr RightPtr)
   {
   BSTNodePtr NodePtr;

   NodePtr = new BSTNodeClass(Item, LeftPtr, RightPtr);
   if (NodePtr == NULL)
      {
      cerr << "Memory allocation error!" << endl;
      exit(1);
      }
   return NodePtr;
   }


/* Given:  NodePtr   A pointer to a node of the implicit binary search tree.
   Task:   To reclaim the space used by this node.
   Return: Nothing directly, but the implicit object is modified.
*/
void BSTClass::FreeNode(BSTNodePtr NodePtr)
   {
   delete NodePtr;
   }


/* Given:  Nothing (other than the implicit BSTClass object).
   Task:   To look up the number of items in this object.
   Return: This number of items in the function name.
*/
int BSTClass::NumItems(void) const
   {
   return Count;
   }


/* Given:  Nothing (other than the implicit BSTClass object).
   Task:   To check if this object (binary search tree) is empty.
   Return: true if empty; false otherwise.
*/
bool BSTClass::Empty(void) const
   {
   if (Count > 0)
      return false;
   else
      return true;
   }


/* Given:  Item   A data item to be inserted.
   Task:   To insert a new node containing Item into the implicit binary
           search tree so that it remains a binary search tree.
   Return: Nothing directly, but the implicit binary search tree is modified.
*/
void BSTClass::Insert(const ItemType & Item)
   {
   BSTNodePtr Current, Parent, NewNodePtr;

   Current = Root;
   Parent = NULL;
   while (Current != NULL)
      {
      Parent = Current;
      if (Item < Current->Info)
         Current = Current->Left;
      else
         Current = Current->Right;
      }

   NewNodePtr = GetNode(Item, NULL, NULL);
   if (Parent == NULL)
      Root = NewNodePtr;
   else if (Item < Parent->Info)
      Parent->Left = NewNodePtr;
   else
      Parent->Right = NewNodePtr;

   Count++;
   }


/* Given:  Item    A data item to look for.
   Task:   To search for Item in the implicit binary search tree.
   Return: A pointer to the node where Item was found or a NULL pointer
           if it was not found.
*/
BSTNodePtr BSTClass::Find(const ItemType & Item) const
   {
   return SubtreeFind(Root, Item);
   }


/* Given:  Current  A pointer to a node in the implicit binary search tree.
           Item     A data item to look for.
   Task:   To search for Item in the subtree rooted at the node Current
           points to.
   Return: A pointer to the node where Item was found or a NULL pointer
           if it was not found.
*/
BSTNodePtr BSTClass::SubtreeFind(BSTNodePtr Current,
   const ItemType & Item) const
   {
   if (Current == NULL)
      return NULL;
   else if (Item == Current->Info)
      return Current;
   else if (Item < Current->Info)
      return SubtreeFind(Current->Left, Item);
   else
      return SubtreeFind(Current->Right, Item);
   }


/* Given:  NodePtr   A pointer to the root of the subtree to be printed.
           Level     Integer indentation level to be used.
   Task:   To print (sideways) the subtree to which NodePtr points, using
           an indentation proportional to Level.
   Return: Nothing.
*/
void BSTClass::PrintSubtree(BSTNodePtr NodePtr, int Level) const
   {
   int k;

   if (NodePtr != NULL)
      {
      PrintSubtree(NodePtr->Right, Level + 1);
      for (k = 0; k < 3 * Level; k++)
         cout << " ";
      cout << NodePtr->Info << endl;
      PrintSubtree(NodePtr->Left, Level + 1);
      }
   }


/* Given:  Nothing (other than the implicit object).
   Task:   To print (sideways) the implicit binary search tree.
   Return: Nothing.
*/
void BSTClass::Print(void) const
   {
   PrintSubtree(Root, 0);
   }





















//Bhuwan implemented code below.
/* Given:  NodePtr   A pointer to the root of the subtree to be printed.
 Level     Integer indentation level to be used.
 Task:   To print (sideways) the subtree to which NodePtr points, using
 an indentation proportional to Level.
 Return: Nothing.
 */

void BSTClass::searchExactAndInsertSubtree(BSTNodePtr NodePtr, vector<ItemType> &result,int field, string content)
{
    //this is recursive in order call but from higher to lower
    if (NodePtr != NULL)
    {
        // search through tree and search only in the intended field.
        // Each case statement will push the ItemType AKA Info in the vector
        // if the search match that ItemType
        searchExactAndInsertSubtree(NodePtr->Right,result,field,content);
        
        switch (field) {
            case 1:{
                string temp = NodePtr->Info.getFirstName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 2:{
                string temp = NodePtr->Info.getMiddleName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 3:{
                string temp = NodePtr->Info.getLastName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 4:{
                string temp = NodePtr->Info.getCompanyName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 5:{
                string temp = NodePtr->Info.getHomePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 6:{
                string temp = NodePtr->Info.getOfficePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 7:{
                string temp = NodePtr->Info.getEmail();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 8:{
                string temp = NodePtr->Info.getMobilePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 9:{
                string temp = NodePtr->Info.getStreetAdd();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 10:{
                string temp = NodePtr->Info.getCity();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 11:{
                string temp = NodePtr->Info.getState();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 12:{
                string temp = NodePtr->Info.getZipCode();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 13:{
                string temp = NodePtr->Info.getCountry();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp == content){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
                
            default:
                break;
        }
        // to the left
        searchExactAndInsertSubtree(NodePtr->Left,result,field,content);
    }

}



void BSTClass::searchExactAndInsert(vector<ItemType> &result)
{
    // user menu to exact search
    int field; // store the field that we are going to search on
    
    string content; // store the content we are going to search in the tree.
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
        cout << "wrong choice, Please enter the valid choice number\n";
        cin >> field;
              
    }
    
    // asking the content they are lookin for
    cout << "Please enter the word/number you are searching on requested field.\n";
    cin.ignore();
    getline (cin, content);
         
    
    //converting content to lower case
    // search will be case insesitive
    transform( content.begin(), content.end(), content.begin(), ::tolower );
    // calling the recursive function.
    searchExactAndInsertSubtree(Root, result,field,content);
}



void BSTClass::searchContainAndInsertSubtree(BSTNodePtr NodePtr, vector<ItemType> &result,int field, string content)
{
    
    
    //this is recursive in order call from higher to lower
    if (NodePtr != NULL)
    {
        // search through tree and search only in the intended field.
        // Each case statement will push the ItemType AKA Info in the vector
        // if the search match that ItemType
        
        searchContainAndInsertSubtree(NodePtr->Right,result,field,content);
        
        switch (field) {
            case 1:{
                
                //finding the name in the ItemType
                string temp = NodePtr->Info.getFirstName();
                //changing it to lower case
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                
                // if searching element is found push back on vector
                // if find function of vector return string::npos, means the content is
                // not found in the name. otherwise past of the name match content.
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 2:{
                string temp = NodePtr->Info.getMiddleName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 3:{
                string temp = NodePtr->Info.getLastName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 4:{
                string temp = NodePtr->Info.getCompanyName();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 5:{
                string temp = NodePtr->Info.getHomePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 6:{
                string temp = NodePtr->Info.getOfficePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 7:{
                string temp = NodePtr->Info.getEmail();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 8:{
                string temp = NodePtr->Info.getMobilePhone();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 9:{
                string temp = NodePtr->Info.getStreetAdd();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 10:{
                string temp = NodePtr->Info.getCity();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 11:{
                string temp = NodePtr->Info.getState();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 12:{
                string temp = NodePtr->Info.getZipCode();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
            case 13:{
                string temp = NodePtr->Info.getCountry();
                transform( temp.begin(), temp.end(), temp.begin(), ::tolower );
                if(temp.find(content) != string::npos){
                    result.push_back(NodePtr->Info);
                }
            }
                break;
                
            default:
                break;
        }
        
        // recursive call to the left.
        searchContainAndInsertSubtree(NodePtr->Left,result,field,content);
    }
    
}



void BSTClass::searchContainAndInsert(vector<ItemType> &result)
{
    // user menu to exact search
    int field;
    string content;
    cout << "choose the field you would like to contain search[1-13]\n";
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
    
    // asking the content they are lookin for
    cout << "Please enter the part of word/number you are searching for on requested field.\n";
    cin.ignore();
    getline(cin,content);
         
    // converting content to lower case
    transform( content.begin(), content.end(), content.begin(), ::tolower );
    
    // calling the function.
    searchContainAndInsertSubtree(Root, result,field,content);
}


BSTNodePtr BSTClass::editNode(ItemType contact){
    BSTNodePtr node;
    
    // finding the poiter to node we want to edit.
    node = Find(contact);
    
    int field; // store the field need to be edited
    string content; // store the string that need to be inserted in required field
    
    // user menu to edit info on node
    cout << "choose the field you would like to edit\n";
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
    
    // switch statement to navigate the user to right field
    // Changing the values.
    switch (field) {
        case 1:{
            cout << "Please enter the new first name\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setFirstName(content);
        }
            break;
        case 2:{
            cout << "Please enter the new middle name\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setMiddleName(content);
        }
            break;
        case 3:{
            cout << "Please enter the new last name\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setLastName(content);
        }
            break;
        case 4:{
            cout << "Please enter the new company name\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setCompanyName(content);
        }
            break;
        case 5:{
            cout << "Please enter the new home phone\n";
            cin.ignore();
            getline(cin,content);
            // just changing the standard phone format.
            // e.g (111)111-1111 from regular input.
            if(content.length() >9){
                content.insert(0,"(");
                content.insert(4,")");
                content.insert(8,"-");
                if(content.length() > 13)
                    content.insert(13," x");
            }

            node->Info.setHomePhone(content);
        }
            break;
        case 6:{
            cout << "Please enter the new office phone\n";
            cin.ignore();
            getline(cin,content);
            // just changing the standard phone format.
            // e.g (111)111-1111 from regular input.

            if(content.length() >9){
                content.insert(0,"(");
                content.insert(4,")");
                content.insert(8,"-");
                if(content.length() > 13)
                    content.insert(13," x");
            }
            node->Info.setOfficePhone(content);
        }
            break;
        case 7:{
            cout << "Please enter the new email\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setEmail(content);
        }
            break;
        case 8:{
            cout << "Please enter the new mobile phone\n";
            cin.ignore();
            getline(cin,content);
            // just changing the standard phone format.
            // e.g (111)111-1111 from regular input.

            if(content.length() >9){
                content.insert(0,"(");
                content.insert(4,")");
                content.insert(8,"-");
                if(content.length() > 13)
                    content.insert(13," x");
            }
            node->Info.setMobilePhone(content);
        }
            break;
        case 9:{
            cout << "Please enter the new streest address\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setStreetAdd(content);
        }
            break;
        case 10:{
            cout << "Please enter the new city\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setCity(content);
        }
            break;
        case 11:{
            cout << "Please enter the new state\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setState(content);
        }
            break;
        case 12:{
            cout << "Please enter the new zip code\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setZipCode(content);
        }
            break;
        case 13:{
            cout << "Please enter the new country\n";
            cin.ignore();
            getline(cin,content);
            node->Info.setCountry(content);
        }
            break;
            
        default:
            break;
    }
    return node;
}

BSTNodePtr BSTClass::editAffiliate(ItemType contact){
    BSTNodePtr node;
    
    // finding the poiter to node we want to edit.
    node = Find(contact);
    
    // user menu to edit info on node
    

    int choice; // menu choice
    string s; // value to be store
    
    // deleting or adding affiliates.
    cout << "What would you like to do with affiliates\n";
    cout << "1: Add.\n";
    cout << "2: Delete.\n";
    cout << "3: Change information.\n";
    cin >> choice;
    
    //menu
    switch (choice) {
        case 1:{
            
            // creating temporary affiliate
            Affiliates temp;
              
            cout << "Enter the first name of Affiliate.\n";
            cin.ignore();
            getline(cin,s);
            temp.firstN = s;
            
            cout << "Enter the last name of Affiliate.\n";
            getline(cin,s);
            temp.lastN = s;
            
            cout << "Enter the phone number of Affiliate.\n";
            getline(cin,s);
            // parsing the user input to standard phone form.
            s.insert(0,"(");
            s.insert(4,")");
            s.insert(8,"-");
            if(s.length() > 13)
                s.insert(13," x");
            temp.phone = s;
            
            cout << "Enter the email of Affiliate\n";
            getline(cin,s);
            temp.AffEmail= s;
            
            // pushing affiliates to node class vector
            node->Info.Aff.push_back(temp);
            cout << "\nAffiliate has been added to the record.\n\n";
        }
            break;
        case 2:{
            cout << "which of the following you would like to delete.\n";
            
            //displaying the list of affiliates.
            
            for (int i = 0; i<node->Info.Aff.size(); ++i) {
                cout << "Affiliate No " <<i+1 << ": \n";
                cout << "Name: "<< node->Info.Aff[i].firstN << ' ' << node->Info.Aff[i].lastN << endl;
                if(node->Info.Aff[i].phone != ""){
                    cout << "Phone: "<< node->Info.Aff[i].phone << endl;
                }
                if(node->Info.Aff[i].phone != ""){
                    cout << "Email: "<< node->Info.Aff[i].AffEmail << endl;
                }
        
            }
            // overriding the previous choce but it's okay though
            cin >> choice;
              
            // deleting the selected affiliates.
            node->Info.Aff.erase(node->Info.Aff.begin()+(choice-1));
            cout << "Affiliate has been deleted from the record \n";
            
        }
        case 3:{
            cout << "which of the following you would like to edit\n";
            
            //displaying the list of affiliates.
            
            for (int i = 0; i<node->Info.Aff.size(); ++i) {
                cout << "Affiliate No. " << i+1 << ": " << endl;
                cout << "Name: "<< node->Info.Aff[i].firstN << ' ' << node->Info.Aff[i].lastN << endl;
                if(node->Info.Aff[i].phone != ""){
                    cout << "Phone: "<< node->Info.Aff[i].phone << endl;
                }
                if(node->Info.Aff[i].phone != ""){
                    cout << "Email: "<< node->Info.Aff[i].AffEmail<< endl;
                }
                
            }
            // givnig optio what field do user want to edit
            cin >> choice;
            cout << "What would you like to change\n";
            cout << "1: First Name\n";
            cout << "2: Last Name\n";
            cout << "3: Phone\n";
            cout << "4: Email\n";
            
            int fieldchoice;
            string fieldcontent; // new info for edited field
            cin >> fieldchoice;
            
            // error prevension
            while (fieldchoice <1 || fieldchoice > 4) {
                cout << "wrong entry please chose the right field\n";
                cin >> fieldchoice;
            }
            
            // making changes accordingly
            switch (fieldchoice) {
                case 1:{
                    cout <<"Please enter the new first name\n";
                    cin.ignore();
                    getline (cin,fieldcontent);
                    node->Info.Aff[choice-1].firstN = fieldcontent;
                }
                    break;
                case 2:{
                    cout <<"Please enter the new last name\n";
                    cin.ignore();
                    getline (cin,fieldcontent);
                    node->Info.Aff[choice-1].lastN = fieldcontent;
                }
                    break;
                case 3:{
                    cout <<"Please enter the new phone\n";
                    cin.ignore();
                    getline (cin,fieldcontent);
                    node->Info.Aff[choice-1].phone = fieldcontent;
                }
                    break;
                case 4:{
                    cout <<"Please enter the new email\n";
                    cin.ignore();
                    getline (cin,fieldcontent);
                    node->Info.Aff[choice-1].AffEmail = fieldcontent;
                }
                    break;
                    
                default:
                    break;
            }
            cout << "Affiliate info has been updated in record\n";
        }

            break;
            
        default:
            break;
    }
    return node;
}

// helping method for the output.
void BSTClass::outputSubtree(BSTNodePtr NodePtr,ostream &output, BSTClass &record, int &counter )
{
    if (NodePtr != NULL)
    {
        
        outputSubtree(NodePtr->Right, output,record,counter);
        output << NodePtr->Info;
        counter++;
        
        // following conditon will prevents the endl on last record while streaming
        if(counter !=Count)
            output << endl;
        outputSubtree(NodePtr->Left, output,record,counter);
    }
}

// outputting the whole stream.
ostream &operator <<(ostream &output, BSTClass &record )
{
    
    int counter=0; // keep track of the nodes
    // recursive call
    record.outputSubtree(record.getRoot(),output,record,counter);
    return output;
}

void BSTClass::printTree(){
    // printing all tree.
   
    // what kind of print
    int type;
    
    // node number.
    int counter=0;
    cout << "How would you like to display the record?[1-2]\n";
    cout << "1: short\n";
    cout << "2: detail\n";
    cin >> type;
    
    // wrong entry prevention
    while(type < 1 || type > 2){
        cout << "Wrong entry, try again";
        cin >>type;
    }
   
    printSubtree(getRoot(),counter, type);
}

void BSTClass::printSubtree(BSTNodePtr NodePtr, int &counter, int type )
{
    if (NodePtr != NULL)
    {
        printSubtree(NodePtr->Right,counter, type);
        // conditional display
        if(type == 1){
            ItemType contact = NodePtr->Info;
            cout <<"Record No."<< counter+1 << ": " << endl;
            cout << "Name: "<< contact.getFirstName() << " "<< contact.getLastName()<<endl;
            cout << "Phone:"<<contact.getMobilePhone() << endl << endl;
        }
        else{
            ItemType contact = NodePtr->Info;
            // outputing all the fields
            cout << "Contact Number: " << counter+1 << endl;
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
        counter++; //increasing the node number
        // recursive call
        printSubtree(NodePtr->Left,counter, type);
    }
}

