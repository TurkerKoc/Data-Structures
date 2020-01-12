//
//  DLList.h
//  Doubly Linked List ALL
//
//  Created by Turker Koc on 10.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#ifndef DLList_h
#define DLList_h
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = 0;
    }
    DLLNode(int el, DLLNode* n, DLLNode* p)
    {
        data = el;
        next = n;
        prev = p;
    }
    int data;
    DLLNode *next, *prev;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = tail = 0;
    }
    bool isEmpty() const
    {
       return head==0;
    }

    void addToDLLTail(int);
    void addToEmpty(int);
    void addToDLLHead(int);
    void addToDLLMiddle(int);
    void deleteFromTail();
    void deleteFromHead();
    void printALL() const;
private:
    DLLNode *head, *tail;
};



#endif /* DLList_h */
