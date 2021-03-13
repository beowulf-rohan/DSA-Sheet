#include<bits/stdc++.h>
using namespace std;


// Greedy method....
// TC - O(n).... SC - O(1)....
int AlternatingaMaxLength(vector<int>&arr)
{
    int n = arr.size();
	int inc = 1, dec = 1;
	for(int i = 1; i < n; i++)
	{
	    if(arr[i] > arr[i-1])
		    inc = dec+1;
        else if(arr[i] < arr[i-1])
		    dec = inc+1;
	}		    
	return max(inc, dec);
}

//DP method.....
// TC - O(n2).... SC - O(n)....
int AlternatingaMaxLength(vector<int>&arr)
{
	int n = arr.size();
	
    int dp[n][2];
	dp[0][0] = 1;   dp[0][1] = 1;
	
    for(int i = 1; i < n; i++)
	{
	    dp[i][0] = 1;   dp[i][1] = 1;
	    for(int j = 0; j < i; j++)
	    {
	    	if(arr[i] > arr[j])
    		    dp[i][0] = max(dp[j][1]+1, dp[i][0]);
		    else if(arr[i] < arr[j])
	            dp[i][1] = max(dp[j][0]+1, dp[i][1]);
	    }
    }
		    
	return max(dp[n-1][0], dp[n-1][1]);
}
