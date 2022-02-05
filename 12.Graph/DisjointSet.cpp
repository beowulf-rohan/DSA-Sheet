#include<bits/stdc++.h>
using namespace std;

void init(vector<int> &rank, vector<int>&parent)
{
    for(int i = 0; i < rank.size(); i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node)
{
    if(node == parent[node])
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

int main()
{
    int size = 5;
    vector<int> rank(size), parent(size);
    init(rank, parent);

}