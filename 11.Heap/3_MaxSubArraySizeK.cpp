#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> v;
    deque<int> dq;
    for(int i = 0; i < k; i++)
    {
        while(dq.size() != 0 && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
    }

    v.push_back(arr[dq.front()]);
            
    for(int i = k; i < n; i++)
    {
        while(dq.size() != 0 && dq.front() <= i-k)
            dq.pop_front();
                
        while(dq.size() != 0 && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
            
        v.push_back(arr[dq.front()]);
    }
    return v;
}