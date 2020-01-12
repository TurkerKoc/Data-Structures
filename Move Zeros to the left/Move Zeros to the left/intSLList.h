//
//  intSLList.h
//  Singly Linked List All
//
//  Created by Turker Koc on 9.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//


#ifndef intSLList_h
#define intSLList_h
#include <iostream>
using namespace std;

class IntSLLNode
{
public:
    IntSLLNode()
    {
        next = NULL;
    }
    typedef int ElementType;
    ElementType data;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = 0;
    }
    //~IntSLList();
    int isEmpty()
    {
        return head == 0;
    }
    void printAll() const;
    void addToHead(int);
    void addToSecond(int data);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its data;
    int deleteFromSecond(); // delete the second and return its data;
    int  deleteFromTail(); // delete the tail and return its data;
    void deleteNode(int);  //find the given element if it is exist delete it
    void deleteNodePosition(int); //if the given position exist delete it
    bool isInList(int) const;
    IntSLLNode getHead();
    int getLength();
    

    
private:
    IntSLLNode *head, *tail;
};

void IntSLList::printAll() const
{
    IntSLLNode *temp = head;
    if(head == NULL)
        cout<<"Your Linked List is empty."<<endl;
    else
    {
        cout<<"Your Current List: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
void IntSLList::addToHead(int data)
{
    IntSLLNode *temp = head;
    IntSLLNode *newEl = new IntSLLNode();
    newEl->data = data;
    newEl->next = NULL;
    
    if(head==NULL) //if the list is empty.
    {
        head=newEl;
        return;
    }
    head = newEl;
    newEl->next = temp;
    
}
void IntSLList::addToSecond(int data)
{
    IntSLLNode *temp = head;
    IntSLLNode *newEl = new IntSLLNode();
    newEl->data = data;
    newEl->next = NULL;
    if(head==NULL || head->next == NULL) //if there are 0 or 1 element add to head.
        addToHead(data);
    else
    {
        temp = temp->next;
        head->next = newEl;
        newEl->next = temp;
    }
}
void IntSLList::addToTail(int data)
{
    IntSLLNode *temp = head;
    IntSLLNode *newEl = new IntSLLNode();
    newEl->data = data;
    newEl->next = NULL;
    if(head == NULL)
        addToHead(data);
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEl;
    }
}
int IntSLList::deleteFromHead() //delete and return the element
{
    IntSLLNode *temp = head;
    int delEl;
    if(head == NULL)
        return -1;
    
    
    head = temp->next;
    temp->next = NULL;
    
    delEl = temp->data;
    delete temp;
    temp = NULL;
    return delEl;
}
int IntSLList::deleteFromTail()
{
    IntSLLNode *cur = head;
    IntSLLNode *prev = NULL;
    int delEl;
    if(head == NULL || head->next == NULL)
        return deleteFromHead();
    while(cur->next != NULL)
    {
        prev = cur;
        cur=cur->next;
    }
    prev->next = cur->next;
    delEl = cur->data;
    delete cur;
    cur = NULL;
    return delEl;
}
int IntSLList::deleteFromSecond()
{
    IntSLLNode *cur = head;
    int delEl;
    if(head == NULL || head->next == NULL)
        return deleteFromHead();
    cur = head->next;
    head->next = cur->next;
    delEl = cur->data;
    delete cur;
    return delEl;
}
void IntSLList::deleteNode(int data)
{
    IntSLLNode *cur = head;
    IntSLLNode *prev = NULL;
    if(cur->data == data)
    {
        deleteFromHead(); 
        return;
    }
    prev = cur;
    cur = cur->next;
    while(cur != NULL)
    {
        if(cur->data == data)
        {
            prev->next = cur->next;
            delete cur;
            cur = NULL;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout<<"Your element does not appear in this list."<<endl;
}

void IntSLList::deleteNodePosition(int pos)
{
    IntSLLNode *cur = head;
    IntSLLNode *prev = NULL;
    if(head == NULL)
    {
        cout<<"Your list is empty"<<endl;
        return;
    }
    if(pos==1)
    {
        head = head->next;
        delete cur;
        cur = NULL;
        return;
    }
    for(int i=1;i<pos;i++)
    {
        if(cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            cout<<"There are not "<<pos<<" positions in your list"<<endl;
            return;
        }
    }
    prev->next = cur->next;
    delete cur;
    cur = NULL;
}

bool IntSLList::isInList(int data) const
{
    IntSLLNode *temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}


IntSLLNode IntSLList::getHead()
{
    return *head;
}

int IntSLList::getLength()
{
    IntSLLNode *temp = head;
    int length=0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}


#endif /* intSLList_h */
