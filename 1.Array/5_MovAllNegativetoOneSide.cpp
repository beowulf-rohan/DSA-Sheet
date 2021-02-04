#include<iostream>

using namespace std;

void move(int* arr, int n)
{
    int l = 0, r = n-1;     //l -> -ve  r -> +ve
    while(l < r)
    {
        if(arr[l] < 0)
            l++;
        if(arr[r] > 0)
            r--;
        
        if(arr[l] > 0 && arr[r] < 0)
        {
            arr[l] = arr[r] + arr[l] - (arr[r] = arr[l]);
            l++;    r--;
        }
    }
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

    move(a, n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}