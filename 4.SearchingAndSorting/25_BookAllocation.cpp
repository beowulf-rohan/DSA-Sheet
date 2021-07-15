#include<iostream>
using namespace std;

bool check(int* arr, int n, int m, int pages)
{
    int count = 1, sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > pages)
        {
            count++;
            sum = arr[i];
        }
    }
    
   return (count <= m);
}

int findPages(int *arr, int n, int m)
{
    int low = 0, high = 0;
    for(int i = 0; i < n; i++)
    {
        high += arr[i];
        low = max(low, arr[i]);
    }
    
    int ans = -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(check(arr, n, m, mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}