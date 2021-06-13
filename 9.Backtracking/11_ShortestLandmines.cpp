#include<bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

bool isValid(int x, int y)
{
    return (x >= 0 && x < R && y >= 0 && y < C);
}

void markBoundaries(int grid[R][C])
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(grid[i][j] == 0)
            {
                for(int k = 0; k < 4; k++)
                {
                    int newX = i + dx[k], newY = j + dy[k];
                    if(isValid(newX, newY))
                        grid[newX][newY] = -1;
                }
            }
        }
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(grid[i][j] == -1)
                grid[i][j] = 0;
        }
    }
}

void findShortestPath(int grid[R][C])
{
    markBoundaries(grid);

    queue<pair<int, int>> pending;
    int dist[R][C];
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < R; i++)
    {
        if(grid[i][0] == 1)
        {
            dist[i][0] = 0;
            pending.push({i, 0});
        }
    }

    while(pending.size() != 0)
    {
        pair<int, int> curr = pending.front();
        pending.pop();
        int i = curr.first, j = curr.second;
        int d = dist[i][j];
        for(int k = 0; k < 4; k++)
        {
            int newX = i + dx[k], newY = j + dy[k];
            if(isValid(newX, newY) && grid[i][j] == 1 && dist[newX][newY] == -1)
            {
                dist[newX][newY] = d+1;
                pending.push({newX, newY});
            }
        }
    }

    int minD = INT_MAX;
    for(int i = 0; i < R; i++)
    {
        if(dist[i][C-1] != -1 && grid[i][C-1] == 1)
            minD = min(minD, dist[i][C-1]);
    }

    cout << minD;
}

int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    findShortestPath(mat);
}