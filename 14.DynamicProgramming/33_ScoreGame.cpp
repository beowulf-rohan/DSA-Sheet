#include<bits/stdc++.h>
using namespace std;

//If (3, 5) and (5, 3) are same....
long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
	for(int i = 3; i <= n; i++)
	    dp[i] += dp[i-3];
	    
	for(int i = 5; i <= n; i++)
	    dp[i] += dp[i-5];
	    
	for(int i = 10; i <= n; i++)
	    dp[i] += dp[i-10];

	return dp[n];
}


// If (3, 5) and (5, 3) are different....
long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
	for(int i = 1; i <= n; i++)
	{
	    if(i >= 10)
	        dp[i] += dp[i-10];
	    if(i >= 5)
	        dp[i] += dp[i-5];
	    if(i >= 3)
	        dp[i] += dp[i-3];
	}
	return dp[n];
}