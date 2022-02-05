#include<bits/stdc++.h>
using namespace std;

// Adjacecy List....
int getMin(int* weight, bool* visited, int n)
{
	int minVertex = -1;
    for(int i = 0; i < n; i++)
	{
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
	        minVertex = i;
	}
    return minVertex;
}
	
vector <int> dijkstra(int V, vector<vector<int>> edge[], int S)
{
    bool* visited = new bool[V];
    int* dist = new int[V];
        
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
        
    dist[S] = 0;
        
    int count = 0;
    while(count != V-1)
    {
        int minVertex = getMin(dist, visited, V);
        visited[minVertex] = true;
            
        for(int i = 0; i < edge[minVertex].size(); i++)
        {
            int nextV = edge[minVertex][i][0], d = edge[minVertex][i][1];
            if(!visited[nextV])
            {
                if(d + dist[minVertex] < dist[nextV])
                    dist[nextV] = d + dist[minVertex];
            }
        }
        count++;
    }
        
    vector<int> v;
    for(int i = 0; i < V; i++)
    {
        v.push_back(dist[i]);
    }
    return v;
}


// Adjacecy Matrix....
int findMinVertex(bool* visited, int* distance, int n)
{
    int minVertex = -1;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void dijkstra(int** edges, int n, int sv)
{
    bool* visited = new bool[n];
    int* distance = new int[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;     distance[i] = INT_MAX;
    }
    
    distance[sv] = 0;
    
    for(int i = 0; i < n-1; i++)
    {
        int minVertex = findMinVertex(visited, distance, n);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++)
        {
            if(edges[minVertex][j] != 0 && !visited[j])
            {
                int tempDistance = distance[minVertex] + edges[minVertex][j];
                if(tempDistance < distance[j])
                    distance[j] = tempDistance;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    delete [] visited;
    delete [] distance;
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
        int f, s, d;
        cin >> f >> s >> d;
        edges[f][s] = d;    edges[s][f] = d;
    }

    cout << endl;
    dijkstra(edges, n, 0);

    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}