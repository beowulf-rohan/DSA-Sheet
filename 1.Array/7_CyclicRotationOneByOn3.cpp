#include <iostream>

using namespace std;

void reverse(int *a, int n)
{
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        a[j] = a[i] + a[j] - (a[i] = a[j]);
    }
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
        {
            cin >> a[i];
        }

        reverse(a, n);
        reverse(a + 1, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}