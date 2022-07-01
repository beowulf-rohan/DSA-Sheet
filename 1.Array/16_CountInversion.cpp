#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll merge(ll *arr, int l, int m, int r)
{
    int i = l, j = m, k = 0;
    ll count = 0;
    ll temp[r - l + 1];

    while (i < m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += m - i;
        }
    }
    while (i < m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    for (int i = l, k = 0; i <= r; i++, k++)
    {
        arr[i] = temp[k];
    }

    return count;
}

ll mergeSort(ll *arr, int l, int r)
{
    ll count = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;

        ll leftCount = mergeSort(arr, l, mid);
        ll rightCount = mergeSort(arr, mid + 1, r);

        ll mergeCount = merge(arr, l, mid + 1, r);
        count = leftCount + rightCount + mergeCount;
        return count;
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N - 1);
}