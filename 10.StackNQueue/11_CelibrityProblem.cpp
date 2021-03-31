#include<bits/stdc++.h>
using namespace std;


int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> st;
    for(int i = 0; i < n; i++)
        st.push(i);
        
    while(st.size() > 1)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
            
        if(M[i][j] == 1)
            st.push(j);
        else
            st.push(i);
    }
        
    int candidate = st.top();
        
    bool isFound = true;
    for(int i = 0; i < n; i++)
    {
        if(i != candidate)
        {
            if(M[i][candidate] == 0 || M[candidate][i] == 1)
                isFound = false;
        }        
    }        
    return (isFound) ? candidate : -1;
}