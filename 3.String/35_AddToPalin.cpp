#include<bits/stdc++.h>
using namespace std;

vector<int> getLPS(string s)
{
    int n = s.size();
    
    vector<int> lps(n);
    int i = 1, j = 0;
    
    lps[0] = 0;
    while(i < n)
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
    return lps;
}

int addToFrontPalin(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());

    string common = str + "$" + rev;
    vector<int> lps = getLPS(common);

    return (str.size()-lps.back());
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << addToFrontPalin(s) << endl;
    }
    return 0;
}