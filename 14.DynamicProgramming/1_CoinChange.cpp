long long int count(int coins[], int n, int sum)
{

    long long int **dp = new long long int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new long long int[sum + 1]();
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    long long int ans = dp[n][sum];
    for (int i = 0; i < n + 1; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;

    return ans;
}