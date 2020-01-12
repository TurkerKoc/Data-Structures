//
//  main.cpp
//  Queue priority Queue linked list
//
//  Created by Turker Koc on 12.11.2018.
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
    IntSLLNode(string el,int pr, IntSLLNode *n)
    {
        data = el;
        next = n;
        priority = pr;
    }
    string data;
    int priority;
    IntSLLNode *next;
};
class PriorityQueue
{
public:
    PriorityQueue()
    {
        front = rear = NULL;
    }
    void Enqueue(string,int); //start from head check priorities
    void Dequeue(); //delete which has most priority
    bool isEmpty()
    {
        return front==NULL;
    }
    string Front()//return which has highest priority
    {
        if(front==NULL)
            return "Empty";
        else
            return front->data;
    }
    void printAll();
    
    
    
private:
    IntSLLNode *front;
    IntSLLNode *rear;
};


void PriorityQueue::Enqueue(string data,int priority)
{

    IntSLLNode *newEl = new IntSLLNode(data,priority,NULL);
    IntSLLNode *cur = front;
    IntSLLNode *prev = NULL;

    if(front==NULL&&rear==NULL)
    {
        front = rear = newEl;
        return;
    }
    while((cur!=NULL)&&cur->priority > priority)
    {
        prev = cur;
        cur = cur->next;
    }
    if(prev==NULL)
    {
        front = newEl;
        newEl->next = cur;
        return;
    }
    prev->next = newEl;
    newEl->next = cur;

    
}
void PriorityQueue::Dequeue()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Empty Queue."<<endl;
        return;
    }
    IntSLLNode *cur = front;
    if(front == rear)
    {
        front = rear = NULL;
        delete cur;
    }
    front = front -> next;
    delete cur;
    
}
void PriorityQueue::printAll()
{
    if(front==NULL && rear == NULL)
    {
        cout<<"Your Queue is empty."<<endl;
        return;
    }
    IntSLLNode *cur = front;
    cout<<"Your current Queue: ";
    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        cur = cur ->next;
    }
    cout<<endl;
}
int main()
{
    PriorityQueue myPQ;
    myPQ.Enqueue("Spotify", 2);
    myPQ.Enqueue("Safari", 3);
    myPQ.Enqueue("Xcode", 4);
    myPQ.Enqueue("Whatsapp", 1);
    myPQ.printAll();
    cout<<"Front of your queue: "<<myPQ.Front()<<endl;
    myPQ.Dequeue();
    myPQ.printAll();
    cout<<"Front of your queue: "<<myPQ.Front()<<endl;
    cout<<myPQ.isEmpty()<<endl;
    return 0;
}
