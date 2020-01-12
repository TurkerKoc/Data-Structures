//
//  main.cpp
//  Singly Linked List All
//
//  Created by Turker Koc on 9.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include "intSLList.h"
using namespace std;

int main()
{
    int El;

    IntSLList mySLList;
    
    mySLList.addToHead(5);
    mySLList.printAll();
    
    
    mySLList.addToTail(9);
    mySLList.printAll();
    
    mySLList.addToSecond(3);
    mySLList.printAll();
    
//    El=mySLList.deleteFromSecond();
//    if(El==-1)
//        cout<<"Your list is empty. No elements to delete."<<endl;
//    else
//        cout<<"Element Deleted From Second: "<<El<<endl;
//    mySLList.printAll();
//
//    mySLList.addToHead(4);
//    mySLList.printAll();
//
//    El=mySLList.deleteFromHead();
//    if(El==-1)
//        cout<<"Your list is empty. No elements to delete."<<endl;
//    else
//        cout<<"Element Deleted From head: "<<El<<endl;
//    mySLList.printAll();
//
//    El=mySLList.deleteFromTail();
//    if(El==-1)
//        cout<<"Your list is empty. No elements to delete."<<endl;
//    else
//        cout<<"Element Deleted From tail: "<<El<<endl;
//    mySLList.printAll();
//
//    mySLList.deleteNode(9);
//    mySLList.printAll();
//
//    bool check = mySLList.isInList(5);
//    if(check == true)
//        cout<<"Yes that element is in your list."<<endl;
//    else
//        cout<<"That element does not appear in your list."<<endl;
//
//    IntSLLNode head;
//    head = mySLList.getHead();

    mySLList.deleteNodePosition(3);
    mySLList.printAll();

    int length = mySLList.getLength();
    cout<<length<<endl;


    return 0;
}
