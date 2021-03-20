#include<bits/stdc++.h>
using namespace std;


int dp[101][101];

int optimal(int* arr, int i, int j)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int left = arr[i] + min(optimal(arr, i+2, j), optimal(arr, i+1, j-1));
    int right = arr[j] + min(optimal(arr, i, j-2), optimal(arr, i+1, j-1));
    
    return dp[i][j] = max(left, right);
}

long long maximumAmount(int arr[], int n) 
{
    memset(dp, -1, sizeof(dp));
    return optimal(arr, 0, n-1);
}