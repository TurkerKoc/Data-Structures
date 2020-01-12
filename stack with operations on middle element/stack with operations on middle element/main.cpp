//
//  main.cpp
//  stack with operations on middle element
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
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
        head = mid = NULL;
    }
    bool isEmpty() const
    {
        return head==0;
    }
    
    void printALL() const;
    void push(int);
    void pop();
    int top();
    bool isEmpty();
    int findLength();
    int findMid()
    {
        return mid->data;
    }
    void deleteMid();
    
private:
    DLLNode *head,*mid;
};

void DoublyLinkedList::push(int data)
{
    DLLNode *newEl = new DLLNode(data,NULL,NULL);
    if(head==NULL)
    {
        head = newEl;
        mid = newEl;
        return;
    }
    DLLNode *cur = head;
    head = newEl;
    newEl->next = cur;
    cur->prev = newEl;
    if(findLength()%2==0)
    {
        mid=mid->prev;
    }
}
int DoublyLinkedList::findLength()
{
    DLLNode *temp = head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
void DoublyLinkedList::deleteMid()
{
    DLLNode *p = mid->prev;
    DLLNode *c = mid;
    DLLNode *n = mid->next;
    
    p->next = n;
    n->prev = p;
    
    c->next = NULL;
    c->prev = NULL;
    delete c;
    c=NULL;
    
    if(findLength()%2!=0)
        mid=n;
    else
        mid=p;
}

void DoublyLinkedList::printALL() const
{
    if(head==NULL)
    {
        cout<<"Empty stack."<<endl;
    }
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
    myDLL.push(1);
    myDLL.push(2);
    myDLL.push(3);
    myDLL.push(4);
    myDLL.push(5);
    myDLL.push(6);
    myDLL.printALL();
    cout<<"Mid Elemend: "<<myDLL.findMid()<<endl;
    myDLL.deleteMid();
    myDLL.printALL();
    cout<<"Mid Elemend: "<<myDLL.findMid()<<endl;
    myDLL.deleteMid();
    myDLL.printALL();
    cout<<"Mid Elemend: "<<myDLL.findMid()<<endl;
    
    return 0;
}
