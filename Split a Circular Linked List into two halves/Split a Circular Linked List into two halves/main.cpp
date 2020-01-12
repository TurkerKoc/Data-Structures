//
//  main.cpp
//  Split a Circular Linked List into two halves
//
//  Created by Turker Koc on 10.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
//************************  intSLList.h  **************************
//           singly-linked list class to store integers

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntCLLNode {
public:
    IntCLLNode()
    {
        next = 0;
    }
    IntCLLNode(int el, IntCLLNode *ptr = 0)
    {
        data = el; next = ptr;
    }
    int data;
    IntCLLNode *next;
};

class IntCLList
{
public:
    IntCLList()
    {
        tail = NULL;
        tail2 =NULL;
    }
    
    int isEmpty()
    {
        return tail == 0;
    }
    
    void addToTail(int);
    void addToBegin(int);
    void addToEmpty(int);
    void deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
    IntCLLNode getHead();
    
    void SplitCLL();
    void printCLL2();
    
    
private:
    IntCLLNode *tail;
    IntCLLNode *tail2;
};

void IntCLList::addToTail(int data)
{
    IntCLLNode *newEl = new IntCLLNode(data,NULL);
    if(tail==NULL)
    {
        tail = newEl;
        newEl->next = newEl;
        return;
    }
    IntCLLNode *temp = tail->next;
    tail->next = newEl;
    tail = newEl;
    newEl->next = temp;
    
}
void IntCLList::addToBegin(int data)
{
    IntCLLNode *newEl = new IntCLLNode(data,NULL);
    if(tail==NULL)
        addToTail(data);
    else
    {
        IntCLLNode *temp = tail->next;
        tail->next = newEl;
        newEl ->next = temp;
        
    }
    
}
void IntCLList::addToEmpty(int data)
{
    IntCLLNode *newEl = new IntCLLNode(data,NULL);
    
    if(tail==NULL)
    {
        tail = newEl;
        newEl->next = newEl;
        return;
    }
    else
    {
        cout<<"Your list is not empty. Call other insertion func."<<endl;
    }
}
void IntCLList::deleteFromTail()
{
    IntCLLNode *prev = NULL;
    IntCLLNode *cur = tail->next;
    while(cur != tail)
    {
        prev = cur;
        cur = cur->next;
    }
    if(prev == NULL)
    {
        tail = NULL;
        delete cur;
    }
    else
    {
        prev->next = tail->next;
        tail = prev;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
    
}
void IntCLList::printAll() const  //starting from tail
{
    IntCLLNode *temp = tail->next;
    if(tail==NULL)
    {
        cout<<"Yout circular list is empty."<<endl;
        return;
    }
    
    cout<<"Your current circular list: ";

    while(temp != tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<temp->data<<" ";

    cout<<endl;
    
}
void IntCLList::deleteNode(int data)
{
    IntCLLNode *prev = tail;
    IntCLLNode *cur = tail->next;
    
    if(tail->data == data)
    {
        deleteFromTail();
    }
    else
    {
        while(cur != tail)
        {
            if(cur->data == data)
            {
                prev->next = cur->next;
                cur->next =NULL;
                delete cur;
                cur = NULL;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        cout<<data<<" does not appear in yout list."<<endl;
    }
    
}
bool IntCLList::isInList(int data) const
{
    IntCLLNode *cur = tail->next;
    while(cur != tail)
    {
        if(cur->data == data)
            return true;
        cur = cur->next;
    }
    return false;
}


void IntCLList::SplitCLL()
{
    if(tail==NULL)
    {
        cout<<"Your CLL is empty."<<endl;
        return;
    }
    if(tail->next == NULL)
    {
        cout<<"Your list has 1 element."<<endl;
        return;
    }
    //first find length of the CLL
    int length = 1;
    IntCLLNode *temp = tail->next;
    while(temp != tail)
    {
        temp=temp->next;
        length++;
    }
    int mid = length/2;
    temp = tail;
    for(int i=0;i<mid;i++)
        temp=temp->next;
    tail2 = temp;
    IntCLLNode *start2 = tail2->next;
    tail2->next = tail->next;
    tail->next = start2;
    
    
    
}
void IntCLList::printCLL2()
{
    IntCLLNode *temp = tail2->next;
    if(tail2==NULL)
    {
        cout<<"Yout circular list is empty."<<endl;
        return;
    }
    
    cout<<"Your current circular list: ";
    
    while(temp != tail2)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<temp->data<<" ";
    
    cout<<endl;
}
#endif




int main()
{
    IntCLList myCLList;
    myCLList.addToTail(1);
    myCLList.addToTail(2);
    myCLList.addToTail(3);
    myCLList.addToTail(4);
    myCLList.addToTail(5);

    myCLList.printAll();
    
    myCLList.SplitCLL();
    cout<<"First CLL: "<<endl;
    myCLList.printCLL2();

    
    cout<<"Second CLL: "<<endl;
    myCLList.printAll();

    

    return 0;
}
