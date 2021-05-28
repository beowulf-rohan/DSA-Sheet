#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m) 
{
    int maxIndex = -1;
	int j = m-1;
	    
	for (int i = 0; i < n; i++) 
    {
        while (j >= 0 && arr[i][j] == 1) 
        {
            j = j - 1;
            maxIndex = i; // Update max_row_index
        }
    }
	return maxIndex;
}