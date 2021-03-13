#include<iostream>
#include<vector>
using namespace std;

int maximumPath(int n, vector<vector<int>> M)
{
    int dp[n][n];
        
    for(int i = 0; i < n; i++)
    {
        dp[n-1][i] = M[n-1][i];
    }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                int mx = dp[i+1][j];
                if(j-1 >= 0)
                    mx = max(mx, dp[i+1][j-1]);
                if(j+1 < n)
                    mx = max(mx, dp[i+1][j+1]);
                dp[i][j] = mx + M[i][j];
            }
        }
        
    int maxCost = 0;
    for(int i = 0; i < n; i++)
    {
        maxCost = max(maxCost, dp[0][i]);
    }
    return maxCost;
}