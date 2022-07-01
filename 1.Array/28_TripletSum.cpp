#include <iostream>
#include <algorithm>

using namespace std;

int solve(int *a, int n, int k)
{
    sort(a, a + n);
    int low, high;
    for (int i = 0; i < n - 1; i++)
    {
        low = i + 1, high = n - 1;
        while (low != high)
        {
            int sum = a[low] + a[high] + a[i];
            if (sum == k)
                return 1;
            else if (sum > k)
                high--;
            else
                low++;
        }
    }
    return 0;
}