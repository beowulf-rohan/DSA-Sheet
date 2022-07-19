#include<bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>>& mat, int n) 
{
    int maxMat[n][n];
    maxMat[n-1][n-1] = mat[n-1][n-1];
    for(int i = n-2; i >= 0; i--)
    {
        maxMat[i][n-1] = max(maxMat[i+1][n-1], mat[i][n-1]);
    }
    for(int i = n-2; i >= 0; i--)
    {
        maxMat[n-1][i] = max(maxMat[n-1][i+1], mat[n-1][i]);
    }
    
    int maxValue = INT_MIN;
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = n-2; j >= 0; j--)
        {
            maxValue = max(maxValue, maxMat[i+1][j+1]-mat[i][j]);
            maxMat[i][j] = max(mat[i][j], max(maxMat[i+1][j], maxMat[i][j+1]));
        }
    }
    return maxValue;
}