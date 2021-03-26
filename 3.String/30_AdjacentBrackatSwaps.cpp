#include<bits/stdc++.h>
using namespace std;


// TC - O(n).... SC - O(1)....
int minimumNumberOfSwaps(string S)
{
    int open = 0, close = 0, diff = 0;
    int result = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == ']')
        {
            close++;
            diff = close - open;
        }
        else
        {
            open++;
            if(diff > 0)
            {
                result += diff;
                diff--;
            }
        }
    }
    return result;
}

// TC - O(n).... SC - O(n)....
int minimumNumberOfSwaps(string S)
{
    vector<int> v;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '[')
            v.push_back(i);
    }
        
    int ans = 0, count = 0, idx = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '[')
        {
            count++;
            idx++;
        }
        else
        {
            count--;
            if(count < 0)
            {
                ans += v[idx]-i;
                swap(S[i], S[v[idx]]);
                count = 1;
                idx++;
            }
        }
    }
    return ans;
}