#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int dp[31][31];

int countPalinSubs(string str, int i, int j)
{
    if(i > j)
        return dp[i][j] = 0;
    if(i == j)
        return dp[i][j] = 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str[i] == str[j])
        return dp[i][j] = countPalinSubs(str, i+1, j) + countPalinSubs(str, i, j-1) + 1;
    else
        return dp[i][j] = countPalinSubs(str, i+1, j) + countPalinSubs(str, i, j-1) - countPalinSubs(str, i+1, j-1);
    
}


int countPS(string str)
{
   memset(dp, -1, sizeof(dp));
   return countPalinSubs(str, 0, str.size()-1);
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << countPS(s) << endl;
    }
    return 0;
}