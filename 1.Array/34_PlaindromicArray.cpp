#include <iostream>
#include <string>

using namespace std;

int reverse(int num)
{
    int rev = 0, rem;
    while (num > 0)
    {
        rem = num % 10;
        rev = (rev * 10) + rem;
        num /= 10;
    }
    return rev;
}

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (reverse(a[i]) != a[i])
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
}
int reverse(int num)
{
    int rev = 0, rem;
    while (num > 0)
    {
        rem = num % 10;
        rev = (rev * 10) + rem;
        num /= 10;
    }
    return rev;
}
int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (reverse(a[i]) != a[i])
            return 0;
    }
    return 1;
}