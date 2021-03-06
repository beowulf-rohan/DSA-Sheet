#include<bits/stdc++.h>
using namespace std;

long long int p = 1e9+7;
long long int count(long long int* dp, int h)
{
    if(h == 0 || h == 1)
        return 1;
        
    if(dp[h] != -1)
        return dp[h];
        
    dp[h-1] = count(dp, h-1)%p;
    dp[h-2] = count(dp, h-2)%p;
        
    return dp[h] = ((2*dp[h-1]*dp[h-2])%p + (dp[h-1]*dp[h-1])%p)%p;
}

long long int countBT(int h) 
{ 
    long long int dp[h+1];
    memset(dp, -1, sizeof(dp));    
    return count(dp, h);
}