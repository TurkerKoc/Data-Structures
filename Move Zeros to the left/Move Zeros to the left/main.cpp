//
//  main.cpp
//  Move Zeros to the left
//
//  Created by Turker Koc on 9.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include "intSLList.h"
using namespace std;

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

void MoveZerosToTheLeft(IntSLLNode *head)
{
    IntSLLNode *temp = head;
    IntSLLNode *prevTemp = NULL;
    IntSLLNode *cur = head;
    
    //MOVİNG ZEROS TO THE LEFT
    bool check = true;
    while(check == true)
    {

        while(temp->data == 0 && temp!=NULL) //find first element after zero in the beginning
            temp = temp->next;
        while(temp->data != 0 && check == true)
        {
            if(temp->next == NULL) //if no zeros left
            {
                cout<<"Your List after moving all zeros to the left: ";
                print(head);
                check = false;
                break;
            }
            prevTemp = temp;
            temp = temp->next;
            

        }
        if(check == true)     //move zero to the left
        {
            prevTemp->next = temp->next;
            temp->next = head;
            head = temp;
        }
        
        temp = head;
    }
    
    
    //REVERSİNG NODES AFTER ZEROS
    temp = head;
    while(temp->next->data == 0 && temp!=NULL) //find first element after zero in the beginning
        temp = temp->next;
    
    IntSLLNode *prev;
    IntSLLNode *Next;
    
    prev = temp->next;
    cur = prev->next;
    Next = cur->next;
    
    while(Next != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = Next;
        Next = Next->next;
    }
    cur->next = prev;
    temp->next->next = NULL;
    temp->next = cur;
    
    cout<<"Your list after reversing nodes after zeros: ";
    print(head);
    
    
}



int main()
{
    
    IntSLList mySLList;
    mySLList.addToTail(1);
    mySLList.addToTail(0);
    mySLList.addToTail(2);
    mySLList.addToTail(3);
    mySLList.addToTail(0);
    mySLList.addToTail(5);
    
    IntSLLNode head = mySLList.getHead();
    mySLList.printAll();
    
    MoveZerosToTheLeft(&head);


    
    

    return 0;
}
