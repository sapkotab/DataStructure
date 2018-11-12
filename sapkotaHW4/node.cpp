/*******************************************************
*  Name      :    Bhuwan Sapkota
*  Student ID:   101101219
*  Class     :  CSC 2421
*  HW#       :  4
*  Due Date  :  Feb. 17, 201
*******************************************************/

#include <iostream>
#include <string>
#include "node.h"
using namespace std;

// default constructor
HW4::node::node()
{
    data = dataType();
    nextPtr = nullptr;
}
//constructor
HW4::node::node(const dataType & newData, node * new_ptr )
{
    data = newData;
    nextPtr = new_ptr;
}

//getters
HW4::node::dataType HW4::node::getData() const
{
    return data;
}

HW4::node * HW4::node::getNextPtr()
{
    return nextPtr;
}

const HW4::node * HW4::node::getNextPtr() const
{
    return nextPtr;
}

//setters

void HW4::node::setData(const node::dataType &newData)
{
    data = newData;
}

void HW4::node::setNextPtr(node * newNextPtr)
{
    nextPtr = newNextPtr;
}

// fuction that find the length of linked list;

int HW4::listLength(const node *headPtr)
{
    const node * cursor;
    int answer = 0;
    for (cursor = headPtr; cursor != nullptr; cursor = cursor->getNextPtr())
        ++answer;
    
    return answer;
}

// function that insert the node at front

void HW4::insertAtFront(node* & headPtr, const node::dataType &newData)
{
    headPtr =new node(newData,headPtr);
}

// function that insert after node

void HW4::insertAfterNode(node *previous_ptr, const node::dataType &newData)
{
    node *insert_ptr;
    
    insert_ptr = new node(newData, previous_ptr->getNextPtr());
    previous_ptr->setNextPtr(insert_ptr);
   
}

// function that remove the front node

void HW4::removeAtFront(node *&head_ptr)
{
    node *remove_ptr;
    remove_ptr = head_ptr;
    head_ptr = head_ptr->getNextPtr();
    delete remove_ptr;
}

// function that remove node after given pointer

void HW4::removeAtNode(node *previous_ptr)
{
    node *remove_ptr;

    remove_ptr = previous_ptr->getNextPtr();
    previous_ptr->setNextPtr(remove_ptr->getNextPtr());
    
    delete remove_ptr;
}

// print everything in the linked list

void HW4::printList(ostream &stream, node *headPtr)
{
    node * cursor;

    for (cursor = headPtr; cursor!= nullptr; cursor = cursor->getNextPtr())
    {
        cout << cursor->getData() << endl;
    }
}

