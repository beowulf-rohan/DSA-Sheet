#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Memoization....
/*
int dp[102][102];
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
*/

//Tabulation......
int editDistance(string s, string t)
{
    int m = s.size(), n = t.size();

    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++)
    {
        dp[i][0] = i;
    }
    for(int j = 0; j <n+1; j++)
    {
        dp[0][j] = j;
    }

    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }

    return dp[m][n];
}
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s, t;
        cin >> s >> t;

        cout << editDistance(s, t) << endl;
    }
}