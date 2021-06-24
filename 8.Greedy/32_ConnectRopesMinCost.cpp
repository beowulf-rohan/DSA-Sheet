#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) 
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
        
    long long int sum = 0;
    while(pq.size() != 1)
    {
        long long int first = pq.top();   pq.pop();
        long long int second = pq.top();  pq.pop();
            
        sum += first+second;
        pq.push(first+second);
    }
        
    return sum;
}