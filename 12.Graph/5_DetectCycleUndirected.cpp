#include<bits/stdc++.h>
using namespace std;


// TC - O(V + E).... SC - O(V)....
bool checkCycle(vector<int>* adj, int currV, int parent, bool* visited)
{
    visited[currV] = true;
    for(int i = 0; i < adj[currV].size(); i++)
    {
        int nextV = adj[currV][i];
        if(!visited[nextV])
        {
            if(checkCycle(adj, nextV, currV, visited))
                return true;
        }
        else if(nextV != parent)
            return true;
    }
    return false;
}
    
bool isCycle(int V, vector<int> adj[]) 
{
    bool visited[V] = {0};
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(checkCycle(adj, i, -1, visited))
                return true;
        }
    }
    return false;
}