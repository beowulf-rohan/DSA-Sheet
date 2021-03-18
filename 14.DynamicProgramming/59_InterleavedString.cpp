#include<bits/stdc++.h>
using namespace std;


// TC - O(a*b).... SC - O(a*b).....
int interleave(string A, string B, string C)
{
    int a = A.size(), b = B.size(), c = C.size();
    if(dp[a][b] != -1)
        return dp[a][b];
    if(c == 0)
        return true;
    
    if(C[0] == A[0] && C[0] == B[0])
    {
        dp[a+1][b] = interleave(A.substr(1), B, C.substr(1));
        dp[a][b+1] = interleave(A, B.substr(1), C.substr(1));
        
        return dp[a][b] = dp[a+1][b]|dp[a][b+1];
    }
    else if(C[0] == A[0])
        return dp[a+1][b] = interleave(A.substr(1), B, C.substr(1));
    else if(C[0] == B[0])
        return dp[a][b+1] = interleave(A, B.substr(1), C.substr(1));
    else
        return dp[a][b] = false;
}

bool isInterleave(string A, string B, string C) 
{ 
    int a = A.size(), b = B.size(), c = C.size();
    if(c != a+b)
        return false;
    
    memset(dp, -1, sizeof(dp));
    
    int answer = interleave(A, B, C);
    if(answer == 1)
        return true;
    else
        return false;
}