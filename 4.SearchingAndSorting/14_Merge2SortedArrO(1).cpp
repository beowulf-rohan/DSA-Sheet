#include <iostream>

using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return gap / 2 + gap % 2;
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int i, j, gap = m + n;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        for (j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> arr2[j];
    }

    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int j = 0; j < m; j++)
    {
        cout << arr2[j] << " ";
    }
    cout << endl;

    return 0;
}