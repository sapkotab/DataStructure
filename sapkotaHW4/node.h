/*******************************************************
 *  Name      :    Bhuwan Sapkota
 *  Student ID:   101101219
 *  Class     :  CSC 2421
 *  HW#       :  4
 *  Due Date  :  Feb. 17, 201
 *******************************************************/

#ifndef NODE_H
#define NODE_H

#include <cstdlib>  //needed for NULL
#include <string>
using namespace std;
namespace HW4 {
    
    class node {
    public:
        // Node data type
        typedef string dataType;
        
        //Default Constructor
        node();
        
        //Constructor
        node(const dataType &newData, node * new_ptr);
        
        //Accessor Functions
        dataType getData() const;
        node* getNextPtr();
        const node* getNextPtr() const;
        
        // Mutator Functions
        void setData( const dataType &newData);
        void setNextPtr(node * newNextPtr);
        
        
        
    private:
        dataType data;
        node* nextPtr;
    };  //End of Class
    
    /****************************************
     Non-member functions
     The Textbook chooses to make these functions instead of member functions.  This is a style call. I would have probably made them member functions, but kept them this way to match your book code.  Note that since they are not member functions, you will need to use member accessor and mutator functions in your code!
     *****************************************/
    /*Returns value of the length of the list*/
    int listLength(const node* headPtr);
    
    /*Inserts a single node at the front of a list*/
    void insertAtFront(node*& headPtr,const node::dataType &newData);
    
    /*Inserts a single node just after the pointer sent in the parameter */
    void insertAfterNode(node* previous_ptr,const node::dataType &newData);
    
    /*Removes a node at the front of the list */
    void removeAtFront(node*& head_ptr);
    
    /*Remove a single node just after the pointer sent in the parameter*/
    void removeAtNode(node* previous_ptr);
    
    /*Displays to the stream listed, an entire list from the pointer location to the end of the list*/
    void printList(ostream &stream, node* headPtr);
    
   
    
}  //End of Namespace

#endif