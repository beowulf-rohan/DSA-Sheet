#include<bits/stdc++.h>
using namespace std;

struct val
{
	int first;
	int second;
};

// Greedy method.....
// TC - O(nlogn).... SC - O(1)....
bool compare(val a, val b)
{
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, compare);
    
    int low = p[0].second;
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if(p[i].first > low)
        {
            low = p[i].second;
            count++;
        }
        else
        {
            low = min(low, p[i].second);
        }
    }
    return count;
}

// DP method....
// TC - O(n2).... SC - O(n)....
bool compare(val a, val b)
{
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, compare);
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(p[j].second < p[i].first)
                dp[i] = max(dp[i], 1+dp[j]);
        }
    }
    
    return dp[n-1];
}