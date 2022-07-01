#include<iostream>

using namespace std;

int maxRepeating(int *arr, int n, int k)
{
    for(int i = 0; i < n; i++)
    {
	    arr[arr[i]%k] += k;
    }
	    
    int max = arr[0]/k, result = 0;
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i]/k > max) 
        { 
            max = arr[i]/k; 
            result = i; 
        } 
    } 
    
    for (int i = 0; i< n; i++) 
    {
        arr[i] = arr[i]%k;
    }
    return result;
}