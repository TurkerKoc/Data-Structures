//
//  main.cpp
//  Add two numbers represented by linked lists
//
//  Created by Turker Koc on 9.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
#include "intSLList.h"
void print(IntSLLNode *head)
{
    IntSLLNode *x;
    x = head;
    
    if(head == NULL)
        cout<<"linked list is empty."<<endl;
    
    while(x != NULL)
    {
        cout<<x->data<<" ";
        x = x->next;
    }
    cout<<endl;
    
}
void addToTail(IntSLLNode *head, int data)
{
    IntSLLNode *temp = head;
    IntSLLNode *newEl = new IntSLLNode();
    newEl->data = data;
    newEl->next = NULL;
    if(head == NULL)
    {
        head = newEl;
    }
    
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEl;
    }
}
int TakePower(int data,int n)
{
    int i = 1;
    int newNum = data;
    if(n==0)
    {
        return 1;
    }
    while(i<n)
    {
        newNum = data * newNum;
        i++;
    }
    return newNum;
}
void findSum(IntSLLNode *head1, IntSLLNode *head2, int n1, int n2) //n1 and n2 for taking power of 10
{
    int num1 = 0;               //FINDING NUM1
    IntSLLNode *temp = head1;
    for(int i=0; i<=n1; i++)
    {
        num1 = num1 +  (temp->data*TakePower(10, i));
        temp = temp->next;
    }
    
    int num2 = 0;               //FINDING NUM2
    IntSLLNode *temp2 = head2;
    for(int i=0; i<=n2; i++)
    {
        num2 = num2 +  (temp2->data*TakePower(10, i));
        temp2 = temp2->next;
    }
    
    int num3 = num1+num2;                   //NUM3
    IntSLLNode *head3;
    head3=NULL;
    
    //INSERT NUM3'S DIGITS TO A NEW LINKED LIST (HEAD3)
    while(num3 != 0)
    {
        int digit = num3 % 10;
        
        //ADD TO TAIL
        IntSLLNode *temp = head3;
        IntSLLNode *newEl = new IntSLLNode();
        newEl->data = digit;
        newEl->next = NULL;
        if(head3 == NULL)
        {
            head3 = newEl;
        }
        
        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newEl;
        }
        //ADDING FROM TAIL (ABOVE)
        
        
        num3 = num3/10;
        
    }
    
    cout<<"Summation Linked List: ";
    print(head3);
    
    
    
}

          



int main()
{
    IntSLList mySLList1;
    IntSLList mySLList2;
    
    mySLList1.addToTail(5);
    mySLList1.addToTail(6);
    mySLList1.addToTail(3);
    

    mySLList2.addToTail(8);
    mySLList2.addToTail(4);
    mySLList2.addToTail(2);
    
    mySLList1.printAll();
    mySLList2.printAll();
    
    IntSLLNode head1 = mySLList1.getHead();
    IntSLLNode head2 = mySLList2.getHead();
    
    int length1 = mySLList1.getLength();
    int length2 = mySLList2.getLength();
    
    findSum(&head1, &head2, length1-1, length2-1);
    
    
    return 0;
}








//struct Node
//{
//    int data;
//    Node *next;
//};
//Node *head = NULL;
//Node *head2 = NULL;
//void addToHead(int data)
//{
//    Node *temp = head;
//    Node *newEl = new Node();
//    newEl->data = data;
//    newEl->next = NULL;
//
//    if(head==NULL) //if the list is empty.
//    {
//        head=newEl;
//        return;
//    }
//    head = newEl;
//    newEl->next = temp;
//
//}
//void Print()
//{
//    Node *temp = head;
//    if(head == NULL)
//        cout<<"Your Linked List is empty."<<endl;
//    else
//    {
//        cout<<"Your Current List: ";
//        while(temp!=NULL)
//        {
//            cout<<temp->data<<" ";
//            temp = temp->next;
//        }
//        cout<<endl;
//    }
//}
