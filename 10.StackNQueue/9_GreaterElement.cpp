#include<bits/stdc++.h>
#include<stack>
using namespace std;

typedef long long int ll;

//TC - O(n).... SC - O(n)....
vector<ll> rightLarger(vector<ll> arr, int n)
{
    vector<ll> v(n, -1);
    stack<ll> st;
    
    for(int i = n-1; i >= 0; i--)
    {
        while((st.size() != 0) && (st.top() <= arr[i]))
            st.pop();
            
        if(st.size() == 0)
            v[i] = -1;
        else
            v[i] = st.top();
        st.push(arr[i]);
    }
    return v;
}

//TC - O(n).... SC - O(n)....
vector<ll> leftLarger(vector<ll> arr, int n)
{
    vector<ll> v(n, -1);
    stack<ll> st;
    
    for(int i = 0; i < n; i++)
    {
        while((st.size() != 0) && (st.top() <= arr[i]))
            st.pop();
            
        if(st.size() == 0)
            v[i] = -1;
        else
            v[i] = st.top();
        st.push(arr[i]);
    }
    return v;
}