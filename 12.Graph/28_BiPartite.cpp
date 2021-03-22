#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<int>* edges, bool* visited, int sv)
{
    unordered_set<int> sets[2];
	vector<int> pending;
	    
	pending.push_back(sv);
    sets[0].insert(sv);
	    
	while(pending.size() != 0)
    {
	    int curr = pending.back();
	    pending.pop_back();
        visited[curr] = true;
	    int currSet = sets[0].count(curr) > 0 ? 0 : 1;
	    for(int i = 0; i < edges[curr].size(); i++)
        {
	        int neighbour = edges[curr][i];
	        // Not in both sets so add it in the set which
	        // does not contain curr... i.e. 1-currSet...
	        if(sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0)
	        {
	            sets[1-currSet].insert(neighbour);
	            pending.push_back(neighbour);
	        }
	        // It is in the same set as curr so it has same
	        // colour... hence return false
            else if(sets[currSet].count(neighbour) > 0)
	            return false;
	        // It is in opposite the set so do nothing
	        // as it has different colour....
	        else if(sets[1-currSet].count(neighbour) > 0)
	            continue;
	    }
	}
	return true;
}

bool isBipartite(int n, vector<int>* edges)
{
	bool* visited = new bool[n]();
    for(int i = 0; i < n; i++)
	{
        visited[i] = false;
	}
	    
	for(int i = 0; i < n; i++)
    {
	    if(!visited[i])
	    {
	        bool isTrue = checkBipartite(edges, visited, i);
	        if(!isTrue)
	            return false;
        }
	}
    return true;
}