//
//  main.cpp
//  Stack implement k stacks in a single array
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class kStacks
{
public:
    kStacks(int k, int size)
    {
        n=size;
        s = new int[k*n];
        top = new int[k]; //storing top index of all stacks.
        for(int i=0;i<k;i++)
        {
            top[i] = (n*i)-1;
        }
    }
    void push(int sn,int data);
    void pop(int sn);
    void printStack(int sn);
    
    
private:
    int *s;
    int n; //stack size
    int *top;
};
void kStacks::push(int sn, int data) //sn = stack number for adding data
{


    if(top[sn-1] == (sn*n)-1)
    {
        cout<<"That stack is full."<<endl;
        return;
    }
    top[sn-1]++;
    s[top[sn-1]] = data;
    
}
void kStacks::printStack(int sn)
{
    if(top[sn-1] == ((sn-1)*n)-1)
    {
        cout<<sn<<". "<<"Stack is empty!"<<endl;
        return;
    }
    cout<<sn<<". Stack:"<<endl;
    for(int i=(sn-1)*n; i<=top[sn-1]; i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void kStacks::pop(int sn)
{
    if(top[sn-1] == ((sn-1)*n)-1)
    {
        cout<<sn<<". "<<"Stack is empty!"<<endl;
        return;
    }
    top[sn-1]--;
}
int main()
{
    int k=3; //stack number
    int n=10; //stack size
    
    kStacks myStack(k,n);
    myStack.push(1, 5);
    myStack.push(1, 3);
    myStack.printStack(1);
    
    myStack.push(2, 12);
    myStack.printStack(2);
    
    myStack.push(3, 6);
    myStack.printStack(3);
    
    myStack.pop(1);
    myStack.printStack(1);
    
    

    
    return 0;
}
