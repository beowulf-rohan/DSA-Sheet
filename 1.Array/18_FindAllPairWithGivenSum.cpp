#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int req = k - arr[i];
        if (mp[req] > 0)
        {
            count += mp[req];
            if (req == arr[i])
                count--;
        }
    }
    return count / 2;
}