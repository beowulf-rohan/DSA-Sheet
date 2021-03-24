#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p)
{
    int l1 = s.size(), l2 = p.size();
        
    if(l1 < l2)
        return "-1";        
    int freqStr[256] = {0};
    int freqPat[256] = {0};
    for(int i = 0; i < l2; i++)
    {
        freqPat[p[i]]++;
    }
        
    int count = 0, i = 0, start = -1, minLen = INT_MAX;
    for(int j = 0; j < l1; j++)
    {
        freqStr[s[j]]++;
        if(freqStr[s[j]] <= freqPat[s[j]])
            count++;
        if(count == l2)
        {
            while(freqStr[s[i]] > freqPat[s[i]] || freqPat[s[i]] == 0)
            {
                freqStr[s[i]]--;
                i++;
            }
                
            if(minLen > j-i+1)
            {
                minLen = j-i+1;
                start = i;
            }
        }
    }
    if(start == -1)
        return "-1";
    return s.substr(start, minLen);
}