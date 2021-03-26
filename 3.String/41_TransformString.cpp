#include<bits/stdc++.h>
using namespace std;

int transform(string s, string t)
{
    int freq[256] = {0};
    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }
    for(int i = 0; i < s.size(); i++)
    {
        freq[t[i]]--;
    }
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
            return -1;
    }

    int i = s.size()-1, j = s.size()-1;
    int count = 0;
    while(i >= 0)
    {
        while(i >= 0 && s[i] != t[j])
        { 
            i--;
            count++;
        }
        if(i >= 0)
        {
            i--;    j--;
        }
    }
    return count;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << transform(s, t);
    return 0;
}