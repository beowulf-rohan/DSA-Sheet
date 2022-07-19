#include<bits/stdc++.h>
using namespace std;

string reverse(string str)
{
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
        st.push(str[i]);
    
    str = "";
    while(st.size() != 0)
    {
        str += st.top();
        st.pop();
    }
    return str;
}