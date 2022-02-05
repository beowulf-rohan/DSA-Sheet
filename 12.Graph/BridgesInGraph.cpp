#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> output;

void dfs(vector<int>* edges, vector<int> &visited, vector<int> &low, vector<int> &tin, int &timer, int node, int parent)
{
    visited[node] = 1;
    low[node] = tin[node] = timer++;
        
    for(auto it : edges[node])
    {
        if(it == parent)
            continue;
        if(!visited[it])
        {
            dfs(edges, visited, low, tin, timer, it, node);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node])
                output.push_back({node, it});
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}
    
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0], v = connections[i][1];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> visited(n, 0);
    vector<int> low(n, -1);
    vector<int> tin(n, -1);
    int timer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(edges, visited, low, tin, timer, i, -1);
    }
    delete [] edges;
    return output;
}