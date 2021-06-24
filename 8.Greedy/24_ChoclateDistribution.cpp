#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long int minD = INT_MAX;
    for(int i = 0; i+m-1 < n; i++)
    {
        minD = min(minD, a[i+m-1]-a[i]);
    }
    return minD;
}  