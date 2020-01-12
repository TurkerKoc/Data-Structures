//
//  main.cpp
//  Circular Linked List ALL
//
//  Created by Turker Koc on 10.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include "intCLL.h"
using namespace std;

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
    IntCLLNode *temp = tail;
    if(tail==NULL)
    {
        cout<<"Yout circular list is empty."<<endl;
        return;
    }
    
    cout<<"Your current circular list: ";
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp != tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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
int main()
{
    IntCLList myCLList;

    myCLList.addToEmpty(12);
    myCLList.printAll();

    myCLList.addToTail(3);
    myCLList.printAll();

    myCLList.addToTail(2);
    myCLList.printAll();

    myCLList.addToTail(5);
    myCLList.printAll();
    
    myCLList.addToBegin(9);
    myCLList.printAll();
    
    myCLList.addToEmpty(12);
    
    myCLList.deleteFromTail();
    myCLList.printAll();

    myCLList.deleteNode(12);
    myCLList.printAll();
    
    myCLList.deleteNode(67);
    
    bool check = myCLList.isInList(9);
    if(check)
        cout<<"Yes it is in your CLL."<<endl;
    else
        cout<<"No it is not in your CLL."<<endl;
    return 0;
}
