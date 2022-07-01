#include<iostream>
using namespace std;

void reverse(int* a, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        a[i] = a[n-1-i] + a[i] - (a[n-i-1] = a[i]);
    }
}