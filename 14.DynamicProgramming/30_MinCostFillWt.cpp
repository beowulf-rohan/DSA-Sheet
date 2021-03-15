#include<bits/stdc++.h>
using namespace std;

int minimumCost(int cost[], int n, int w) 
{ 
	int wt[n];
	for(int i = 0; i < n; i++)
	    wt[i] = i+1;
	   
    long long int dp[n+1][w+1];
    for(int i = 0; i < n+1; i++)
        {
        for(int j = 0; j < w+1; j++)
        {
            if(i == 0)
                dp[i][j] = INT_MAX;
            else if(j == 0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j && cost[i-1] != -1)
                dp[i][j] = min(dp[i-1][j], dp[i][j-wt[i-1]] + cost[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
        
    if(dp[n][w] == INT_MAX)
        return -1;
    return dp[n][w];
}