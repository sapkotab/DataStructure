/* Filename:  bstree.h

   Programmer:  Br. David Carlson

   Date:  October 10, 1997

   Modified:  August 8, 1998.

   Modified:  June 9, 1999 to make AVLClass a friend of BSTClass.

   This is the header file to accompany bstree.cpp.  It provides the
   BSTClass as shown below.
*/

#ifndef BSTREE_H
#define BSTREE_H

#include "bstnode.h"


class BSTClass
   {
   private:
      BSTNodePtr GetNode(const ItemType & Item,
         BSTNodePtr LeftPtr = NULL, BSTNodePtr RightPtr = NULL);
      void FreeNode(BSTNodePtr NodePtr);
      void ClearTree(void);
      void ClearSubtree(BSTNodePtr Current);
      BSTNodePtr SubtreeFind(BSTNodePtr Current,
         const ItemType & Item) const;
      void PrintSubtree(BSTNodePtr NodePtr, int Level) const;
      // The following data fields could be made protected instead of
      // private.  This would make them accessible to the derived AVLClass
      // without making AVLClass a friend of BSTClass.
      BSTNodePtr Root;
      int Count;
   public:
      BSTClass(void);
      ~BSTClass(void);
      int NumItems(void) const;
      bool Empty(void) const;
      void Insert(const ItemType & Item);
      //  Some sort of Remove method could also be added, but
      //  it would require effort to remake the binary search tree
      //  after the deletion of a node.
      BSTNodePtr Find(const ItemType & Item) const;
      void Print(void) const;
      friend class AVLClass;
       
       
       //Bhuwan added function
       // for exact search
       void searchExactAndInsert(vector<ItemType> &result);
       void searchExactAndInsertSubtree(BSTNodePtr NodePtr,vector<ItemType> &result, int field, string content);
       // for contain search.
       void searchContainAndInsert(vector<ItemType> &result);
       void searchContainAndInsertSubtree(BSTNodePtr NodePtr,vector<ItemType> &result, int field, string content);
       // edit the info and return the pointer
       
       BSTNodePtr editNode(ItemType contact);
       BSTNodePtr editAffiliate(ItemType contact);
       
       // following functions are for outputing the data from tree.
       void outputSubtree(BSTNodePtr NodePtr,ostream &output, BSTClass &record, int &counter);
       friend ostream &operator << (ostream &output, BSTClass &record );
       
       // just a regular console display
       void printSubtree(BSTNodePtr NodePtr, int &counter, int kind );
       void printTree();
       
       // returns the root
       BSTNodePtr getRoot(){return Root;}
   };

#endif


