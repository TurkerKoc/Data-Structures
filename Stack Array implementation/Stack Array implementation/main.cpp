//
//  main.cpp
//  Stack Array implementation
//
//  Created by Turker Koc on 10.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class vectorArr
{

};
class Stack
{
public:
    void push(int);
    void pop();
    int Top();
    bool isEmpty()
    {
        return top == -1;
    }
    void printStack() const;
private:
    vector<int> S{0,0,0,0,0,0,0,0,0,0};
    int top = -1;
};

void Stack::printStack() const
{
    if(top == -1)
    {
        cout<<"Your Stack is empty."<<endl;
        return;
    }
    cout<<"Your Stack:"<<endl;
    for(int i=top;i>-1;i--)
    {
        cout<<S[i]<<endl;
    }
}
void Stack::push(int data)
{
    if(top == S.size()-1)
    {
        cout<<"Your Stack is full."<<endl;
        return;
    }
    top++;
    S[top] = data;
}
void Stack::pop()
{
    if(top==-1)
    {
        cout<<"Your Stack is empty"<<endl;
        return;
    }
    S[top] = 0;
    top--;
}
int Stack::Top()
{
    return S[top];
}
int main()
{

    Stack S;
    S.push(3);
    S.push(4);
    S.printStack();
    S.pop();
//    S.printStack();
//    S.pop();
    S.printStack();
    if(S.isEmpty())
        cout<<"Yes it is empty"<<endl;
    else
        cout<<"No it is not empty"<<endl;

    cout<<"Your top element is: ";
    int top = S.Top();
    cout<<top<<endl;
    

    return 0;
}
