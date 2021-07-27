#include<bits/stdc++.h>
using namespace std;

bool redundance(string s)
{
    stack<char> st;
    for(int i = 0; i< s.size(); i++)
    {
        int ch = s[i];
        if(ch == ')')
        {
            int top = st.top();
            st.pop();

            bool flag = true;
            while(top != '(')
            {
                if(top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }

            if(flag == true)
                return true;
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}