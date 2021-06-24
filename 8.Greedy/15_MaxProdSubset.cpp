#include<bits/stdc++.h>
using namespace std;

int maxProd(int* arr, int n)
{
    int negCount = 0, zeroCount = 0;
    int maxNeg = INT_MAX;
    int prod = 1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            zeroCount++;
            continue;
        }
        if(arr[i] < 0)
        {
            maxNeg = max(maxNeg, arr[i]);
            negCount++;
        }

        prod = prod*arr[i];
    }

    if(zeroCount == 0)
        return 0;
    if(negCount&1)
    {
        if(negCount == 1 && zeroCount > 0 && zeroCount + negCount == n)
            return 0;
        prod /= maxNeg;
    }

    return prod;
}