#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int knapsack(int W, int* wt, int* val, int N)
{
    if(N <= 0 || W <= 0)
        return 0;
    
    if(dp[N][W] != -1)
        return dp[N][W];
    
    if(wt[N-1] <= W)
        return dp[N][W] = max(val[N-1] + knapsack(W-wt[N-1], wt, val, N-1), knapsack(W, wt, val, N-1));
    else
        return dp[N][W] = knapsack(W, wt, val, N-1);
}

int knapSack(int W, int wt[], int val[], int N) 
{ 
   memset(dp, -1, sizeof(dp));
   knapsack(W, wt, val, N);
   return dp[N][W];
}