#include<bits/stdc++.h>
using namespace std;


// TC - O(n).... SC - O(n)....
vector<int> rightSmaller(int n, int a[])
{
    vector<int> v(n);
    stack<int> st;
        
    for(int i = n-1; i >= 0; i--)
    {
        while(st.size() != 0 && st.top() >= a[i])
            st.pop();
            
        if(st.size() == 0)
            v[i] = -1;
            
        else
            v[i] = st.top();
        
        st.push(a[i]);
    }
    return v;
}


// TC - O(n).... SC - O(n)....
vector<int> leftSmaller(int n, int a[])
{
    vector<int> v(n);
    stack<int> st;
        
    for(int i = 0; i < n; i++)
    {
        while(st.size() != 0 && st.top() >= a[i])
            st.pop();
            
        if(st.size() == 0)
            v[i] = -1;
            
        else
            v[i] = st.top();
        
        st.push(a[i]);
    }
    return v;
}
