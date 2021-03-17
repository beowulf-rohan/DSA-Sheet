#include<bits/stdc++.h>
using namespace std;

//TC - O(n2).... SC - O(n)....
void wordWrap(int* arr, int n, int l)
{
    int dp[n];
    int ans[n];
    int cost;
    
    dp[n-1] = 0;
    ans[n-1] = n-1;
    for(int i = n-2; i >= 0; i--)
    {
        int currLen = -1;
        dp[i] = INT_MAX;
        for(int j = i; j < n; j++)
        {
            currLen += (arr[j]+1);
            if(currLen > l)
                break;
            
            if(j == n-1)
                cost = 0;
            else
                cost = (l-currLen)*(l-currLen) + dp[j+1];
            
            if(cost < dp[i])
            {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }
    
    int i = 0;
    while(i < n)
    {
        cout << i+1 << " " << ans[i] + 1 << " ";
        i = ans[i]+1;
    }
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    int l;
	    cin >> l;
	    
	    wordWrap(arr, n, l);
	    cout << endl;
	}
	return 0;
}


//TC - O(n2).... SC - O(n2)....
void print(int* path, int n)
{
    if(path[n] == 1)
        cout << path[n] << " " << n << " ";
    else
    {
        print(path, path[n]-1);
        cout << path[n] << " " << n << " ";
    }
}

void wordWrap(int* arr, int n, int l)
{
    int space[n+1][n+1];
    int cost[n+1];
    int path[n+1];
    
    //space calc....
    for(int i = 1; i <= n; i++)
    {
        space[i][i] = l - arr[i];
        for(int j = i+1; j <= n; j++)
        {
            space[i][j] = space[i][j-1] - (arr[j]+1);
        }
    }
    
    //cost calc....
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(space[i][j] < 0)
                space[i][j] = INT_MAX;
            else if(j == n)
                space[i][j] = 0;
            else
                space[i][j] = space[i][j]*space[i][j];
        }
    }
    
    //find path....
    cost[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cost[i] = INT_MAX;
        for(int j = 1; j <= i; j++)
        {
            if(cost[j-1] != INT_MAX && space[j][i] != INT_MAX && cost[j-1] + space[j][i] < cost[i])
            {
                cost[i] = cost[j-1] + space[j][i];
                path[i] = j;
            }
        }
    }
    
    //print path....
    print(path, n);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n+1];
	    for(int i = 1; i <= n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    int l;
	    cin >> l;
	    
	    wordWrap(arr, n, l);
	    cout << endl;
	}
	return 0;
}
