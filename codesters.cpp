//;compile c++ ```
#include<bits/stdc++.h>
using namespace std;

int lowerBound(int* arr, int n, int k)
{
    int l = 0, h = n-1;
    while(l < h)
    {
        int mid = (l+h)/2;
        if(arr[mid] >= k)
            h = mid;
        else
            l = mid+1;
    }
    return l;
}

int upperBound(int* arr, int n, int k)
{
    int l = 0, h = n-1;
    while(l < h)
    {
        int mid = (l+h)/2;
        if(arr[mid] <= k)
            l = mid+1;
        else
            h = mid;
    }
    return l;
}

int main()
{
    int n1 = 8;
    int arr1[n1] = { 5, 5, 5, 6, 6, 6, 7, 7};

    cout << lowerBound(arr1, n1, 6) + 1;
    cout << upperBound(arr1, n1, 6) + 1;
    return 0;
}//```