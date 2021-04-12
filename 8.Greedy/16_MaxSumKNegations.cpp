#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int arr[], int n, int k)
{
    sort(arr, arr+n);
    int i = 0;
    while(k != 0 && i < n)
    {
        if(arr[i] < 0)
        {
            arr[i] = -arr[i];
            k--;
        }
        i++;    
    }
        
    long long int sum = 0, minE = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        minE = min(minE, arr[i]);
    }
                
    if(k%2 != 0)
        sum -= 2*minE;
            
    return sum;
}