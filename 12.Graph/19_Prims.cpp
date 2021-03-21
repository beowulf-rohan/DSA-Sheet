#include<bits/stdc++.h>
using namespace std;

int findMinVertex(bool* visited, int* weights, int n)
{
    int minVertex = -1;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void prims(int** edges, int n, int sv)
{
    bool* visited = new bool[n];
    int* weights = new int[n];
    int* parent = new int[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;     weights[i] = INT_MAX;
    }
    parent[sv] = -1;    weights[sv] = 0;

    for(int i = 0; i < n-1; i++)
    {
        int minVertex = findMinVertex(visited, weights, n);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && edges[minVertex][j] != 0)
            {
                if(edges[minVertex][j] < weights[j])
                {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i < n; i++)
    {
        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weights[i] << endl;
    }

    delete [] visited;
    delete [] weights;
    delete [] parent;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n]();
    }

    for(int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;    edges[s][f] = w;
    }

    prims(edges, n, 0);

    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}