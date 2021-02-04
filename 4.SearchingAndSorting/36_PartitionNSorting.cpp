#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int findPivot(int* arr, int l, int r)
{
    int X = arr[l];
    int smallEqualX = 0;

    for(int i = l+1; i <= r; i++)
    {
        if(arr[i] <= X)
            smallEqualX++;
    }

    int pos = l+smallEqualX;
    arr[l] = arr[pos] + arr[l] - (arr[pos] = arr[l]);

    int i = l, j = r;
    while(i < pos && j > pos)
    {
        if(arr[i] <= arr[pos])
            i++;
        else if(arr[j] > arr[pos])
            j--;
        else
        {
            arr[i] = arr[j] + arr[i] - (arr[j] = arr[i]);
            i++;    j--;
        }
    }
    return pos;
}

void quicksort(int* arr, int si, int ei)
{
    if(si >= ei)
        return;
    
    int pivot = findPivot(arr, si, ei);
    
    quicksort(arr, si, pivot-1);
    quicksort(arr, pivot+1, ei);
}

void quickSort(int* arr, int n)
{
    quicksort(arr, 0, n-1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        quickSort(arr, n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
    return 0;
}