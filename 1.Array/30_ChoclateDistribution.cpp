#include<iostream>
#include<algorithm>

using namespace std;

int solve(int* arr, int n, int m)
{
    if(n < m)
        return -1;
        
    sort(arr, arr+n);
    
    int i = 0, j = m-1, minDiff = INT32_MAX;
    for(; j < n; i++, j++)
    {
        int diff = arr[j]-arr[i];
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}