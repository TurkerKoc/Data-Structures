//
//  main.cpp
//  Queue Implementing using stack
//
//  Created by Turker Koc on 12.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
class Queue
{
public:
    void Enqueue(int);
    void Dequeue();
    bool isEmpty()
    {
        return s2.empty() == 1;
    }
    int Front();
    void printAll();
    
private:
    stack<int> s1;
    stack<int> s2;
};

void Queue::Enqueue(int data)
{
    s2.push(data);
}
void Queue::Dequeue()
{
    if(s2.empty())
    {
        cout<<"Empty Queue"<<endl;
        return;
    }
    while(!s2.empty())
    {
        int el = s2.top();
        s1.push(el);
        s2.pop();
    }
    s1.pop();
//    while(!s2.empty())
//        s2.pop();
    while(!s1.empty())
    {
        int el = s1.top();
        s2.push(el);
        s1.pop();
    }
}
void Queue::printAll()
{
    if(s2.empty())
    {
        cout<<"Empty Queue."<<endl;
        return;
    }
    cout<<"Your Queue: ";
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        int el = s2.top();
        s1.push(el);
        s2.pop();
    }
    while(!s1.empty())
    {
        int el = s1.top();
        s2.push(el);
        s1.pop();
    }
    cout<<endl;
}
int Queue::Front()
{
    while(!s2.empty())
    {
        int el = s2.top();
        s1.push(el);
        s2.pop();
    }
    int top;
    if(!s1.empty())
        top = s1.top();
    else
        top = -1;
    while(!s1.empty())
    {
        int el = s1.top();
        s2.push(el);
        s1.pop();
    }
    return top;
}
int main()
{
    
    Queue myQueue;
    myQueue.Dequeue();
    myQueue.printAll();
    myQueue.Enqueue(6);
    myQueue.Enqueue(5);
    myQueue.Enqueue(4);
    myQueue.Enqueue(3);
    myQueue.Enqueue(2);
    myQueue.printAll();
    myQueue.Dequeue();
    myQueue.printAll();
//    cout<<myQueue.isEmpty()<<endl;
    cout<<"Your top element: "<<myQueue.Front()<<endl;


    return 0;
}
