#include<iostream>

using namespace std;

//TC - O(n2).... SC - O(1).....
int rainWater(int* arr, int n)
{
    int res = 0;
    for(int i = 1; i < n-1; i++)
    {
        int curr = arr[i];
        int left = curr, right = curr;
        for(int l = 0; l < i; l++)
        {
            left = max(left, arr[l]);
        }
        for(int r = i+1; r < n; r++)
        {
            right = max(right, arr[r]);
        }
        
        res += (min(left, right) - curr);
    }
    return res;
}

//TC - O(n)..... SC - O(n).....
int rainWater(int arr[], int n)
{
    int res = 0;
    int left[n], right[n];
    
    left[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], arr[i]);
    }
    
    right[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1], arr[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        res += (min(left[i], right[i]) - arr[i]);
    }
    
    return res;
}

//TC - O(n)..... SC - O(1).....
int rainWater(int* arr, int n)
{

}
