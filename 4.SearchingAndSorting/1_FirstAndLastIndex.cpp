#include<iostream>
using namespace std;

int bSearch1(int* arr, int si, int ei, int x)
{
    int ans = -1; 
    
    while(si <= ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid] == x)
        {
            ans = mid;
            ei = mid-1;
        }
            
        else if(arr[mid] < x)
            si = mid+1;
        else
            ei = mid-1;
    }
    return ans;
}

int bSearch2(int* arr, int si, int ei, int x)
{
    int ans = -1; 
    
    while(si <= ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid] == x)
        {
            ans = mid;
            si = mid+1;
        }
            
        else if(arr[mid] < x)
            si = mid+1;
        else
            ei = mid-1;
    }
    return ans;
}

void solve(int* arr, int n, int x)
{
    int left = bSearch1(arr, 0, n-1, x);
    int right = bSearch2(arr, 0, n-1, x);
    
    if(left == -1 || right == -1)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        cout << left << " " << right << endl;
        return;
    }
}