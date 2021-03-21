#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], bool* visited, int n, vector<int> &v, int sv)
{
    if(visited[sv])
        return;
        
    v.push_back(sv);
    visited[sv] = true;
    for(int i = 0; i < adj[sv].size(); i++)
    {
        int nextSv = adj[sv][i];
        if(!visited[nextSv])
            bfs(adj, visited, n, v, nextSv);
    }
}
    
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
	bool* visited = new bool[V]();
   for(int i = 0; i < V; i++)
	{
       visited[i] = false;
	}
    vector<int> v;
    bfs(adj, visited, V, v, 0);
	return v;
}