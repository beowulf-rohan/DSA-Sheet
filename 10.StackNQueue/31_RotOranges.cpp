
#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// TC - O(R*C).... SC - O(R*C)....
bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
    
int orangesRotting(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    int count = 0;
    queue<pair<int, int>> pending;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                pending.push({i,j});
            }
        }
    }
        
    pending.push({-1,-1});
        
    while(pending.size() != 0)
    {
        bool changed = false;
        while(pending.front().first != -1 && pending.front().second != -1)
        {
            pair<int,int> front = pending.front();
            pending.pop();
            for(int i = 0; i < 4; i++)
            {
                int newX = front.first + dx[i], newY = front.second + dy[i];
                if(isValid(newX, newY, n, m) && grid[newX][newY] == 1)
                {
                    if(!changed)
                    {
                        changed = true;
                        count++;
                    }
                    grid[newX][newY] = 2;
                    pending.push({newX, newY});
                }
            }
        }
        pending.pop();
        if(pending.size() != 0)
            pending.push({-1,-1});
    }
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
                return -1;
        }
    }
        
    return count;
}

// TC - O(max(R,C)*R*C).... SC - O(1)....
bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
    
int orangesRotting(vector<vector<int>>& grid)
{
    int count = 2;
    int n = grid.size(), m = grid[0].size();
    bool visited = false;
    while(true)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                if(grid[i][j] == count)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int newX = i+dx[k], newY = j + dy[k];
                        if(isValid(newX, newY, n, m) && grid[newX][newY] == 1)
                        {
                            grid[newX][newY] = grid[i][j]+1;
                            visited = true;
                        }
                    }
                }
            }
        }
        if(!visited)
            break;
        visited = false;
        count++;
    }
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
                return -1;
        }
    }        
    return count-2;
}