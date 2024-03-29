#include<iostream>
#include<string>

using namespace std;

int LongestRepeatingSubsequence(string str)
{
	string s1 = str, s2 = str;
	int n = str.size();
		    
	int dp[n+1][n+1];
	for(int i = 0; i < n+1; i++)
    {
		dp[i][0] = 0;		dp[0][i] = 0;
	}
		    
	for(int i = 1; i < n+1; i++)
	{
		for(int j = 1; j < n+1; j++)
        {
		    if(s1[i-1] == s2[j-1] && i != j)
		        dp[i][j] = dp[i-1][j-1] + 1;
		    else
		        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	    }
	}
	return dp[n][n];
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        cout << LongestRepeatingSubsequence(s) << endl;
    }
    return 0;
}