#ifndef LIST_H
#define LIST_H
//#include "LinkedList_structNode_Exceptions.h"
#include "LinkListException.h
typedef int ListItemType;
//typedef desired-type-of-list-item ListItemType;

/** @class List
* ADT list - Pointer-based implementation. */
class List
{
public:
// Constructors and destructor:

  /** Default constructor. */
  List();

  /** Copy constructor.
    * @param aList The list to copy. */
  List(const List& aList);

  //overload the assignment operator
  List operator=(const List&  rhs);
  /** Destructor. */
  ~List();

// List operations:
  bool isEmpty() const;
  int getLength() const;
  void insert(int index, const ListItemType& newItem)
      throw(ListIndexOutOfRangeException, ListException);
  void remove(int index)
      throw(ListIndexOutOfRangeException);
  void retrieve(int index, ListItemType& dataItem) const
      throw(ListIndexOutOfRangeException);
  void reverse(int);
  //overload the << operator: idea is similar to the find()
  friend ostream & operator << (ostream & out, const List & aList);

private:
  /** A node on the list. */
  struct ListNode
  {
      /** A data item on the list. */
      ListItemType item;
      /** Pointer to next node. */
      ListNode    *next;
  }; // end ListNode

  /** Number of items in list. */
  int      size;
  /** Pointer to linked list of items. */
  ListNode *head;

  /** Locates a specified node in a linked list.
    * @pre index is the number of the desired node.
    * @post None.
    * @param index The index of the node to locate.
    * @return A pointer to the index-th node. If index < 1
    *        or index > the number of nodes in the list,
    *        returns NULL. */
  ListNode *find(int index) const;
}; // end List
// End of header file.

#endif // LINKLISTSTRUCT_H
/*
    single linkList
    head = temp // link the temp node to the head
    head=>[ 71|next]
    temp => [50|null]
    temp->next = head
    temp ->[50|next]->[71|null]
    head = temp
    head->[50|next]->[71|null]
    traverse the List list;
    ListNode * cur = head;
    while(cur != NULL)
        cout << cur << " ":
        cur = cur->next;    // linking the pointer to the next mode in the List
        }
        insert at a specificed location (temp)[ |]
        ....(pre)[ |]->(cur)[ |]->[ |]....
        temp->next = prev->next
        prev->next = temp;

    delete a Node in the list
    pre->next = toDel->next
    delete toDel;
    Inheritance are based on shared relationship between two classes
    A Student class and a Person class both share some similarity of the two thus inheritance
    class Student: public Person     (Parent class (Person), Base or child class (Student)
    the sintext of inheritance
    virtual is related to polymorism
    "virtual" is the key words to impliment the polymorism function.
    the implementation will determine whether the specified function is a parent class or a child class
    the friend function declaration cannot access the private data of the define class of data members which are private to the class.
*/

