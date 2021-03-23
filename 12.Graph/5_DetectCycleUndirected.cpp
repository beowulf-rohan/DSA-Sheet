#include<bits/stdc++.h>
using namespace std;


// TC - O(V + E).... SC - O(V)....
bool checkCycle(vector<int>* &adj, bool* visited, int sv, int parent)
{
    visited[sv] = true;
        
    for(int i = 0; i < adj[sv].size(); i++)
    {
        int nextSv = adj[sv][i];
        if(!visited[nextSv])
        {
            if(checkCycle(adj, visited, nextSv, sv))
                return true;
        }
        else if(nextSv != parent)
            return true;
    }
    return false;
}
    
bool isCycle(int V, vector<int>* adj)
{
    bool* visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
	    visited[i] = false;
	}
	    
	for(int i = 0; i < V; i++)
    {
	    if(!visited[i] && checkCycle(adj, visited, i, -1))
	        return true;
	}
	    
	return false;
}