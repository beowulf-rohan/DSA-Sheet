#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{        
    int sum = 0, minSum = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        minSum = min(minSum, sum);
    if(sum > 0)
            sum = 0;
    }
    return minSum;
}