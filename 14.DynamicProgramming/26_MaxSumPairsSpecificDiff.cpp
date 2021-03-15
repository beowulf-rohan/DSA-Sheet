#include<bits/stdc++.h>
using namespace std;

// Greedy method....
// TC - O(nlogn).... SC - O(1)....
int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr+n, greater<int>());
    int i = 0, sum = 0;
    while(i < n-1)
    {
        if(arr[i]-arr[i+1] < k)
        {
            sum += arr[i] + arr[i+1];
            i += 2;
        }
        else
        {
            i += 1;
        }
    }
    return sum;
}


// DP method....
// TC - O(nlogn).... SC - O(n)....
int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr+n);
    int dp[n];
    dp[0] = 0;
    if(arr[1] - arr[0] < k)
        dp[1] = arr[1]+arr[0];
    else
        dp[1] = 0;
    for(int i = 2; i < n; i++)
    {
        if(arr[i]-arr[i-1] < k)
        {
            dp[i] = dp[i-2] + arr[i-1] + arr[i];
        }
        else
        {
            dp[i] = dp[i-1];
        }
    }
    return dp[n-1];
}