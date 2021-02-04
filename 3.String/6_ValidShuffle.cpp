#include<bits/stdc++.h>
#include<string>

using namespace std;

bool validShuffle(string s1, string s2, string str)
{
    int i = 0, j = 0, k = 0;
    while(k != str.size())
    {
        if(i < s1.size() && s1[i] == str[k])
        {    i++;   k++;    }
        else if(j < s2.size() && s2[j] == str[k])
        {    j++;   k++;    }
        else
            return false;
    }

    if(i < s1.size() || j < s2.size())
        return false;
    return true;
}

int main()
{
    string s1, s2, str;
    cin >> s1 >> s2 >> str;

    cout << validShuffle(s1, s2, str);

    return 0;
}