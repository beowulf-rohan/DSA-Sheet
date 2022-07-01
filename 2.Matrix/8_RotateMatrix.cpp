#include<bits/stdc++.h>
using namespace std;

int n, m;

// TC - O(n2).... SC - O(1)....
// CLOCKWISE
void rotate1(int** arr)
{
    //Transpose....
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    //Reverse Column....
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m/2; j++)
        {
            swap(arr[j], arr[m-j-1]);
        }
    }
    //Print
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

// CLOCKWISE
void rotate1(int** arr)
{
    //Reverse Column....
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m/2; j++)
        {
            swap(arr[j], arr[m-j-1]);
        }
    }
    //Transpose....
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    //Print
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

void rotate2(int** arr)
{
    /*
    00 01 02              20 10 00
    10 11 12    --->>>    21 11 01
    20 21 22              22 12 02
    */
    for(int j = 0; j < m; j++)
    {
        for(int i = n-1; i >= 0; i--)
        {
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}
