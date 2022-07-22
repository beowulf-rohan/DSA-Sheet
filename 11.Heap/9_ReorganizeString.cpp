#include<bits/stdc++.h>
using namespace std;

typedef pair<int,char> pp;

string reorganizeString(string S)
{
    int n = S.size();

    int count[26] = {0};
    for(int i = 0; i < n; i++)
    {
        count[S[i] - 'a']++;
    }

    priority_queue<pp> pq;
    for(char c = 'a'; c <= 'z'; c++)
    {
        if(count[c - 'a'])
            pq.push({count[c - 'a'],c});
    }

    string str = "";
    pp  prev{-1,'$'};
    while(pq.size() != 0)
    {
        pp curr = pq.top();
        pq.pop();
            
        str = str + curr.second;
            
        if(prev.first > 0)
            pq.push(prev);
        
        (curr.first)--;
        prev = curr;
    }
    return (n == str.size()) ? str : "";
}