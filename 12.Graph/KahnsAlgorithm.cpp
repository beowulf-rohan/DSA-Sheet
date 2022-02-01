#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> edges[]) 
{
	vector<int> indegree(V, 0);
	for(int i = 0; i < V; i++)
    {
	    for(int j = 0; j < edges[i].size(); j++)
	    {
	        indegree[edges[i][j]]++;
        }
	}
	    
	queue<int> pending;
    for(int i = 0; i < V; i++)
	{
	    if(indegree[i] == 0)
            pending.push(i);
	}
	    
    vector<int> output;
	while(pending.size() != 0)
    {
	    int curr = pending.front();
	    pending.pop();
        output.push_back(curr);
	    for(int i = 0; i < edges[curr].size(); i++)
	    {
	        int nextV = edges[curr][i];
	        indegree[nextV]--;
	        if(indegree[nextV] == 0)
	            pending.push(nextV);
        }
	}
    
	return output;      
    //to check if a graph is acyclic we can use Kahn's algo...
    //if size of output == V, then graph is acyclic 
    //else it contains a cycle and is cyclic
    
    //return (output.size() == V) ? false : true;
}