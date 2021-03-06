#include<bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            dp[i][m-1] = M[i][m-1];
        }
        
        for(int j = m-2; j >= 0; j--)
        {
            for(int i = 0; i < n; i++)
            {
                int mx = dp[i][j+1];
    			if(i-1 >= 0) 
	    			mx=max(mx,dp[i-1][j+1]);
		    	if(i+1 <n)
			    	mx=max(mx,dp[i+1][j+1]);
			    dp[i][j] = mx + M[i][j];
            }
        }
        
        int maxGold = 0;
        for(int i = 0; i < n; i++)
        {
            maxGold = max(dp[i][0], maxGold);
        }
        return maxGold;
    }