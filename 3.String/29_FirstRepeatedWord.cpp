#include<bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
{
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    
    int max = 0;
    string  s = "";
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > max)
        {
            s = it->first;
            max = it->second;
        }
    }
        
    mp[s] = 0;

    max = 0;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > max)
        {
            s = it->first;
            max = it->second;
        }
    }
    return s;
}

string secFrequent (string arr[], int n)
{
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
        
    int max1 = 0, max2 = 0;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > max1)
        {
            max2 = max1;
            max1 = it->second;
        }
        else if(it->second > max2 && it->second != max1)
        {
            max2 = it->second;
        }
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second == max2)
        {
            return it->first;
        }
    }
    return "";
}