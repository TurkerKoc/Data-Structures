//
//  main.cpp
//  Bubble Sort
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
class BubbleSort
{
public:
    BubbleSort(int *a,int n)
    {
        arr = a;
        size = n;
    }
    void printAll();
    void sort();
    void swap(int *x,int *y);
    
    
    
private:
    int *arr;
    int size;
};
void BubbleSort::printAll()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void BubbleSort::sort()
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i=0;i<size-1;i++)
        {
            if(arr[i+1]<arr[i])
            {
                swap(&arr[i],&arr[i+1]);
                sorted = false;
            }
        }
    }
}
void BubbleSort::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a[]={12,3,6,1,2,9};
    BubbleSort myBubble(&a[0],6);
    myBubble.sort();
    myBubble.printAll();
   
    return 0;
}
