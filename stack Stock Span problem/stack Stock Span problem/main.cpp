//
//  main.cpp
//  stack Stock Span problem
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using std::vector;
using namespace std;
void findSpanDays(vector<int> &dp, vector<int> &span)
{
    stack<int> s;
    span[0] = 1;
    s.push(0);
    for(int i=1;i<dp.size();i++)
    {
        while(!s.empty() && dp[s.top()]<=dp[i])
            s.pop();
        if(s.empty())
            span[i] = i+1;
        else
            span[i] = i-s.top();
        s.push(i);
    }
}

int main()
{
    vector<int> dailyPrice = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span(dailyPrice.size());
    findSpanDays(dailyPrice, span);
    cout<<"Daily prices: ";
    for(int i=0;i<dailyPrice.size();i++)
    {
        cout<<dailyPrice[i]<<" ";
    }
    cout<<endl;
    cout<<"Span: ";
    for(int i=0;i<dailyPrice.size();i++)
    {
        cout<<span[i]<<" ";
    }

    return 0;
}
