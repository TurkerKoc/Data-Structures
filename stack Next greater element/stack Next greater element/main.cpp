//
//  main.cpp
//  stack Next greater element
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using std::vector;
using namespace std;
void NGE(vector<int> &arr)
{
    stack<int> S;
    S.push(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        while(!S.empty()&&arr[i]>S.top())
        {
            cout<<"Next greater element of "<<S.top()<<" = "<<arr[i]<<endl;
            S.pop();
        }
        S.push(arr[i]);
    }
    while(!S.empty())
    {
        cout<<"Next greater element of "<<S.top()<<" = -1"<<endl;
        S.pop();
    }
}
int main()
{
    vector<int> arr = {33, 13, 21, 3};
    NGE(arr);

    return 0;
}
