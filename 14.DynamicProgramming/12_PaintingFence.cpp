#include<bits/stdc++.h>
using namespace std;


int countWays(int n, int k)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return k;
        
    int mod = 1e9+7;
    int diff = k, same = (k%mod*(k-1)%mod)%mod;
    int total = (same%mod + diff%mod)%mod;

    for(int i = 3; i <= n; i++)
    {
        same = diff;
        diff = ((k-1)%mod * total%mod)%mod;
        total = (same%mod + diff%mod)%mod;
    }
    
    return total;
}
