#include<bits/stdc++.h>
using namespace std;

int a[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

bool isValid(int x, int y, int N, int M)
{
    return (x >= 0 && y >= 0 && x < N && y < M);
}
    
bool search(vector<vector<char>> &grid, string word, int x, int y, int N, int M)
{
    for(int i = 0; i < 8; i++)
    {
        int nextX = x+a[i][0], nextY = y+a[i][1];
        int j;
        for(j = 1; j < word.size(); j++)
        {
            if(isValid(nextX, nextY, N, M) && grid[nextX][nextY] == word[j])
            {
                nextX += a[i][0];       nextY += a[i][1];
            }
            else
                break;
        }
        if(j == word.size())
            return true;
    }
    return false;
}

vector<vector<int>>searchWord(vector<vector<char>> &grid, string word)
{
    int N = grid.size(), M = grid[0].size();
	vector<vector<int>> output;
	for(int i = 0; i < N; i++)
	{
	    for(int j = 0; j < M; j++)
	    {
	        if(grid[i][j] == word[0] && search(grid, word, i, j, N, M))
	        {
	            vector<int> v;
	            v.push_back(i);   v.push_back(j);
	            output.push_back(v);
	        }
	    }
    }
	return output;
}