#include<bits/stdc++.h>
using namespace std;

int bSearch(int* dp, int si, int ei, int x)
{
    while(si < ei)
    {
        int mid = (si+ei)/2;
        if(x >= dp[mid])
            si = mid+1;
        else
            ei = mid;
    }
    return si;
}

int longestSubsequence(int n, int a[])
{
    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
   
    for(int i = 0; i < n; i++)
    {
        int idx = bSearch(dp, 0, n+1, a[i]);
        if(a[i] > dp[idx-1] && a[i] < dp[idx])
            dp[idx] = a[i];
    }
    int ans = 0;
    for(int i = n; i >= 0; i--)
    {
        if(dp[i] != INT_MAX)
        {
            ans = i;    
            break;
        }
    }
    return ans;
}