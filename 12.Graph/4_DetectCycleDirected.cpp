#include<bits/stdc++.h>
using namespace std;


// TC - O(V + E).... SC - O(V)....
bool checkCycle(vector<int>* &adj, bool* visited, bool* stack, int sv)
{
    stack[sv] = true;
    visited[sv] = true;
    
    for(int i = 0; i < adj[sv].size(); i++)
    {
        int nextSv = adj[sv][i];
        if(!visited[nextSv])
        {
            if(checkCycle(adj, visited, stack, nextSv))
                return true;
        }
        else if(stack[nextSv])
            return true;
    }
        
    stack[sv] = false;
    return false;
}

bool isCyclic(int V, vector<int>* adj)
{
   	bool* visited = new bool[V];
	bool* stack = new bool[V];
	   	
   	for(int i = 0; i < V; i++)
	{
	    visited[i] = false;
	   	stack[i] = false;
	}
	   	
	for(int i = 0; i < V; i++)
	{
	   	if(!visited[i] && checkCycle(adj, visited, stack, i))
	   	    return true;
	}
    return false;
	   	
   	delete [] visited;
	delete [] stack;
}