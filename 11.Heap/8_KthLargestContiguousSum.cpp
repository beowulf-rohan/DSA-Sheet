#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[], int n, int k)
{
	int sum[n+1] = {0};
    sum[0] = 0;
    sum[1] = arr[0];
    for(int i = 2; i <= n; i++)
    {
        sum[i] = sum[i-1] + arr[i-1];
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int s = sum[j] - sum[i-1];
            if(pq.size() == k)
            {
                if(pq.top() < s)
                {
                    pq.pop();
                    pq.push(s);
                }
            }
            else
            {
                pq.push(s);
            }
        }
    }
    return pq.top();
}