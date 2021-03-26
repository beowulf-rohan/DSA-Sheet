#include<bits/stdc++.h>
using namespace std;

int a[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
bool visited[101][101];
int size;


bool isValid(int x, int y, int N, int M)
{
    return (x >= 0 && y >= 0 && x < N && y < M);
}

bool dfs(vector<vector<char>> &grid, string word, int index, int x, int y, int N, int M)
{
    if(index == size)
        return true;
    
    visited[x][y] = true;
    bool found = false;
    
    for(int i = 0; i < 8; i++)
    {
        int newX = x + a[i][0];
        int newY = y + a[i][1];
        if(isValid(newX, newY, N, M) && (grid[newX][newY] == word[index]) && !visited[newX][newY])
        {
            found = found|dfs(grid, word, index+1, newX, newY, N, M);
        }
    }
    visited[x][y] = false;
    return found;
}

vector<vector<int>>searchWord(vector<vector<char>> &grid, string word)
{
	memset(visited, false, sizeof(visited));	 
    size = word.size();
	int N = grid.size(), M = grid[0].size();
    vector<vector<int>> output;
	for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
	        if(grid[i][j] == word[0] && dfs(grid, word, 1, i, j, N, M))
	        {
	            vector<int> v;
	            v.push_back(i);   v.push_back(j);
                output.push_back(v);
	        }
	    }
    }
	return output;
}