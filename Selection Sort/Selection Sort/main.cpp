//
//  main.cpp
//  Selection Sort
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <vector>
using std::vector;
using namespace std;
class SelectionSort
{
public:
    SelectionSort(int *a,int n) //a is array from client
    {
        arr = a;
        size = n;
    }
    void printArr() const;
    void sort();
    
private:
    int *arr;
    int size = 0;

};
void SelectionSort::printArr() const
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void SelectionSort::sort()
{
    for(int i=0;i<size;i++)
    {
        int min = arr[i];
        int minPos = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                minPos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}
int main()
{
    int a[] = {3,2,1,5,6,11,12,-5};
    SelectionSort myArr(a,8);
    myArr.printArr();
    myArr.sort();
    myArr.printArr();

    return 0;
}
