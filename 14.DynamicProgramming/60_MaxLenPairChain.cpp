#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
    
int findLongestChain(vector<vector<int>>& pairs)
{
    sort(pairs.begin(), pairs.end(), compare);
    int count = 1;
    int idx = 0;
    for(int i = 1; i < pairs.size(); i++)
    {
        if(pairs[idx][1] < pairs[i][0])
        {
            count++;
            idx = i;
        }
    }
    return count;
}