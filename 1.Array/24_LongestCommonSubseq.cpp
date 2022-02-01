#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

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