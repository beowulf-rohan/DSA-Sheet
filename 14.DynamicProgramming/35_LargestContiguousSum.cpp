#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{        
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}