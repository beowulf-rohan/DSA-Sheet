#include<bits/stdc++.h>
using namespace std;

int getLPS(string s)
{
    int len = s.size();
    int* lps = new int[len];
    int i = 1, j = 0;
    lps[0] = 0;
    while(i < len)
    {
        if(s[i] == s[j])
        {
            lps[i] = j+1;
            i++;    j++;
        }
        else
        {
            if(j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
    int ans = lps[len-1];
    delete [] lps;
    return ans;
}