#include<bits/stdc++.h>
using namespace std;


int mod = 1e9 + 7;
int dp[1001][801];
int solve(int n, int r)
{
    if(r > n)
        return 0;
    if(r == 0 || r == n)
        return 1;
        
    if(dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = (solve(n-1, r-1)%mod + solve(n-1, r)%mod)%mod;
}
    
int nCr(int n, int r)
{
    memset(dp, -1, sizeof(dp));    
    return solve(n, r);       
}