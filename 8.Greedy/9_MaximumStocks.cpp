#include<bits/stdc++.h>
using namespace std;

int buyMaximum(int* cost, int n, int k)
{
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++)
    {
        arr.push_back({cost[i], i+1});
    }

    sort(arr.begin(), arr.end());

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int price = arr[i].first;
        int stock = arr[i].second;
        if(price*stock <= k)
        {
            count += stock;
            k -= (price*stock);
        }
        else
        {
            count += (k/price);
            k -= price*(k/price);
        }
    }

    return count;
}