#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pp;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    int minE = INT_MAX, maxE = INT_MIN;
    int start = 0, end = 0, range = INT_MAX;
    
    for(int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], {i, 0}});
        maxE = max(maxE, arr[i][0]);
    }
    
    while(pq.size() == k)
    {
        pp curr = pq.top();
        pq.pop();
        
        int minE = curr.first;
        int i = curr.second.first, j = curr.second.second;
        
        if(maxE - minE < range)
        {
            range = maxE - minE;
            start = minE;  end = maxE;
        }
        
        if(j != n-1)
        {
            pq.push({arr[i][j+1], {i, j+1}});
            maxE = max(maxE, arr[i][j+1]);
        }
    }
    
    return {start, end};
}