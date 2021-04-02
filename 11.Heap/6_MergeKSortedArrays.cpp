#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> ppi;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> v(k*k);
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for(int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
        
    int idx = 0;
    while(pq.size() != 0)
    {
        ppi current = pq.top();
        pq.pop();
            
        int val = current.first;
        int i = current.second.first, j = current.second.second;
            
        v[idx++] = val;
        
        if(j != k-1)
            pq.push({arr[i][j+1], {i, j+1}});
    }
        
    return v;
}