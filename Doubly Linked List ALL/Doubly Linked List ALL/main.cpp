//
//  main.cpp
//  Doubly Linked List ALL
//
//  Created by Turker Koc on 10.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include "DLList.h"
using namespace std;
void DoublyLinkedList::addToEmpty(int data)
{
    DLLNode *newEl = new DLLNode(data, NULL, NULL);
    if(head == NULL)
    {
        head = tail = newEl;
        return;
    }
    else
    {
        cout<<"Your list is not empty. Call other insertion func."<<endl;
    }
}
void DoublyLinkedList::addToDLLHead(int data)
{
    DLLNode *newEl = new DLLNode(data, NULL, NULL);
    if(head == NULL)
    {
        addToEmpty(data);
        return;
    }
    DLLNode *temp = head;
    head = newEl;
    newEl->next = temp;
    temp->prev = newEl;

}
void DoublyLinkedList::addToDLLTail(int data)
{
    if(head == NULL)
    {
        addToEmpty(data);
        return;
    }
    DLLNode *newEl = new DLLNode(data, NULL, NULL);
    
    DLLNode *temp = tail;
    temp->next = newEl;
    newEl->prev = temp;
    tail = newEl;

}
void DoublyLinkedList::addToDLLMiddle(int data)
{
    if(head == NULL)
    {
        addToDLLHead(data);
        return;
    }
    if(head->next == NULL)
    {
        addToDLLHead(data); //add to head
        return;
    }
    DLLNode *x = head;
    DLLNode *y = head;
    while(y->next != NULL && y->next->next != NULL)
    {
        x = x->next;
        y=y->next->next;
    }
    
    
    DLLNode *xnext = x->next;
    DLLNode *temp = new DLLNode(data,xnext,x);
    
    x->next  = temp;
    xnext->prev = temp;
    
}
void DoublyLinkedList::deleteFromHead()
{
    if(head == NULL)
    {
        cout<<"Your DLL is empty."<<endl;
        return;
    }
    DLLNode *cur = head;
    if(head->next == NULL)
    {
        head = tail = NULL;
        delete cur;
        cur = NULL;
        return;
    }
    head = cur->next;
    head->prev = NULL;
    cur->next = NULL;
    cur->prev = NULL;
    delete cur;
    cur = NULL;
    
}
void DoublyLinkedList::deleteFromTail()
{
    if(tail == NULL)
    {
        cout<<"Your DLL is empty."<<endl;
        return;
    }
    DLLNode *cur = tail;
    if(cur->prev == NULL && cur->next == NULL)
    {
        head = tail = NULL;
        delete cur;
        cur = NULL;
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
    cur->prev = NULL;
    delete cur;
    cur = NULL;
    
    
}
void DoublyLinkedList::printALL() const
{
    DLLNode *temp = head;
    cout<<"Your current DLL: ";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

int main()
{
    
    DoublyLinkedList myDLL;
    myDLL.addToEmpty(5);
    myDLL.printALL();
    
    myDLL.addToDLLHead(2);
    myDLL.printALL();
    
    myDLL.addToDLLTail(3);
    myDLL.printALL();
    
    myDLL.addToDLLMiddle(12);
    myDLL.printALL();
    
    myDLL.addToDLLMiddle(31);
    myDLL.printALL();
    
    myDLL.deleteFromHead();
    myDLL.printALL();
    
    myDLL.deleteFromTail();
    myDLL.printALL();
    return 0;
}
