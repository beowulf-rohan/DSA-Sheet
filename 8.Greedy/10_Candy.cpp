#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies+n);
        
    int min = 0, max = 0;
    for(int i = 0, j = n-1; i <= j; i++, j -= k)
        min += candies[i];
        
    for(int i = n-1, j = 0; i >= j; i--, j += k)
        max += candies[i];
        
        
    vector<int> v;
    v.push_back(min);
    v.push_back(max);
        
    return v;
}