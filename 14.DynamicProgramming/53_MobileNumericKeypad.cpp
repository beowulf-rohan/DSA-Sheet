#include<bits/stdc++.h>
using namespace std;

int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
long long int dp[10][26];

long long keys(int i, int j, int n)
{
	if(arr[i][j] == -1)
        return 0;
	if(n == 1)
        return 1;
	    
	if(dp[arr[i][j]][n] != -1)
	    return dp[arr[i][j]][n];
	    
	long long int count = keys(i, j, n-1);
    if(i-1 >= 0)
        count += keys(i-1, j, n-1);
	if(i+1 < 4)
        count += keys(i+1, j, n-1);
	if(j-1 >= 0)
        count += keys(i, j-1, n-1);
	if(j+1 < 3)
	    count += keys(i, j+1, n-1);
    
	return dp[arr[i][j]][n] = count;
}
	
long long getCount(int n)
{
	memset(dp, -1, sizeof(dp));
	long long int count = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
	    {
	        count += keys(i, j, n);
		}
	}
		
	return count;
}