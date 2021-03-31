#include<bits/stdc++.h>
using namespace std;

bool isDigit(char ch)
{
    return (ch != '+' && ch != '-' && ch != '*' && ch != '/');
}

// POST - FIX....
int evaluatePostfix(string str)
{        
    stack<int> st;
    for(int i = 0; i < str.size(); i++)
    {
        if(isDigit(str[i]))
            st.push(str[i]-'0');
        else
        {
            int q = st.top();   st.pop();
            int p = st.top();   st.pop();
            if(str[i] == '+')
                st.push(p+q);
            else if(str[i] == '-')
                st.push(p-q);
            else if(str[i] == '*')
                st.push(p*q);
            else if(str[i] == '/')
                st.push(p/q);
        }
    }
    return st.top();
}


// PRE - FIX....
int evaluatePretfix(string str)
{
    reverse(str.begin(), str.end());
    stack<int> st;
    for(int i = 0; i < str.size(); i++)
    {
        if(isDigit(str[i]))
            st.push(str[i]-'0');
        else
        {
            int p = st.top();   st.pop();
            int q = st.top();   st.pop();
            if(str[i] == '+')
                st.push(p+q);
            else if(str[i] == '-')
                st.push(p-q);
            else if(str[i] == '*')
                st.push(p*q);
            else if(str[i] == '/')
                st.push(p/q);
        }
    }
    return st.top();
}