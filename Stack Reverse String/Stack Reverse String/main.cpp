//
//  main.cpp
//  Stack Reverse String
//
//  Created by Turker Koc on 11.11.2018.
//  Copyright © 2018 Turker Koc. All rights reserved.
//

#include <iostream>
using namespace std;
#include <stack>
void reverse(string &n)
{
    stack<char> s;
    for(int i=0;i<n.length();i++)
    {
        s.push(n[i]);
    }
    for(int i=0;i<n.length();i++)
    {
        n[i]=s.top();
        s.pop();
    }

}
int main()
{
    string n;
    cout<<"Enter a string: ";
    cin>>n;
    reverse(n);
    cout<<"reversed string: "<<n<<endl;
    
    
    
    
    return 0;
}
