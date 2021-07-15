#include<bits/stdc++.h>
using namespace std;

// TC - O(nlogn).... SC - O(1)....
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
        
    int count = 1, maxCount = 1;
    int i = 1, j = 0;
        
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else if(arr[i] > dep[j])
        {
            count--;
            j++;
        }
        
        if(count > maxCount)
            maxCount = count;
    }
    return maxCount;
}


// TC - O(2359*n).... SC - O(n)....
struct Time
{
    int arrival, departure;
};

int findPlatform(int arr[], int dep[], int n)
{
    Time time[n];
    for(int i = 0; i < n; i++)
    {
        time[i].arrival = arr[i];
    	time[i].departure = dep[i];
    }
    	
    int count = 0, maxCount = INT_MIN;
    	
    for(int i = 0; i < 2359; i++)
    {
        count = 0;
    	for(int j = 0; j < n; j++)
    	{
    	    if(i >= time[j].arrival && i <= time[j].departure)
                count++;
    	}
    	maxCount = max(count, maxCount);
    }
    	
    return maxCount;
}