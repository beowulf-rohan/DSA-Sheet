#include<bits/stdc++.h>
using namespace std;

#define N 9

bool findEmpty(int grid[N][N], int &row, int &col)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 0)
            {
                row = i;    col = j;
                return true;
            }
        }
    }
    return false;
}
    
bool isSafe(int grid[N][N], int row, int col, int num)
{
    for(int i = 0; i < N; i++)
    {
        if(grid[row][i] == num)
            return false;
    }
        
    for(int i = 0; i < N; i++)
    {
        if(grid[i][col] == num)
            return false;
    }
        
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[i+rowFactor][j+colFactor] == num)
                return false;
        }
    }
        
    return true;
}
    
bool SolveSudoku(int grid[N][N])  
{ 
    int row, col;
    if(!findEmpty(grid, row, col))
        return true;
        
    for(int i = 1; i <= 9; i++)
    {
        if(isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if(SolveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
    
void printGrid (int grid[N][N]) 
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}