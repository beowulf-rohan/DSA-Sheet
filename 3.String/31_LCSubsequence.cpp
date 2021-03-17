int lcs(int n, int m, string s, string t)
{
    int dp[2][m+1];
    
    int bit;
    for(int i = 0; i < n+1; i++)
    {
        bit = i&1;
        for(int j = 0; j < m+1; j++)
        {
            if(i == 0 || j == 0)
                dp[bit][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[bit][j] = dp[1-bit][j-1] + 1;
            else
                dp[bit][j] = max(dp[1-bit][j], dp[bit][j-1]);
        }
    }
    
    return dp[bit][m];
}