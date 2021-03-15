#include<bits/stdc++.h>
using namespace std;

int kadanes(int* temp, int n)
{
    int maxSum = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += temp[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}

int maxSumRect(int** arr, int n, int m)
{
    int maxSum = INT_MIN;
    for(int left = 0; left < m; left++)
    {
        int* temp = new int[n]();
        for(int right = left; right < m; right++)
        {
            for(int i = 0; i < n; i++)
            {
                temp[i] += arr[i][right];
            }
            maxSum = max(maxSum, kadanes(temp, n));
        }
        delete [] temp;
    }
    
    return maxSum;
}

int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
    	cin >> n >> m;
	
	    int** arr = new int*[n];
	    for(int i = 0; i < n; i++)
    	{
	        arr[i] = new int[m];
	        for(int j = 0; j < m; j++)
    	    {
	            cin >> arr[i][j];
	        }
	    }
	
    	cout << maxSumRect(arr, n, m) << endl;
	
	    for(int i = 0; i < n; i++)
	    {
	        delete [] arr[i];
    	}
	    delete [] arr;
	}
	
	return 0;
}