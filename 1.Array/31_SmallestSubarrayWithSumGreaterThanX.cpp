#include<iostream>

using namespace std;

int solve(int* arr, int n, int x)
{
    int currSum = 0, minLen = n+1;
    int start = 0, end = 0;
    
    while(end < n)
    {
        while(end < n && currSum <= x)
            currSum += arr[end++];
        
        while(start < n && currSum > x)
        {
            if(end-start < minLen)
                minLen = end-start;
            currSum -= arr[start++];
        }
    }
    return minLen;
}