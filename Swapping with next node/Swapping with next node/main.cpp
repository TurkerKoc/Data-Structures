
//
//  main.cpp
//  Swapping with next node
//
//  Created by Turker Koc on 13.11.2018.
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
    intSLLNode(int el,intSLLNode *n)
    {
        data = el;
        next = n;
    }
    int data;
    intSLLNode *next;
};
class swapNext
{
public:
    swapNext()
    {
        head = NULL;
    }
    void addToHead(int data);
    void printAll();
    void swap();
    
private:
    intSLLNode *head;
    
};

void swapNext::addToHead(int data)
{
    intSLLNode *newEl = new intSLLNode(data,NULL);
    if(head == NULL)
    {
        head = newEl;
        return;
    }
    intSLLNode *temp = head;
    head = newEl;
    newEl -> next = temp;
}
void swapNext::printAll()
{
    intSLLNode *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void swapNext::swap()
{
    if(head == NULL)
    {
        cout<<"Empty List!"<<endl;
        return;
    }
    if(head->next == NULL)
        return;
    if(head->next->next == NULL)
    {
        intSLLNode *temp = head->next;
        temp->next = head;
        head->next = NULL;
        head = temp;
        return;
    }
    intSLLNode *p = head;
    intSLLNode *c = head->next;
    intSLLNode *n = c->next;
    bool flag = true;
    intSLLNode *headRef = head->next;

    while(p!=NULL)
    {

        if(n==NULL)
        {
            p->next = c->next;
        }
        else
        {
            if(n->next == NULL) //tek sayıda eleman varsa
            {
                p->next = n;
            }
            else
                p->next = n->next;

        }
        c->next = p;
        if(n != NULL && n->next == NULL) //tek sayıysa head ayarla bitir..
        {
            if(flag == true)
            {
                head = headRef;
                flag = false;
            }
            return;

        }
        p = n;
        if(n!=NULL)
        {
            c=n->next;
        }
        if(n!=NULL)
        {
            n = c->next;
        }
        if(flag == true)
        {
            head = headRef;
            flag = false;
        }

    }
}


int main()
{
    
    swapNext mySwap;
    mySwap.addToHead(9);
    mySwap.addToHead(6);
    mySwap.addToHead(8);
    mySwap.addToHead(7);
    mySwap.addToHead(4);
    mySwap.addToHead(5);
    mySwap.addToHead(3);

    mySwap.printAll();
    mySwap.swap();
    mySwap.printAll();

    return 0;
}
