#include <iostream>
#include <unordered_map>

using namespace std;

void NbyK(int *arr, int n, int k)
{
    int val = n / k;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > val)
            cout << it->first << " ";
    }
    return;
}