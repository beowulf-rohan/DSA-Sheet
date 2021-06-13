#include<bits/stdc++.h>
using namespace std;

void ratInMaze(vector<vector<int>> &maze, vector<string> &v, string path, int i, int j, int n)
{
    if(i == n-1 && j == n-1 && maze[i][j] == 1)
    {
        v.push_back(path);
        return;
    }
        
    if(i < 0 || j < 0 || i == n || j == n || maze[i][j] != 1)
        return;
        
        
    maze[i][j] = -1;
    ratInMaze(maze, v, path+'L', i, j-1, n);
    ratInMaze(maze, v, path+'R', i, j+1, n);
    ratInMaze(maze, v, path+'U', i-1, j, n);
    ratInMaze(maze, v, path+'D', i+1, j, n);
    maze[i][j] = 1;
        
}
    
vector<string> findPath(vector<vector<int>> &maze, int n) 
{
    vector<string> v;
    string path = "";
    ratInMaze(maze, v, path, 0, 0, n);
    if(v.size() == 0)
    {
        vector<string> temp;
        temp.push_back("-1");
            return temp;
    }
        
    sort(v.begin(), v.end());
    return v;
}


int sol[20][20];

void print(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << sol[i][j] << " ";
        }
    }
    cout << endl;
}

void ratInMaze(int maze[][20], int row,int col, int n)
{
    if(row == n-1 && col == n-1)
    {
        sol[row][col] = 1;
        print(n);
        sol[row][col] = 0;
        return;
    }
    
    if(row < 0 || row == n || col < 0 || col == n || maze[row][col] == 0 || sol[row][col] == 1)
        return;
    
    sol[row][col] = 1;
    
    ratInMaze(maze, row, col-1, n);
    ratInMaze(maze, row, col+1, n);
    ratInMaze(maze, row-1, col, n);
    ratInMaze(maze, row+1, col, n);
    
    sol[row][col] = 0;
}

void ratInAMaze(int maze[][20], int n)
{
    memset(sol, 0, sizeof(sol));
    ratInMaze(maze, 0, 0, n);
}