//
//  main.cpp
//  Stack implementation using Queues
//
//  Created by Turker Koc on 12.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <queue>
using std::queue;
using namespace std;
class stack
{
public:
    
    void push(int data);
    void pop();
    void printAll();
    bool isEmpty();
    int Top();
    
    
    
private:
    queue<int> q1,q2;
};

void stack::push(int data)
{
    q1.push(data);
}
void stack::pop()
{
    if(q1.empty())
    {
        cout<<"Empty stack."<<endl;
        return;
    }
    while(q1.size()!=1)
    {
        int el = q1.front();
        q2.push(el);
        q1.pop();
    }
    q1.pop();
    while(!q2.empty())
    {
        int el = q2.front();
        q1.push(el);
        q2.pop();
    }
    
}
void stack::printAll()
{
    if(q1.empty())
    {
        cout<<"Empty stack."<<endl;
        return;
    }
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        int el = q1.front();
        q2.push(el);
        q1.pop();
    }
    while(!q2.empty())
    {
        int el = q2.front();
        q1.push(el);
        q2.pop();
    }
    cout<<endl;
}
int main()
{
    stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.printAll();
    myStack.pop();
    myStack.printAll();
    myStack.push(6);
    myStack.printAll();
    myStack.pop();
    myStack.printAll();
    return 0;
}
