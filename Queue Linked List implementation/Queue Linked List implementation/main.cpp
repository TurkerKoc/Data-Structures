//
//  main.cpp
//  Queue Linked List implementation
//
//  Created by Turker Koc on 11.11.2018.
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
    intSLLNode(int el, intSLLNode *n)
    {
        data = el;
        next = n;
    }
    int data;
    intSLLNode *next;
};
class Queue
{
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int);
    void Dequeue();
    bool isEmpty()
    {
        if(front == NULL)
            return true;
        else
            return false;
    }
    int Front()
    {
        if(front == NULL)
            return -1;
        return front->data;
    }
    void printALL();
    
private:
    intSLLNode *front;
    intSLLNode *rear;
    
};

void Queue::Enqueue(int data)
{
    intSLLNode *newEl = new intSLLNode(data, NULL);
    if(front==NULL && rear == NULL)
    {
        front = rear = newEl;
        return;
    }
    intSLLNode *temp = rear;
    temp->next = newEl;
    rear = newEl;
}
void Queue::Dequeue()
{
    if(front==NULL && rear == NULL)
    {
        cout<<"Your Queue is empty."<<endl;
        return;
    }
    intSLLNode *temp = front;
    front = front->next;
    delete temp;

}
void Queue::printALL()
{
    if(front==NULL && rear == NULL)
    {
        cout<<"Your Queue is empty."<<endl;
        return;
    }
    intSLLNode *cur = front;
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
    Queue myQueue;
    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.printALL();
    myQueue.Dequeue();
    myQueue.printALL();
    cout<<myQueue.Front()<<endl;
    myQueue.isEmpty() ? cout<<"Yes"<<endl : cout<<"No"<<endl;

    return 0;
}
