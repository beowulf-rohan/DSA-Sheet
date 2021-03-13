#include<bits/stdc++.h>
using namespace std;


// DP method...
// TC - O(n2).... SC - O(n)....
int minJumps(int arr[], int n)
{
    int dp[n];
    
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(dp[j] == INT_MAX)
                continue;
            if(arr[j]+j >= i)
                dp[i] = min(dp[i], dp[j]+1);
        }
    }
    
    return dp[n-1] == INT_MAX ? -1 : dp[n-1];
}


// Greedy method...
// TC - O(n).... SC - O(1)....
int minJumps(int arr[], int n)
{
    if(n == 1)
        return 0;
    if(arr[0] == 0)
        return -1;
        
    int steps = arr[0];
    int maxReach = arr[0];
    int jumps = 1;
    for(int i = 1; i < n; i++)
    {
        if(i == n-1)
            return jumps;
        
        steps--;
        maxReach = max(maxReach, i+arr[i]);
        if(steps == 0)
        {
            jumps++;
            if(i >= maxReach)
                return -1;
            steps = maxReach-i;
        }
    }
}
