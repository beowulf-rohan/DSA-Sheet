#include<bits/stdc++.h>
using namespace std;

int subset(int* arr, int n)
{
    sort(arr, arr+n, greater<int>());

    int totSum = 0, subsetSum = 0;
    for(int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }


    int i = 0, count = 0;
    while(true)
    {
        subsetSum += arr[i];
        totSum -= arr[i];
        i++;    count++;
        if(subsetSum > totSum)
            break;
    }

    return count;
}