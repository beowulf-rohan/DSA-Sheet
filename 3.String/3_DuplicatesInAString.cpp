#include<iostream>
#include<unordered_map>

using namespace std;

void duplicates(string s)
{
    unordered_map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > 1)
            cout << it->first << " ";
    }
}


int main()
{
    string s;
    cin >> s;

    duplicates(s);

    return 0;
}