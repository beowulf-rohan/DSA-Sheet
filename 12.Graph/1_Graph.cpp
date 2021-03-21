#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int* visited, int sv, int n)
{
    cout << sv << " ";  visited[sv] = true;
    
    for(int i = 0; i < edges[sv].size(); i++)
    {
        int nextSv = edges[sv][i];
        if(!visited[nextSv])
            dfs(edges, visited, nextSv, n);
    }
}

void DFS(vector<int>* edges, int n)
{
    int* visited = new int[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    cout << "\nDFS : ";
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(edges, visited, i, n);
    }
    delete [] visited;
}


void bfs(vector<int>* edges, int* visited, int sv, int n)
{
    queue<int> pending;
    
    pending.push(sv);   visited[sv] = true;
    
    while(pending.size() != 0)
    {
        int curr = pending.front();
        pending.pop();
        cout << curr << " ";
        for(int i = 0; i < edges[curr].size(); i++)
        {
            int nextSv = edges[curr][i];
            if(!visited[nextSv])
            {
                pending.push(nextSv);   visited[nextSv] = true;
            }
        }
    }
}

void BFS(vector<int>* edges, int n)
{
    int* visited = new int[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    cout << "\nBFS : ";
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            bfs(edges, visited, i, n);
    }
    delete [] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f].push_back(s);
    }

    DFS(edges, n);

    BFS(edges, n);

    delete [] edges;

    return 0;
}