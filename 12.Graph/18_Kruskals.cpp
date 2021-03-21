#include<bits/stdc++.h>
using namespace std;

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