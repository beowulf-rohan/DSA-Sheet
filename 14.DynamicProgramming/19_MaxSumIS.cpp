#include<bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)  
{  
    int maxElement = arr[0];
	int dp[n];
    dp[0] = arr[0];
	for(int i = 1; i < n; i++)
	{
	    dp[i] = arr[i];
	    for(int j = 0; j < i; j++)
	    {
	        if(arr[i] <= arr[j])
	            continue;
	        dp[i] = max(dp[j]+arr[i], dp[i]);
	    }
	    maxElement = max(maxElement, dp[i]);
	}
	return maxElement;
}