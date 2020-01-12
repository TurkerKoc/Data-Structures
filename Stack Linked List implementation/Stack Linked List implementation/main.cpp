//
//  main.cpp
//  Stack Linked List implementation
//
//  Created by Turker Koc on 10.11.2018.
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
class stack
{
public:
    stack()
    {
        head = top = NULL;
    }
    void push(int);
    void pop();
    void printStack() const;
    int Top() const; //return top element;
    bool isEmpty() const;
    
private:
    IntSLLNode *head;
    IntSLLNode *top;
    
};
void stack::printStack() const
{
    if(head == NULL)
    {
        cout<<"Your stack is empty."<<endl;
        return;
    }
    IntSLLNode *cur = head;
    cout<<"Your stack: "<<endl;
    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
    
    
}
void stack::push(int data)
{
    IntSLLNode *newEl = new IntSLLNode(data, NULL);

    if(head == NULL)
    {
        head = newEl;
        top = newEl;
        return;
    }
    IntSLLNode *cur = head;
    head = newEl;
    newEl->next = cur;
    top = head;
    
    
}
void stack::pop()
{
    IntSLLNode *cur = head;
    if(head==NULL)
    {
        cout<<"Your stack is empty."<<endl;
        return;
    }
    if(head->next == NULL)
    {
        head = top = NULL;
        delete cur;
        cur = NULL;
        return;
    }
    top = head->next;
    head = head->next;
    cur->next = NULL;
    delete cur;
    cur = NULL;
    
    
}
int stack::Top() const
{
    if(head==NULL)
    {
        cout<<"Your stack is empty."<<endl;
        return -1;
    }
    return top->data;
}
bool stack::isEmpty() const
{
    if(head==NULL)
        return true;
    else
        return false;
}
int main()
{
    
    stack s;
    
    
    s.push(3);
    s.printStack();

    s.push(2);
    s.printStack();
    
    s.push(5);
    s.printStack();
    
//    s.pop();
//    s.printStack();
//
//
//    s.pop();
    
    cout<<"Your top element: "<<s.Top()<<endl;
   
    s.pop();
    s.printStack();
    
    if(s.isEmpty())
        cout<<"Your stack is empty."<<endl;
    else
        cout<<"Your stack is not empty."<<endl;
    

    return 0;
}
