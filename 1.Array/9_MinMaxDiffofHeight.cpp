#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int getMinDiff(int arr[], int n, int k) 
{
    int maxE, minE, minDiff;
    sort(arr, arr+n);
    minDiff = arr[n-1] - arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= k)
        {
            maxE = max(arr[n-1]-k, arr[i-1]+k);
            minE = min(arr[0]+k, arr[i]-k);
            minDiff = min(minDiff, maxE-minE);
        }
    }
    return minDiff;       
}