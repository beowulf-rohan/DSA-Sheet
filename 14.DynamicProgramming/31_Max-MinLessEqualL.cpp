#include<bits/stdc++.h>
using namespace std;


// TC - O(n2).... SC - O(n2)....
int minRemoval(int* arr, int n, int k)
{
    
}


// TC - O(n2).... SC - O(n2)....
int dp[101][101];
int solve(int* arr, int i, int j, int k)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(arr[j] - arr[i] <= k)
        return dp[i][j] = 0;

    return dp[i][j] = 1 + min(solve(arr, i+1, j, k), solve(arr, i, j+1, k));
}

int minRemoval(int* arr, int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(arr, 0, n-1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minRemoval(arr, n, k);

    return 0;
}