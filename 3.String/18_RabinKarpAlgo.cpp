#include<bits/stdc++.h>
using namespace std;


vector<int> rabinKarp(string text, string pat)
{
    vector<int> v;
    int t = 0, p = 0;
    int n = text.size(), m = pat.size();
    int mod = 107;

    for(int i = 0; i < m; i++)
    {
        t = (t + text[i])%mod;
        p = (p + pat[i])%mod;
    }

    for(int i = 0; i <= n-m; i++)
    {
        if(t == p)
        {
            int j;
            for(j = 0; j < m; j++)
            {
                if(text[i+j] != pat[j])
                    break;
            }
            if(j == m)
                v.push_back(i);
        }

        if(i < n-m)
        {
            t = (t - text[i] + text[i+m]);
            t = (t+mod)%mod;
        }
    }
    return v;
}

int main()
{
    string s = "GEEKS FOR GEEKS", t = "GEEKS";
    vector<int> v = rabinKarp(s, t);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}