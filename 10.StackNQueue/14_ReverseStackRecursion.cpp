#include <bits/stdc++.h>
#include<stack>
using namespace std;


//TC - O(n).... SC - O(n)....
stack<int> st;
stack<int> rev;

void reverse()
{
    if(st.size() != 0)
    {
        int x = st.top();
        st.pop();
        reverse();
        
        rev.push(x);
    }
}


//TC - O(n2).... SC - O(n) stack space....
stack<int> st;
void insertAtBottom(int x)
{
    if(st.size() == 0)
        st.push(x);
    else
    {
        int a = st.top();
        st.pop();
        insertAtBottom(x);
        
        st.push(a);
    }
}

void reverse()
{
    if(st.size() != 0)
    {
        int x = st.top();
        st.pop();
        reverse();
        
        insertAtBottom(x);
    }
}