#include<bits/stdc++.h>
using namespace std;

bool findAinB(string A, vector<string> &B)
{
    for(int i = 0; i < B.size(); i++)
    {
        if(B[i] == A)
            return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    int size = A.size();
    if(size == 0)
        return true;
    
    bool dp[size+1];
    memset(dp, false, sizeof(dp));
    
    for(int i = 1; i <= size; i++)
    {
        if((dp[i] == false) && findAinB(A.substr(0, i), B))
            dp[i] = true;
        
        if(dp[i] == true)
        {
            if(i == size)
                return true;
            
            for(int j = i+1; j <= size; j++)
            {
                if((dp[j] == false) && findAinB(A.substr(i, j-i), B))
                    dp[j] = true;
                
                if((dp[j] == true) && j == size)
                    return true;
            }
        }
    }
    return false;
}