#include<bits/stdc++.h>

using namespace std;

int search(int* arr, int n, int x, int k)
{
    for(int i = 0; i < n;)
    {
        if(arr[i] == x)
            return i;
        
        int possibleJumps = abs(arr[i]-x)/k;
        int jumps = max(possibleJumps, 1);  // 1 jump if possJumps = 0

        i = i+jumps;
    }
    return -1;
}