//
//  main.cpp
//  Merge Sorted LinkedLists
//
//  Created by Turker Koc on 9.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include "intSLList.h"
using namespace std;

void MergeSortedSLL(IntSLLNode *head1,IntSLLNode *head2)
{
    IntSLLNode *cur1 = head1;
    
    IntSLLNode *cur2 = head2;
    
    
    while(cur2 != NULL)
    {
        while(!(cur1->next->data > cur2->data))
        {
            cur1 = cur1->next;
        }
        IntSLLNode *tempCur2 = cur2;
        cur2 = cur2->next;
        tempCur2->next = cur1->next;
        cur1->next = tempCur2;
        
        
        cur1 = head1;
    }
    
    
}

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
int main()
{
    IntSLList mySLList;
    IntSLList mySLList2;


    

    mySLList.addToHead(9);
    mySLList.addToHead(5);
    mySLList.addToHead(1);
    IntSLLNode head1 = mySLList.getHead();
    cout<<"First List: ";
    print(&head1);


    

    

    mySLList2.addToHead(7);
    mySLList2.addToHead(3);
    mySLList2.addToHead(2);
    IntSLLNode head2 = mySLList2.getHead();
    cout<<"Second List: ";
    print(&head2);


    MergeSortedSLL(&head1, &head2);
    
    cout<<"Merged List: ";
    print(&head1);
    return 0;
}






//2. LİSTEYİ 1. NİN SONUNA EKLEYİP SELECTİON SORT DENEMESİ (BAŞARISIZ)


//    while(cur1->next != NULL)
//    {
////        minprev = cur1;
////        min = cur1;
////        prev1 = head1;
////        while(prev1->next != cur1)
////            prev1 = prev1->next;
//
//        int Min = cur1->data;
//        temp = cur1;
//        prev1 = head1;
//        while(prev1->next != cur1 && prev1 != cur1)
//            prev1 = prev1->next;
//
//        while(temp->next != NULL)
//        {
//            if(temp->next->data < Min)
//            {
//                Min = temp->next->data;
//                minprev = temp;
//                min = temp->next;
//            }
////            minprev = min;
////            min = min->next;
//            temp = temp->next;
//        }
//        if(Min == cur1->data)
//        {
//            prev1 = cur1;
//            cur1 = cur1->next;
//            continue;
//        }
//        IntSLLNode *tempCur = cur1;
//        IntSLLNode *tempPrev = prev1;
//
//
//
//
//        if(prev1 == NULL)
//        {
//            prev1 = cur1;
//            cur1 = cur1->next;
//
//            head1 = min;
//            min = min->next;
//            minprev->next = tempCur;
//            head1->next = tempCur -> next;
//            tempCur -> next = min;
//        }
//        if(prev1->next = min)
//        {
//            tempPrev = min;
//            tempCur->next = min->next;;
//            min->next = tempCur;
//
//        }
//        else
//        {
//            prev1 = cur1;
//            cur1 = cur1->next;
//
//            tempPrev->next = min;
//            min = min->next;
//            minprev->next = tempCur;
//            tempPrev->next->next = tempCur -> next;
//            tempCur->next = min;
////        }
////
//
//
//    }


