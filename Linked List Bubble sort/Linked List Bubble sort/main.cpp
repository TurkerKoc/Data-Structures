//
//  main.cpp
//  Linked List Bubble sort
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

struct node
{
    int data;
    node *next;
};
#include <iostream>
void ll_bubblesort(struct node **pp)
{
    // p always points to the head of the list
    struct node *p = *pp;
    *pp = nullptr;
    
    while (p)
    {
        struct node **lhs = &p;
        struct node **rhs = &p->next;
        bool swapped = false;
        
        // keep going until qq holds the address of a null pointer
        while (*rhs)
        {
            // if the left side is greater than the right side
            if ((*rhs)->data < (*lhs)->data)
            {
                // swap linked node ptrs, then swap *back* their next ptrs
                std::swap(*lhs, *rhs);
                std::swap((*lhs)->next, (*rhs)->next);
                lhs = &(*lhs)->next;
                swapped = true;
            }
            else
            {   // no swap. advance both pointer-pointers
                lhs = rhs;
                rhs = &(*rhs)->next;
            }
        }
        
        // link last node to the sorted segment
        *rhs = *pp;
        
        // if we swapped, detach the final node, terminate the list, and continue.
        if (swapped)
        {
            // take the last node off the list and push it into the result.
            *pp = *lhs;
            *lhs = nullptr;
        }
        
        // otherwise we're done. since no swaps happened the list is sorted.
        // set the output parameter and terminate the loop.
        else
        {
            *pp = p;
            break;
        }
    }
}
void addToHead(struct node **head,int el)
{
    struct node *newEl = new node;
    newEl->data = el;
    newEl->next = NULL;
    if(*head == NULL)
    {
        *head = newEl;
        return;
    }
    struct node *temp = *head;
    *head = newEl;
    newEl->next = temp;
}
int main()
{
    struct node *head = NULL;
    addToHead(&head, 9);
    addToHead(&head, 2);
    addToHead(&head, 1);
    addToHead(&head, 6);
    addToHead(&head, 3);
    addToHead(&head, 12);
    ll_bubblesort(&head);


    return 0;
}
