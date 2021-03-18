#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int> revQ;
    stack<int> st;
    if(k > q.size() || q.size() == 0)
        return revQ;
    
    for(int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    
    while(st.size() != 0)
    {
        revQ.push(st.top());
        st.pop();
    }
    
    while(q.size() != 0)
    {
        revQ.push(q.front());
        q.pop();
    }
    
    return revQ;
}