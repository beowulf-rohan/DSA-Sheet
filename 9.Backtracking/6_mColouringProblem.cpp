#include<bits/stdc++.h>
using namespace std;

bool isValid(bool graph[101][101], int* color, int n, int node, int col)
{
    for(int i = 0; i < n; i++)
    {
        if(i != node && graph[i][node] == 1 && color[i] == col)
            return false;
    }
    return true;
}

bool colorGraph(bool graph[101][101], int* color, int m, int n, int node)
{
    if(node == n)
        return true;
        
    for(int i = 1; i <= m; i++)
    {
        if(isValid(graph, color, n, node, i))
        {
            color[node] = i;
            if(colorGraph(graph, color, m, n, node+1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    return colorGraph(graph, color, m, n, 0);
}