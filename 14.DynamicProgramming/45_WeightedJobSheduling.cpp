#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool compare(Job a, Job b)
{
    return a.finish < b.finish;
}

int bSearch(Job* arr, int* dp, int i)
{
    int low = 0, high = i-1;
    int maxP = 0;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid].finish <= arr[i].start)
        {
            maxP = max(maxP, dp[mid]);
            low = mid+1;
        }
        else
        {
            high = low-1;
        }
    }
    return maxP;
}

int maxProfit(Job* arr, int n)
{
    int dp[n] = {0};
    sort(arr, arr+n, compare);
    
    dp[0] = arr[0].profit;
    int maxP = dp[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = arr[i].profit;
        for(int j = 0; j < i; j++)
        {
            if(arr[j].finish <= arr[i].start)
                dp[i] = max(dp[i], dp[j] + arr[i].profit);
        }
        maxP = max(maxP, dp[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    return maxP;
}

int main()
{
    int n;
    cin >> n;
    
    Job arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    }
    
    cout << maxProfit(arr, n) << endl;
    return 0;
}