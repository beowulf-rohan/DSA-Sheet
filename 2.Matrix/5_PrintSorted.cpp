#include<bits/stdc++.h>
using namespace std;


//TC - O(N*N*log(N*N))... SC - O(N*N)....
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

//TC - O(N*N*log(N))... SC - O(N)....
#include<queue>
typedef pair<int, pair<int, int>> pp;
vector<int> sortedMatrix(vector<vector<int>> &mat, int n) 
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    for(int i = 0; i < n; i++)
        pq.push({mat[i][0], {i, 0}});
    
    vector<int> output;
    while(pq.size() != 0)
    {
        pp top = pq.top();
        pq.pop();
        
        output.push_back(top.first);
        
        int i = top.second.first, j = top.second.second;
        if(j != n-1)
            pq.push({mat[i][j+1], {i, j+1}});
    }
    return output;
}