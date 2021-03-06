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
   return knapsack(W, wt, val, N);
}


int knapSack(int W, int wt[], int val[], int n) 
{ 
   long long int **dp = new long long int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new long long int[W + 1]();
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    long long int ans = dp[n][W];

    for (int i = 0; i < n + 1; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return ans;
}