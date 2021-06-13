#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> grid;
    
bool isValid(int row, int col, int n)
{
    for(int i = row-1; i >= 0; i--)
    {
        if(grid[i][col] == 'Q')
            return false;
    }   
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
    {
        if(grid[i][j] == 'Q')
            return false;
    }     
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
    {
        if(grid[i][j] == 'Q')
            return false;
    }   
    return true;
}
    
void nQueens(int row, int n)
{
    if(row == n)
    {
        result.push_back(grid);
        return;
    }   
    for(int i = 0; i < n; i++)
    {
        if(isValid(row, i, n))
        {
            grid[row][i] = 'Q';
            nQueens(row+1, n);
            grid[row][i] = '.';
        }
            
    }
}
    
vector<vector<string>> solveNQueens(int n) 
{
    string s = "";
    for(int i = 0; i < n; i++)
    {
        s += '.';
    }
    for(int i = 0; i < n; i++)
    {
        grid.push_back(s);
    } 
    nQueens(0, n);
    return result;
}


int grid[11][11];
void print(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
    cout << endl;
    return;
}

bool isPossible(int row, int col, int n)
{
    for(int i = row-1; i >= 0; i--)
    {
        if(grid[i][col] == 1)
            return false;
    }
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
    {
        if(grid[i][j] == 1)
            return false;
    }
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
    {
        if(grid[i][j] == 1)
            return false;
    }
    return true;
}

void placeNqueens(int row, int n)
{
    if(row == n)
    {
        print(n);
        return;
    }  
    for(int i = 0; i < n; i++)
    {
        if(isPossible(row, i, n))
        {
            grid[row][i] = 1;
            placeNqueens(row+1, n);
            grid[row][i] = 0;
        }
    }
    return;
}

void placeNQueens(int n)
{
    memset(grid, 0, sizeof(grid));
    placeNqueens(0, n);
}