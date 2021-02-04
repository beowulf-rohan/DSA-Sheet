#include<iostream>

using namespace std;

long long int kadanes(int *arr, int n)
{
    long long int sum = 0, maxSum = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
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

        cout << kadanes(a, n) << endl;
    }
    return 0;
}