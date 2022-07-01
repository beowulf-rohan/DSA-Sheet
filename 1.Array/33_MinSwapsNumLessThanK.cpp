#include<iostream>

using namespace std;

int minSwaps(int* arr, int n, int k)
{
    int lessThanEqualTo = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= k)
            lessThanEqualTo++;
    }
    
    int count = 0;
    for(int i = 0; i < lessThanEqualTo; i++)
    {
        if(arr[i] > k)
            count++;
    }
    
    int minResult = count;
    int i = 0, j = lessThanEqualTo;
    while(j < n)
    {
        if(arr[i] > k)
            count--;
        if(arr[j] > k)
            count++;
        
        i++;    j++;
        minResult = min(minResult, count);
    }
    return minResult;
}