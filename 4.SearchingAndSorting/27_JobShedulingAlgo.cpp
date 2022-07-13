#include<bits/stdc++.h>
using namespace std;
struct job
{
    int a, d, p;
};

bool compare(struct job a, struct job b)
{
    return a.d < b.d;
}

int search(job* arr, int si, int ei, int pos)
{
    int index = -1;

    while(si <= ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid].d <= arr[pos].a)
        {
            index = mid;
            si = mid+1;
        }
        else
        {
            ei = mid-1;
        }
    }
    return index;
}

int jobSheduling(job* arr, int n)
{
    
    int* dp = new int[n]();
    dp[0] = arr[0].p;

    for(int i = 1; i < n; i++)
    {
        int prevMax = search(arr, 0, i-1, i);
        if(prevMax != -1)
            dp[i] = max(dp[i-1], arr[i].p + dp[prevMax]);
        else
            dp[i] = max(dp[i-1], arr[i].p);
    }

    int ans = dp[n-1];
    delete [] dp;
    return ans;
}