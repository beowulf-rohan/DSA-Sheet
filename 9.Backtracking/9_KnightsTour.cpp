#include<bits/stdc++.h>
using namespace std;
#define n 8

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void printGrid(int grid[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }cout << endl;
    }
}

bool isValid(int grid[n][n], int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == -1);
}

bool fillGrid(int grid[n][n], int x, int y, int count)
{
    if(count == n*n)
        return true;
    
    for(int k = 0; k < n; k++)
    {
        int newX = x+dx[k], newY = y+dy[k];
        if(isValid(grid, newX, newY))
        {
            grid[newX][newY] = count;
            if(fillGrid(grid, newX, newY, count+1))
                return true;
            else
                grid[newX][newY] = -1;
        }
    }
    return false;
}

void solveKnightsTour()
{
    int grid[n][n];
    memset(grid, -1, sizeof(grid));
    grid[0][0] = 0;
    cout << "Filling Grid .......\n\n";
    if(fillGrid(grid, 0, 0, 1))
        printGrid(grid);
    else
        cout << "Solution does not exist";
}

int main()
{
    solveKnightsTour();
    return 0;
}