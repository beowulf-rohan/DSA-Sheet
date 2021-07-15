 #include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;


bool findInB(vector<string> &B, string A)
{
    for(int i = 0; i < B.size(); i++)
    {
        if(B[i].compare(A) == 0)
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

    // Create the DP table to store results of subroblems. The value wb[i] 
    // will be true if str[0..i-1] can be segmented into dictionary words, 
    // otherwise false. 
    
    for(int i = 1; i <= size; i++)
    {
        if((dp[i] == false) && (findInB(B, A.substr(0, i))))
            dp[i] = true;
        
        if(dp[i] == true)
        {
            if(i == size)
                return true;
            
            for(int j = i+1; j <= size; j++)
            {
                if((dp[j] == false) && (findInB(B, A.substr(i, j-i))))
                    dp[j] = true;
                if(j == size && dp[j] == true)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<string> B(n);
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    string A;
    cin >> A;

    cout << boolalpha << wordBreak(A, B) << endl;

    return 0;
}