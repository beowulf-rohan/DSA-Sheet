#include<bits/stdc++.h>
using namespace std;

int dp[31][31];
int countPalin(string str, int i, int j)
{
    if(i > j)
        return 0;
    
    if(i == j)
        return 1;
        
    if(dp[i][j] != -1)  
        return dp[i][j];
    
    if(str[i] == str[j])
        return dp[i][j] = countPalin(str, i+1, j) + countPalin(str, i, j-1) + 1;
    else
        return dp[i][j] = countPalin(str, i+1, j) + countPalin(str, i, j-1) - countPalin(str, i+1, j-1);
}

int countPS(string str)
{
    memset(dp, -1, sizeof(dp));
    return countPalin(str, 0, str.size()-1);
}