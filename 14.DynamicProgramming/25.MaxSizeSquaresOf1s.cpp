#include<iostream>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    int arr[n][m];
    int dp[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; 
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0];
    }
    
    for(int j = 0; j < m; j++)
    {
        dp[0][j] = arr[0][j];
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(arr[i][j] == 1)
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        }
    }
    
    int maxOnes = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maxOnes = max(maxOnes, dp[i][j]);
        }
    }
    cout << maxOnes << endl;
}

int main()
 {
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
	return 0;
}