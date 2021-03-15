#include<bits/stdc++.h>
using namespace std;

long long int p = 1e9+7;

long long countWays(int n, int k)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return k;
    int same = k%p;
    int diff = (k*(k-1))%p;
    for(int i = 3; i <= n; i++)
    {
        int prev = diff%p;
        diff = ((same+diff)%p*(k-1)%p)%p;
        same = prev%p;
    }
    return (same+diff)%p;
}