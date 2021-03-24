#include<bits/stdc++.h>
using namespace std;

// TC - (N*|S|log|S|).... SC - O(N*|S|)....
vector<vector<string>> Anagrams(vector<string>& list) 
{
    unordered_map<string, vector<string>> mp;
    for(int i = 0; i < list.size(); i++)
    {
        string s = list[i];
        sort(s.begin(), s.end());
        
        mp[s].push_back(list[i]);
    }
    
    vector<vector<string>> output;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        output.push_back(it->second);
    }
    
    return output;
}

// TC - (NlogN + N*|S|log|S|).... SC - O(N*|S|)....
vector<vector<string>> Anagrams(vector<string>& list) 
{
    int n = list.size();
    vector<vector<string>> output;
    vector<pair<string, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        string s = list[i];
        sort(s.begin(), s.end());
        v[i].first = s;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    
    vector<string> temp;
    for(int i = 0; i < n; i++)
    {
        int j;
        temp.push_back(list[v[i].second]);
        for(j = i+1; j < n; j++)
        {
            if(v[j-1].first == v[j].first) 
                temp.push_back(list[v[j].second]);
            else
            {
                j--;
                break;
            }
        }
        output.push_back(temp);
        temp.clear();
        i = j;
    }
    return output;
}