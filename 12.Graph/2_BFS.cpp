#include<bits/stdc++.h>
using namespace std;

vector<int>bfsOfGraph(int V, vector<int> adj[])
{
	bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
	{
        visited[i] = false;
	}
	    
    vector<int> v;
	queue<int> pending;
    pending.push(0);
	visited[0] = true;
	    
    while(pending.size() != 0)
	{
	    int front = pending.front();
	    pending.pop();
	    v.push_back(front);
        for(int i = 0; i < adj[front].size(); i++)
	    {
	        int nextSv = adj[front][i];
	        if(!visited[nextSv])
            {
	            visited[nextSv] = true;
	            pending.push(nextSv);
	        }
	    }
	}	    
	return v;
}