#include<bits/stdc++.h>
using namespace std;

bool Adjacent(string s)
{
    int freq[256] = {0};
    int maxFreq = 0;
    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
        maxFreq = max(maxFreq, freq[s[i]]);
    }

    return (maxFreq <= s.size()+1-maxFreq);
}