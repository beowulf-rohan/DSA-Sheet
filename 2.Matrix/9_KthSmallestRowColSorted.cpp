#include<bits/stdc++.h>
using namespace std;

#define MAX 50
typedef pair<int, pair<int, int>> pp;

int kthSmallest(int arr[MAX][MAX], int n, int k)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    
    for(int i = 0; i < n; i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    
    while(pq.size() != 0 && k != 1)
    {
        pp top = pq.top();
        pq.pop();
        
        int i = top.second.first, j = top.second.second;
        
        k--;
        
        if(j != n-1)
            pq.push({arr[i][j+1], {i, j+1}});
    }
    
    if(pq.size() == 0)
        return -1;
    return pq.top().first;
}