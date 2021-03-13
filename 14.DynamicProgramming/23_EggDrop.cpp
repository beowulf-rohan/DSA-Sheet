#include<bits/stdc++.h>
using namespace std;

int dp[11][51];
int eggdrop(int e, int f)
{
    if(f <= 1 || e == 1)
        return f;
    
    if(dp[e][f] != -1)
        return dp[e][f];
    
    int ans = INT_MAX;
    for(int k = 1; k < f; k++)
    {
        int temp = 1+max(eggdrop(e, f-k), eggdrop(e-1, k-1));
        ans = min(temp, ans);
    }
    return dp[e][f] = ans;
}

int eggDrop(int e, int f) 
{
    memset(dp, -1, sizeof(dp));
    return eggdrop(e, f);
}