#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    
    vector<int> output;
    unordered_map<int, int> mp;
    for(int i = 0; i < m; i++)
    {
        mp[mat[0][i]] = 1;
        output.push_back(mat[0][i]);
    }
    
    if(n == 1)
        return output;
    output.clear();
        
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i+1;
                if(i == n-1)
                    output.push_back(mat[i][j]);
            }
        }
    }
    
    return output;
}