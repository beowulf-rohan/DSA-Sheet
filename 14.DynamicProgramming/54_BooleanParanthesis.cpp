#include<bits/stdc++.h>
using namespace std;

int dp[201][201][2];
int evaluate(string s, int i, int j, int isTrue)
{
    if(i > j)
        return false;
    if(i == j)
    {
        if(isTrue)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }
        
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
        
    int count = 0;
    for(int k = i+1; k < j; k += 2)
    {
        int lT, rT, lF, rF;
        if(dp[i][k-1][true] != -1)
            lT = dp[i][k-1][true];
        else
            lT = evaluate(s, i, k-1, true);
            
        if(dp[i][k-1][false] != -1)
            lF = dp[i][k-1][false];
        else
            lF = evaluate(s, i, k-1, false);
                
        if(dp[k+1][j][true] != -1)
            rT = dp[k+1][j][true];
        else
            rT = evaluate(s, k+1, j, true);
            
        if(dp[k+1][j][false] != -1)
            rF = dp[k+1][j][false];
        else
            rF = evaluate(s, k+1, j, false);   
        
        if(s[k] == '&')
        {
            if(isTrue)
                count = count + (lT*rT);
            else
                count = count + (lT*rF) + (lF*rT) + (lF*rF);
        }
        else if(s[k] == '|')
        {
            if(isTrue)
                count = count + (lT*rT) + (lT*rF) + (lF*rT);
            else
                count = count + (lF*rF);
        }
        else if(s[k] == '^')
        {
            if(isTrue)
                count = count + (lT*rF) + (lF*rT);
            else
                count = count + (lT*rT) + (lF*rF);
        }
    }
    return dp[i][j][isTrue] = count%1003;
}
    
int countWays(int N, string S)
{
    memset(dp, -1, sizeof(dp));
    return evaluate(S, 0, S.size()-1, true);
}