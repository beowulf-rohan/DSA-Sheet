#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int* arr)
{
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j]+1 || arr[i] == arr[j]-1)
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int maxN = 0;
    for(int i = 0; i < n; i++)
    {
        maxN = max(maxN, dp[i]);
    }        
    return maxN;
}