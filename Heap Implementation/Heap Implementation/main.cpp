//
//  main.cpp
//  Heap Implementation
//
//  Created by Turker Koc on 9.01.2019.
//  Copyright © 2019 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX_ITEM 100
class heap
{
public:
    heap()
    {
        size = 0;
    }
    bool isEmpty()
    {
        if(size==0)
            return true;
        else
            return false;
    }
    void heapInsert(int newItem);
    int heapDelete(int rootItem);
    void heapRebuild(int rootItem, int *arr, int size);
    void printHeap();
    void heapSort(int *arr, int n);
    
private:
    int arr[MAX_ITEM];
    int size;
};
void heap::heapSort(int *arr, int n)
{
    for(int i=n;i>=0;i--)
        heapRebuild(i, arr, n);
    for(int last=n-1;last>0;last--)
    {
        int temp = arr[0];
        arr[0]=arr[last];
        arr[last]=temp;
        heapRebuild(0, arr, last);
    }
}
void heap::printHeap()
{
    cout<<"Your heap: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heap::heapInsert(int newItem)
{
    if(size>MAX_ITEM)
    {
        cout<<"Full heap";
        return;
    }
    arr[size]=newItem;
    int place = size++;
    int parent = (place-1)/2;
    while(place>0 && arr[parent]<arr[place])
    {
        int temp = arr[parent];
        arr[parent]=arr[place];
        arr[place]=temp;
        place = parent;
        parent = (place-1)/2;
    }
}
int heap::heapDelete(int rootItem)
{
    if(isEmpty())
    {
        cout<<"Empty heap."<<endl;
        return -1;
    }
    rootItem = arr[0];
    arr[0]=arr[--size];
    heapRebuild(0, arr, size);
    return rootItem;
}
void heap::heapRebuild(int rootItem, int *arr, int size)
{
    int child = rootItem*2 +1; //left child position
    if(child<size)
    {
        int rightChild = child + 1;
        if(rightChild<size && arr[rightChild]>arr[child]) //finding bigger child
            child = rightChild;
        if(arr[rootItem]<arr[child])
        {
            int temp = arr[rootItem];
            arr[rootItem] = arr[child];
            arr[child] = temp;
            heapRebuild(child,arr,size);
        }
    }
}
int main()
{
    heap MyHeap;
    MyHeap.heapInsert(10);
    MyHeap.heapInsert(9);
    MyHeap.heapInsert(6);
    MyHeap.heapInsert(3);
    MyHeap.heapInsert(2);
    MyHeap.heapInsert(5);
    MyHeap.printHeap();
    MyHeap.heapInsert(15);
    MyHeap.printHeap();
    int deletedEl = MyHeap.heapDelete(deletedEl);
    cout<<"Deleted element: "<<deletedEl<<endl;
    MyHeap.printHeap();

    deletedEl = MyHeap.heapDelete(deletedEl);
    cout<<"Deleted element: "<<deletedEl<<endl;
    MyHeap.printHeap();
    
    int arr[6]={6,3,5,9,2,10};
    MyHeap.heapSort(arr, 6);
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}
