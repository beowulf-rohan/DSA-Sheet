#include<bits/stdc++.h>
using namespace std;

int n, m;

void common(int** arr)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < m; i++)
    {
        mp[arr[0][i]] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mp[arr[i][j]] == i)
            {
                mp[arr[i][j]] = i+1;
                if(i == n-1 && mp[arr[i][j]] == n)
                    cout << arr[i][j] << " ";
            }
        }
    }
}

int main()
{    
    cin >> n >> m;
    
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for(int j = 0 ; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    common(arr);

    for(int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }delete [] arr;

    return 0;
}