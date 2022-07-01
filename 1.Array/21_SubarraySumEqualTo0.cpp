#include<iostream>
#include<unordered_map>

using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, bool> mp;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(mp[sum] == true || sum == 0)
            return true;
        mp[sum] = true;
    }
    return false;
}