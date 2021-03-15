#include<bits/stdc++.h>
using namespace std;


int dp[501][201][2];
int profit(int* arr, int n, int k, int ongoing)
{
    if(n == 0 || k == 0)
        return 0;
    if(dp[n][k][ongoing] != -1)
        return dp[n][k][ongoing];
        
    int ignore = profit(arr+1, n-1, k, ongoing);
    int notIgnore;
    if(ongoing)
    {
        notIgnore = profit(arr+1, n-1, k-1, 0) + arr[0];
    }
    else
        {
        if(k > 0)
            notIgnore = profit(arr+1, n-1, k, 1) - arr[0];
    }
    return dp[n][k][ongoing] = max(ignore, notIgnore);
}
      
int maxProfit(int k, int n, int* arr)
{
    memset(dp, -1, sizeof(dp));
    return profit(arr, n, k, 0);
}