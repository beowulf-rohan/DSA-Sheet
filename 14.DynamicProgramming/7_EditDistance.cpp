#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int editDist(string s, string t)
{
	int m = s.size(), n = t.size();
	if(m == 0 || n == 0)
	    return max(m, n);
	       
	if(dp[m][n] != -1)
	    return dp[m][n];
	         
	if(s[0] == t[0])
	    dp[m][n] = editDist(s.substr(1), t.substr(1));
	else
	{
	    dp[m-1][n] = editDist(s.substr(1), t);
	    dp[m][n-1] = editDist(s, t.substr(1));
	    dp[m-1][n-1] = editDist(s.substr(1), t.substr(1));
	            
	    dp[m][n] = 1+min(dp[m-1][n], min(dp[m][n-1], dp[m-1][n-1]));
	}
	return dp[m][n];
}
	
int editDistance(string s, string t)
{
	memset(dp, -1, sizeof(dp));
	return editDist(s, t);
}