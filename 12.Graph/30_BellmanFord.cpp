#include<bits/stdc++.h>
using namespace std;

// TC - (V*E).... SC - O(V)....
int isNegativeWeightCycle(int n, vector<vector<int>>edges)
{
	int distance[n];
    for(int i = 0; i < n; i++)
	{
        distance[i] = INT_MAX;
	}
	    
	distance[0] = 0;
	for(int i = 0; i < n-1; i++)
    {
	    for(int j = 0; j < edges.size(); j++)
	    {
            int src = edges[j][0];
            int dest = edges[j][1];
	        int wt = edges[j][2];
	        if(distance[src] != INT_MAX && distance[src]+wt < distance[dest])
	        {
	            distance[dest] = distance[src]+wt;
    	    }
        }
	}
	    
    for(int i = 0; i < edges.size(); i++)
    {
	    int src = edges[i][0];
        int dest = edges[i][1];
	    int wt = edges[i][2];
	        
	    if(distance[src] != INT_MAX && distance[src]+wt < distance[dest])
	        return 1;
	}
	    
	return 0;
}