#include<bits/stdc++.h>
using namespace std;

typedef long long int cpp_int;

cpp_int dp[101];
cpp_int catalan(int n)
{
    if(n <= 1)
        return 1;
        
    if(dp[n] != -1)
        return dp[n];
    cpp_int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (catalan(i)*catalan(n-i-1));
    }
    return dp[n] = ans;
}

cpp_int findCatalan(int n)
{    
    for(int i = 0; i < 101; i++)
    {
        dp[i] = -1;
    }
    return catalan(n);
}



cpp_int findCatalan(int n) 
{
    cpp_int dp[n+1];
    dp[0] = 1;  dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for(int j = 0; j < i; j++)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}