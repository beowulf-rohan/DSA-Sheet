#include<iostream>

using namespace std;

typedef long long int ll;

int *findTwoElement(int *arr, int n)
{    
    int* a = new int[2];

    ll sum1 = 0, sum2 = 0;
    for(int i=0; i < n; i++)
    {
        sum1 += arr[i];
        sum2 += ((ll)arr[i])*arr[i];
    }
    
    ll linear = n*(n+1)/2;
    ll square = n*(n+1)*(2*n+1)/6;
    ll temp1 = sum1-linear;
    ll temp2 = sum2-square;
    
    ll diff = temp1;
    ll sum = temp2/temp1;
    
    ll repeat = (sum+diff)/2;
    ll miss = (sum-diff)/2;
    
    return {repeat, miss};
}