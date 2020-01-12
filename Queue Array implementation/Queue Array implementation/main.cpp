//
//  main.cpp
//  Queue Array implementation
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class Queue
{
public:
    Queue(int n)
    {
        rear = front = -1;
        arr = new int[n];
        size = n;
    }
    void Enqueue(int);
    void Dequeue();
    int Front()
    {
        return arr[front];
    }
    bool isEmpty()
    {
        if(rear==-1&&front==-1)
            return true;
        else
            return false;
    }
    void printAll();
    
    
    
private:
    int *arr;
    int rear;
    int front;
    int size;
};

void Queue::Enqueue(int data)
{
    
    if((rear+1)%size == front)
    {
        cout<<"Queue is full."<<endl;
        return;
    }
    if(isEmpty())
        rear = front = 0;
    else
        rear = (rear+1)%size;
    arr[rear] = data;
}

void Queue::Dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front == rear)
        front = rear = -1;
    else
        front = (front+1)%size;
    
}

void Queue::printAll()
{
    cout<<"Your Queue: ";
    if (!isEmpty())
    {
        int i = front;
        do
        {
            cout<<(arr[i])<<" ";
            if(i==rear)
                break;
            i = (i + 1) % (size);
            
        } while (i != front);
    }
    cout<<endl;
}

int main()
{
    Queue myQueue(10);
    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);
    myQueue.Enqueue(4);
    myQueue.Enqueue(5);
    myQueue.Enqueue(6);
    myQueue.Enqueue(7);
    myQueue.Enqueue(8);
    myQueue.Enqueue(9);
    myQueue.Enqueue(10);
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Enqueue(11);
    myQueue.Enqueue(12);
    myQueue.Enqueue(13);

    myQueue.printAll();
    cout<<"Front: "<<myQueue.Front()<<endl;

    return 0;
}
