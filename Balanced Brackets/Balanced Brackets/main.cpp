#include<iostream>
using namespace std;
#include<stack>

// Complete the isBalanced function below.
string isBalanced(string s)
{
    stack<char> st;
    
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
            st.push(s[i]);
        else if(s[i]=='}'||s[i]==')'||s[i]==']')
        {
            if (st.empty())
            {
                return "NO";
            }
            if(st.top()=='(' && s[i]!=')'||st.top()=='[' && s[i]!=']'||st.top()=='{' && s[i]!='}')
            {
                return "NO";
            }
            else
            {
                st.pop();
            }

        }
        
    }
    if(st.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
    
    
}

int main()
{
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        cin>>s;
        
        string result = isBalanced(s);
        
        cout << result << "\n";
    }
    
    
    return 0;
}


