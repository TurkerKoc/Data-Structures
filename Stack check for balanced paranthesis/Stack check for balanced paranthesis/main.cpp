//
//  main.cpp
//  Stack check for balanced paranthesis
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
bool CheckParanthesis(string &n)
{
    stack<char> s;
    for(int i=0;i<n.size();i++)
    {
        if(n[i] == '{'||n[i] == '['||n[i] == '(')
            s.push(n[i]);
        else if(n[i] == '}'||n[i] == ']'||n[i] == ')')
        {
            if((n[i] == '}'&&s.top() == '{')||(n[i] == ']'&&s.top() == '[')||(n[i] == ')'&&s.top() == '('))
            {
                s.pop();
            }
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}
int main()
{
    string n;
    cout<<"Enter a string: ";
    cin>>n;
    if(CheckParanthesis(n))
        cout<<"Your paranthesis are true."<<endl;
    else
        cout<<"Your paranthesis are not true."<<endl;

    return 0;
}
