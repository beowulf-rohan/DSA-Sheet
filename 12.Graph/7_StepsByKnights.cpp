#include<bits/stdc++.h>
using namespace std;

bool check(int x, int y, int N)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
{
    int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dp[N][N];
	bool visited[N][N];
	    
    memset(dp, 0, sizeof(dp));
	memset(visited, false, sizeof(dp));
	    
    int sX = KnightPos[0]-1, sY = KnightPos[1]-1;
	int tX = TargetPos[0]-1, tY = TargetPos[1]-1;
	    
	if(sX == tX && sY == tY)
        return dp[sX][sY];
	queue<pair<int,int>> pending;
    pending.push({sX, sY});
	visited[sX][sY] = true;
	    
	while(pending.size() != 0)
    {
	    pair<int, int> p = pending.front();
	    pending.pop();
	    
	    int currX = p.first, currY = p.second;
	    for(int i = 0; i < 8; i++)
	    {
	        int nextX = currX+dx[i], nextY = currY+dy[i];
	        if(check(nextX, nextY, N) && !visited[nextX][nextY])
	        {
                pending.push({nextX, nextY});
	            visited[nextX][nextY] = true;
	            
	            dp[nextX][nextY] = 1+dp[currX][currY];
	                
	            if(nextX == tX && nextY == tY)
	                return dp[tX][tY];
	        }
	    }
	}
}