//
//  main.cpp
//  Queue implement k queues in a single array
//
//  Created by Turker Koc on 12.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class kQueue
{
public:
    kQueue(int k,int size)
    {
        n = size;
        Qarr = new int[k*n];
        front = new int[k];
        for(int i=0;i<k;i++)
        {
            front[i] = (i*n)-1;
        }
    }
    void Enqueue(int qn,int data); //qn = queue number
    void Dequeue(int qn);
    void printQueue(int qn);
    
    
    
private:
    int *Qarr;
    int n;
    int *front;
    
};
void kQueue::Enqueue(int qn, int data) //for k=3 qn can be 1,2,3
{
    if(front[qn-1]==((qn*n)-1))
    {
        cout<<qn<<". queue is full."<<endl;
        return;
    }
    front[qn-1]++;
    Qarr[front[qn-1]] = data;
}
void kQueue::Dequeue(int qn)
{
    if(front[qn-1]==((qn-1)*n)-1)
    {
        cout<<qn<<". queue is empty."<<endl;
        return;
    }
    front[qn-1]--;
    
}
void kQueue::printQueue(int qn)
{
    if(front[qn-1]==((qn-1)*n)-1)
    {
        cout<<qn<<". queue is empty."<<endl;
        return;
    }
    cout<<qn<<". queue: ";
    for(int i=(qn-1)*n;i<=front[qn-1];i++)
    {
        cout<<Qarr[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    
    kQueue myQueues(3,10);
    myQueues.printQueue(1);
    myQueues.Dequeue(1);
    myQueues.Enqueue(1, 1);
    myQueues.Enqueue(2, 2);
    myQueues.Enqueue(3, 3);
    myQueues.printQueue(1);
    myQueues.printQueue(2);
    myQueues.printQueue(3);
    myQueues.Enqueue(1, 2);
    myQueues.printQueue(1);
    myQueues.Dequeue(1);
    myQueues.printQueue(1);

    
    return 0;
}
