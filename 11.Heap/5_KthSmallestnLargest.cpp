#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
        
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int kthLargest(int* arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}