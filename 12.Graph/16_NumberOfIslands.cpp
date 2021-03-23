#include<bits/stdc++.h>
using namespace std;


// TC - O(n*m).... SC - O(n*m)....
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int n, m;

bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
    
void dfs(vector<vector<char>>& grid, bool** visited, int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 8; i++)
    {
        int nextX = x+dx[i], nextY = y+dy[i];
        if(check(nextX, nextY) && !visited[nextX][nextY] && grid[nextX][nextY] == '1')
            dfs(grid, visited, nextX, nextY);
    }
}
    
int numIslands(vector<vector<char>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
        
    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m]();
    }
        
    int count = 0;
    for(int i =  0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && grid[i][j] == '1')
            {
                count++;
                dfs(grid, visited, i, j);
            }
        }
    }
        
    for(int i = 0; i < n; i++)
    {
        delete [] visited[i];
    }
    delete [] visited;
        
    return count;
}