//
//  main.cpp
//  Add Node To the Sorted Linked List
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class intSLLNode
{
public:
    intSLLNode()
    {
        next = NULL;
    }
    intSLLNode(int el,intSLLNode *n)
    {
        data = el;
        next = n;
    }
    int data;
    intSLLNode *next;
};


class intSLList
{
public:
    intSLList()
    {
        head = tail = NULL;
    }
    void addToHead(int);
    void printAll();
    void addToSorted(int data);
    
    
private:
    intSLLNode *head,*tail;
};

void intSLList::addToHead(int data)
{
    intSLLNode *newEL = new intSLLNode(data,NULL);
    if(head==NULL&&tail==NULL)
    {
        head = tail = newEL;
        return;
    }
    intSLLNode *temp = head;
    head = newEL;
    newEL->next = temp;
    
}
void intSLList::printAll()
{
    intSLLNode *cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
void intSLList::addToSorted(int data)
{
    intSLLNode *newEL = new intSLLNode(data,NULL);
    if(head==NULL&&tail==NULL)
    {
        head = tail = newEL;
        return;
    }
    if(newEL->data<head->data)
    {
        addToHead(data);
    }
    else if(newEL->data>tail->data)
    {
        tail->next = newEL;
        tail = tail->next;
    }
    else
    {
        intSLLNode *cur = head;
        while(cur->next->data<newEL->data)
            cur = cur->next;
        newEL->next = cur->next;
        cur->next = newEL;
    }
    
}
int main()
{
    intSLList mySLList;
    mySLList.addToHead(5);
    mySLList.addToHead(3);
    mySLList.addToHead(1);
    mySLList.addToHead(-1);
    mySLList.addToHead(-12);
    mySLList.printAll();
    mySLList.addToSorted(5);
    mySLList.printAll();
    return 0;
}
