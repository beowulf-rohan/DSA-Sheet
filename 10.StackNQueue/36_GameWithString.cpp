#include<bits/stdc++.h>
using namespace std;

int minValue(string s, int k)
{
    int n = s.size();
    if(k > n)
        return 0;
    int arr[26] = {0};
    for(int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;
    }
    
    priority_queue<int> pq;
    for(int i = 0; i < 26; i++)
    {
        pq.push(arr[i]);
    }
        
    while(k > 0)
    {
        int max = pq.top();
        pq.pop();
        max--;
        pq.push(max);
        k--;
    }
    
    int sum = 0;
    while(pq.size() != 0)
    {
        sum += (pq.top()*pq.top());
        pq.pop();
    }
    return sum;
}