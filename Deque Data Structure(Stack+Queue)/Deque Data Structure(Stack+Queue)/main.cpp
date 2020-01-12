//
//  main.cpp
//  Deque Data Structure(Stack+Queue)
//
//  Created by Turker Koc on 12.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = NULL;
        
    }
    DLLNode(int el,DLLNode *p,DLLNode *n)
    {
        data = el;
        next = n;
        prev = p;
    }
    int data;
    DLLNode *next;
    DLLNode *prev;
};
class Deque
{
public:
    Deque()
    {
        front = rear = NULL;
    }
    void insertAtFront(int);
    void insertAfter(int,int); //first int for searching the node to insert after it other int is data
    void insertAtRear(int);
    void insertBefore(int,int);//first int for searching the node to insert before it other int is data
    void deleteAtFront();
    void deleteAtRear();
    
    void printAll();
    
    
    
    
private:
    DLLNode *front;
    DLLNode *rear;
    
};

void Deque::insertAtFront(int data)
{
    DLLNode *newEl = new DLLNode(data,NULL,NULL);
    if(front==NULL&&rear==NULL)
    {
        front = rear = newEl;
        return;
    }
    DLLNode *cur = front;
    front = newEl;
    newEl->next = cur;
    cur->prev = newEl;
}
void Deque::insertAtRear(int data)
{
    DLLNode *newEl = new DLLNode(data,NULL,NULL);
    if(front==NULL&&rear==NULL)
    {
        front = rear = newEl;
        return;
    }
    DLLNode *cur = rear;
    rear = newEl;
    newEl->prev = cur;
    cur->next = newEl;
}
void Deque::printAll()
{
    if(front == NULL&&rear == NULL)
    {
        cout<<"Your Deque is empty."<<endl;
        return;
    }
    DLLNode *cur = front;
    cout<<"Your Deque: ";
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}
void Deque::insertAfter(int Node,int data)//Node=insert after it
{
    DLLNode *newEl = new DLLNode(data,NULL,NULL);
    if(front==NULL&&rear==NULL)
    {
        front=rear=newEl;
        return;
    }
    DLLNode *cur = front;
    while(cur!=NULL&&cur->data!=Node)
        cur=cur->next;
    if(cur->next == NULL)
    {
        cur->next = newEl;
        newEl->prev = cur;
        return;
    }
    newEl->next = cur->next;
    cur->next->prev = newEl;
    cur->next = newEl;
    newEl->prev = cur;
}
void Deque::insertBefore(int Node, int data)
{
    DLLNode *newEl = new DLLNode(data,NULL,NULL);
    if(front==NULL&&rear==NULL)
    {
        front=rear=newEl;
        return;
    }
    DLLNode *cur = front;
    while(cur!=NULL&&cur->data!=Node)
        cur=cur->next;
    if(cur->prev == NULL)
    {
        cur->prev = newEl;
        newEl->next = cur;
        front = newEl;
        return;
    }
    newEl->next = cur;
    newEl->prev = cur->prev;
    cur->prev->next = newEl;
    cur->prev = newEl;
}
void Deque::deleteAtFront()
{
    if(front==NULL&&rear==NULL)
    {
        cout<<"Your Deque is empty!"<<endl;
        return;
    }
    if(front==rear)
    {
        front = rear = NULL;
        return;
    }
    DLLNode *cur = front;
    front = front->next;
    front->prev = NULL;
    delete cur;
    cur=NULL;
}
void Deque::deleteAtRear()
{
    if(front==NULL&&rear==NULL)
    {
        cout<<"Your Deque is empty!"<<endl;
        return;
    }
    if(front==rear)
    {
        front = rear = NULL;
        return;
    }
    DLLNode *cur = rear;
    rear = rear->prev;
    rear->next = NULL;
    delete cur;
    cur=NULL;
}
int main()
{
    Deque myDeque;
    myDeque.insertAtFront(5);
    myDeque.printAll();
    myDeque.insertAtFront(2);
    myDeque.printAll();
    myDeque.insertAtRear(7);
    myDeque.printAll();
    myDeque.insertAfter(2, 3);
    myDeque.printAll();
    myDeque.insertBefore(7, 9);
    myDeque.printAll();
    myDeque.deleteAtFront();
    myDeque.printAll();
    myDeque.deleteAtRear();
    myDeque.printAll();
    return 0;
}
