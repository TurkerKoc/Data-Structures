//
//  main.cpp
//  Detect and Remove Loop in a Linked List
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
    typedef int ElementType;
    ElementType data;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = 0;
    }
    //~IntSLList();
    int isEmpty()
    {
        return head == 0;
    }
    void printAll() const;
    void addToHead(int);
    void addToSecond(int data);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its data;
    int deleteFromSecond(); // delete the second and return its data;
    int  deleteFromTail(); // delete the tail and return its data;
    void deleteNode(int);  //find the given element if it is exist delete it
    void deleteNodePosition(int); //if the given position exist delete it
    bool isInList(int) const;
    IntSLLNode getHead();
    int getLength();
    void addLoopInSLL();  //adding loop for at least list with 5 variables
    void detectLoopInSLL();
    
    
private:
    IntSLLNode *head, *tail;
};

void IntSLList::addLoopInSLL()
{
    IntSLLNode *start = head->next; //LOOP is starting from second variable.
    IntSLLNode *end = head;
    while(end->next != NULL)
    {
        end = end->next;
    }
    end->next = start;
}
void IntSLList::printAll() const
{
    IntSLLNode *temp = head;
    if(head == NULL)
        cout<<"Your Linked List is empty."<<endl;
    else
    {
        cout<<"Your Current List: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
void IntSLList::addToHead(int data)
{
    IntSLLNode *temp = head;
    IntSLLNode *newEl = new IntSLLNode();
    newEl->data = data;
    newEl->next = NULL;
    
    if(head==NULL) //if the list is empty.
    {
        head=newEl;
        return;
    }
    head = newEl;
    newEl->next = temp;
    
}
void IntSLList::detectLoopInSLL()
{
    IntSLLNode *x = head;
    IntSLLNode *y = head;
    while(true)
    {
        x=x->next;
        y=y->next->next;
        if(x==y)
            break;
    }
    y->next = NULL;
}
int main()
{
    IntSLList mySLList;
    mySLList.addToHead(8);
    mySLList.addToHead(7);
    mySLList.addToHead(6);
    mySLList.addToHead(5);
    mySLList.addToHead(4);
    mySLList.addToHead(3);
    mySLList.addToHead(2);
    mySLList.addToHead(1);
    mySLList.addToHead(0);
    
    mySLList.addLoopInSLL();
    mySLList.detectLoopInSLL();
    mySLList.printAll();


    return 0;
}
