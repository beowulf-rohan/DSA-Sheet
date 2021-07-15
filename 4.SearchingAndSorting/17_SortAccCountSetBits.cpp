#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

typedef long long int ll;

bool compare(int a, int b)
{
    int setA = __builtin_popcount(a);
    int setB = __builtin_popcount(b);
    if(setA > setB)
        return true;
    else
        return false;
}

void sortSetBits(int* arr, int n)
{
    stable_sort(arr, arr+n, compare);
}