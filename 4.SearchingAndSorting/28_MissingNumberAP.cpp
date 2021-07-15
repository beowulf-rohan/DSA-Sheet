#include<iostream>
using namespace std;

int missingAP(int* arr, int n)
{
    int diff = (arr[n-1]-arr[0])/n;

    int si = 0, ei = n-1;

    int ans = -1;

    while(si < ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid+1]-arr[mid] != diff)
        {
            ans = arr[mid] + diff;
            break;
        }
        if(mid > 0 && arr[mid]-arr[mid-1] != diff)
        {

            ans = arr[mid-1]+diff;
            break;
        }
        
        if(arr[mid] == arr[0] + mid*diff)
            si = mid+1;
        else
            ei = mid-1;
    }
    return ans;
}