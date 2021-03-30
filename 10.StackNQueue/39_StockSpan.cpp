#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
    vector<int> v(n);
    stack<pair<int, int>> st;    //first - element.... second - index....
    for(int i = 0; i < n; i++)
    {
        while(st.size() != 0 && st.top().first <= price[i])
            st.pop();
            
        if(st.size() == 0)
            v[i] = i+1;
        else
            v[i] = i-st.top().second;
                
        st.push({price[i], i});
    }
    return v;
    
    /*
    stack<int> s;
    s.push(0);
    vector <int> S (n);
        
    // Span value of first day is always 1  
    S[0] =1;
        
    // Calculate span value of remaining days   
    // by linearly checking previous days 
    for(int i=1;i<n;i++)
    {
        // pop from the stack untill you find a greater value in the stack
        while(s.empty()==false and price[s.top()] <= price[i])
        s.pop();
        
        // calculating distance, if stack is empty then the distance is i+1 
        int span = (s.empty()) ? (i+1) : (i-s.top());
        S[i] = span;
        s.push(i);
    }
    return S;
    */
}