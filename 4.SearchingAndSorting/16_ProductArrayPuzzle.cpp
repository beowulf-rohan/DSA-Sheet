#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

vector<ll> prodPuzzle(vector<ll> arr, int n)
{
    vector<ll> prod(n, 1);
    
    ll temp = 1;
    for(int i = 1; i < n; i++)
    {
       temp = temp*arr[i-1];
       prod[i] = prod[i]*temp;
    }
    
    temp = 1;
    for(int i = n-2; i >= 0; i--)
    {
        temp = temp*arr[i+1];
        prod[i] = prod[i]*temp;
    }
    return prod;
}