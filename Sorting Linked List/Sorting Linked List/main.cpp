//
//  main.cpp
//  Sorting Linked List
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class IntSLLNode
{
public:
    IntSLLNode()
    {
        next = NULL;
    }
    IntSLLNode(int el, IntSLLNode *n)
    {
        data = el;
        next = n;
    }
    int data;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = NULL;
    }
    void addToHead(int);
    void printAll() const;
    void sortSLList();
    
    
    
    
    
private:
    IntSLLNode *head,*tail;
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
        head=tail=newEl;
        return;
    }
    head = newEl;
    newEl->next = temp;
    
}
void IntSLList::sortSLList()
{
    if(head == NULL&&tail==NULL)
    {
        cout<<"Empty list1."<<endl;
        return;
    }
    if(head==tail)
    {
        return;
    }
    if(head->next->next ==NULL)
    {
        IntSLLNode *cur = head;
        if(cur->data>tail->data)
        {
            tail->next = cur;
            cur->next = NULL;
            head = tail;
            tail = tail->next;
            
        }
        return;
    }
    IntSLLNode *p1,*c1,*p2,*c2,*temp;
    temp = tail;
    
    bool sorted = false;
    while(!sorted)
    {
        p1 = p2 = NULL;
        c1 = c2 = head;
        sorted = true;
        while(c2 != tail->next)
        {
            if(c2->data<c1->data)
            {
                p1 = p2;
                c1 = c2;
            }

            p2 = c2;
            c2 = c2->next;
        }
        if(c1 == tail)
        {
            tail = p1;
        }
        if(p1 == NULL)
        {
            head = c1->next;
        }
        else
        {
            p1->next = c1->next;

        }
        temp->next = c1;
        c1->next = NULL;
        temp = temp->next;

        if(tail!=head)
            sorted = false;
        
    }
    
    head = tail->next;
    temp->next = tail;
    tail->next = NULL;

}
int main()
{
    IntSLList mySLList;
    mySLList.addToHead(9);
    mySLList.addToHead(2);
    mySLList.addToHead(1);
    mySLList.addToHead(6);
    mySLList.addToHead(3);
    mySLList.addToHead(12);
    mySLList.printAll();
    mySLList.sortSLList();
    mySLList.printAll();

    return 0;
}
