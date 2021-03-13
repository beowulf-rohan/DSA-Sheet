#include<iostream>
using namespace std;

int maxProfit(int* arr, int n)
{
    int profit = 0;
    for(int i = 1; i < n; i++)
    {
        int sub = arr[i]-arr[i-1];
        if(sub > 0)
            profit += sub;
    }
    return profit;
}