#include<bits/stdc++.h>
using namespace std;

#include<stack>

bool ispar(string s)
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        
        if(st.size() == 0)
            return false;
        
        if(s[i] == ')')
        {
            char open = st.top();
            st.pop();
            if(open != '(')
                return false;
        }
        else if(s[i] == '}')
        {
            char open = st.top();
            st.pop();
            if(open != '{')
                return false;
        }
        else if(s[i] == ']')
        {
            char open = st.top();
            st.pop();
            if(open != '[')
                return false;
        }
    }
    
    return (st.size() == 0);
}
