//
//  main.cpp
//  Insertion Sort
//
//  Created by Turker Koc on 13.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
using std::vector;
class InsertionSort
{
public:
    InsertionSort(vector<int> a)
    {
        arr = a;
    }
    void printAll() const;
    void sort();
    
    
    
private:
    vector<int> arr;
    vector<int> size;
};

void InsertionSort::sort()
{
    for(int i=1;i<arr.size();i++)
    {
        int x = arr[i];
        int j;
        for(j=i-1;j>-1 && arr[j] > x;j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = x;
        cout<<"Iteration 1: ";
        printAll();
    }
}
void InsertionSort::printAll() const
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> a = {12,3,6,1,2,9};
    InsertionSort myIns(a);
    myIns.printAll();
    myIns.sort();
    myIns.printAll();
    

    return 0;
}
