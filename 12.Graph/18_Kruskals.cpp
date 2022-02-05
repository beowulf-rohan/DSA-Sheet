#include<bits/stdc++.h>
using namespace std;


//Union by Rank and Path Compression....

class Edge{
    public: int source, destination, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void setUnion(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskals(Edge* input, int n, int e)
{
    sort(input, input+e, compare);

    vector<int> parent(n);
    vector<int> rank(n);
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge* output = new Edge[n-1];
    int count = 0, i = 0;
    while(count != n-1)
    {
        Edge curr = input[i];
        int sourceParent = findParent(parent, curr.source);
        int destinationParent = findParent(parent, curr.destination);

        if(sourceParent != destinationParent)
        {
            output[count] = curr;
            setUnion(parent, rank, sourceParent, destinationParent);
            count++;
        }
        i++;
    }

    int sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        Edge curr = output[i];
        cout << curr.source << " " << curr.destination << " " << curr.weight << endl;
        sum += curr.weight;
    }

    delete [] output;

    return sum;
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    Edge* input = new Edge[e];
    for(int i = 0; i < e; i++)
    {
        cin >> input[i].source >> input[i].destination >> input[i].weight;
    }
    
    cout << kruskals(input, n, e);
    
    delete [] input;
    
    return 0;
}

//Union Find Algothirm....
/*
class Edge
{
    public  :   int source, destination, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int* parent, int p)
{
    if(parent[p] == p)
        return p;
    return findParent(parent, parent[p]);
}

int kruskals(Edge* input, int n, int e)
{
    sort(input, input+e, compare);
    
    Edge* output = new Edge[n-1];
    int* parent = new int[n];
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    int i = 0, count = 0;
    while(count != n-1)
    {
        Edge curr = input[i];
        int sourceP = findParent(parent, curr.source);
        int destP = findParent(parent, curr.destination);
        
        if(sourceP != destP)
        {
            output[count] = curr;
            parent[sourceP] = destP;
            count++;
        }
        i++;
    }
    
    int sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        sum += output[i].weight;
    }
    
    delete [] output;
    delete [] parent;
    
    return sum;
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    Edge* input = new Edge[e];
    for(int i = 0; i < e; i++)
    {
        cin >> input[i].source >> input[i].destination >> input[i].weight;
    }
    
    cout << kruskals(input, n, e);
    
    delete [] input;
    
    return 0;
}
*/