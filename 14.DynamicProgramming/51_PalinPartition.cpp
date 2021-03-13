#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
bool isPalindrome(string s, int i, int j)
{
    if(i >= j)
        return true;
    while(i < j)
    {   
        if(s[i] != s[j])
            return false;
        i++;    j--;
    }
    return true;
}

int PalinPartition(string s, int i, int j)
{
    if(i >= j || isPalindrome(s, i, j))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT32_MAX;
    for(int k = i; k < j; k++)
    {
        int opt1, opt2;
        if(dp[i][k] != -1)
            opt1 = dp[i][k];
        else
            opt1 = PalinPartition(s, i, k);
        if(dp[k+1][j] != -1)
            opt2 = dp[k+1][j];
        else
            opt2 = PalinPartition(s, k+1,j);
        int tempAns = 1 + opt1 + opt2;
        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}
    
int palindromicPartition(string str)
{
    return PalinPartition(str, 0, str.size()-1);
}