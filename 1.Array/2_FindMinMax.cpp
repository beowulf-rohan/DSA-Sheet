#include<iostream>
using namespace std;

struct Pair
{
    int min, max;
};

Pair solve(int* arr, int n)
{
    Pair minmax;
    int i;
    if(n%2 == 0)
    {
        if(arr[0] > arr[1])
        {
            minmax.max = arr[0]; minmax.min = arr[1];
        }    
        else
        {
            minmax.max = arr[1]; minmax.min = arr[0];
        }
        i = 2;
    }
    else
    {
        minmax.max = arr[0]; minmax.min = arr[0];
        i = 1;
    }

    while(i < n-1)
    {
        if(arr[i] > arr[i+1])
        {
            if(arr[i] > minmax.max)
                minmax.max = arr[i];
            if(arr[i+1] < minmax.min)
                minmax.min = arr[i+1];
        }
        else
        {
            if(arr[i+1] > minmax.max)
                minmax.max = arr[i+1];
            if(arr[i] < minmax.min)
                minmax.min = arr[i];
        }
        i += 2;
    }
    return minmax;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Pair minmax = solve(a, n);

    cout << minmax.min << " " << minmax.max;

    return 0;
}