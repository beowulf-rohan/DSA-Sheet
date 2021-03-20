#include<bits/stdc++.h>
using namespace std;


// TC - O(n).... SC - O(n)....
int count(int n)
{
    if(n <= 1)
        return 0;
    if(n == 2)
        return 1;

    int dp[n+1];
    dp[0] = 0;  dp[1] = 0;  dp[2] = 1;

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    }

    return dp[n];
}

// TC - O(n).... SC - O(1)....
int count(int n)
{
    if(n <= 1)
        return 0;
    if(n == 2)
        return 1;

    int prev = 1;   int prevToPrev = 0;
    int curr;
    for(int i = 3; i <= n; i++)
    {
        curr = (i-1) * (prev + prevToPrev);
        prevToPrev = prev;
        prev = curr;
    }

    return curr;
}