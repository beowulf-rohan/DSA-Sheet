#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int arr[], int n);

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}
#include <unordered_map>
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = true;
    }

    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]])
        {
            map[arr[i]] = false;
            int size = 1;
            int front = arr[i] + 1, back = arr[i] - 1;
            while (map[front])
            {
                map[front] = false;
                size++;
                front++;
            }
            while (map[back])
            {
                map[back] = false;
                size++;
                back--;
            }
            maxSize = max(maxSize, size);
        }
    }
    return maxSize;
}