#include<bits/stdc++.h>
using namespace std;

string findSubString(string str)
{
    int diff = 0;
    bool* visited = new bool[256]();
    for(int i = 0; i < str.size(); i++)
    {
        if(!visited[str[i]])
        {
            diff++;
            visited[str[i]] = true;
        }
    }
    delete [] visited;
    
    int* mp = new int[256]();
    int count = 0;
    int i = 0, start = -1, minLen = INT_MAX;
    for(int j = 0; j < str.size(); j++)
    {
        mp[str[j]]++;
        if(mp[str[j]] == 1)
            count++;
        if(count == diff)
        {
            while(mp[str[i]] > 1)
            {
                mp[str[i]]--;
                i++;
            }
            
            if(minLen > j-i+1)
            {
                minLen = j-i+1;
                start = i;
            }
        }
    }
    
    delete [] mp;
    
    return str.substr(start, minLen);
}