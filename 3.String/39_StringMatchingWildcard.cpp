#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int dp[1001][1001];

int solve(string s, string t, int i, int j)
{
    if(i == -1 && j == -1)
        return 1;
    if(j == -1)
    {
        for(int k = 0; k < i; k++)
        {
            if(s[k] != '*')
                return 0;
        }
        return 1;
    }
    if(i == -1)
        return 0;
    
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == t[j] || s[i] == '?')
        return dp[i][j] = solve(s, t, i-1, j-1);
    else if(s[i] == '*')
    {
        int opt1 = solve(s, t, i-1, j);
        int opt2 = solve(s, t, i, j-1);
        
        return dp[i][j] = opt1+opt2;
    }    
    else
        return dp[i][j] = 0;
    
}

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    string s, t;
	    cin >> s >> t;
	    
	    memset(dp, -1, sizeof(dp));
	    
	    if(solve(s, t, s.size()-1, t.size()-1))
	        cout << "Yes\n";
	    else
	        cout << "No\n";
	}
	return 0;
}