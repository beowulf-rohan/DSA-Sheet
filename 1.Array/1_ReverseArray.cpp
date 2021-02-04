#include<iostream>
using namespace std;

void reverse(int* a, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        a[i] = a[n-1-i] + a[i] - (a[n-i-1] = a[i]);
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

    reverse(a, n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}