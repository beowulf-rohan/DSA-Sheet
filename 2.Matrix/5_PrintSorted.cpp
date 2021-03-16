#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat)
{
    int arr[n*n];
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[k++] = mat[i][j];
        }
    }
        
    sort(arr, arr+n*n);
    k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = arr[k++];
        }
    }
    return mat;
}