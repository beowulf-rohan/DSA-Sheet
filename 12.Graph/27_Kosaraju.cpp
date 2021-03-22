#include<bits/stdc++.h>
using namespace std;

void setFalse(bool* visited, int n)
{
	for(int i = 0; i < n; i++)
    {
	    visited[i] = false;
	}
}
	
void dfs1(vector<int>* edges, bool* visited, stack<int>& st, int sv)
{
	visited[sv] = true;
    for(int i = 0; i < edges[sv].size(); i++)
	{
	    int nextSv = edges[sv][i];
	    if(!visited[nextSv])
            dfs1(edges, visited, st, nextSv);
	}
    st.push(sv);
}
	
void getTranspose(vector<int>* edges, vector<int>* edgesT, int n)
{
	for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < edges[i].size(); j++)
	    {
            edgesT[edges[i][j]].push_back(i);
	    }
	}
}
	
void dfs2(vector<int>* edges, bool* visited, int sv)
{
	visited[sv] = true;
    for(int i = 0; i < edges[sv].size(); i++)
	{
	    int nextSv = edges[sv][i];
	    if(!visited[nextSv])
	        dfs2(edges, visited, nextSv);
	}
}
	
int kosaraju(int n, vector<int> edges[])
{
    bool* visited = new bool[n];
    setFalse(visited, n);
        
    //fill stack....
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs1(edges, visited, st, i);
    }
    setFalse(visited, n);
        
    //transpose edges....
    vector<int> edgesT[n];
    getTranspose(edges, edgesT, n);
        
    //count components....
    int count = 0;
    while(st.size() != 0)
    {
        int sv = st.top();
        st.pop();
        if(!visited[sv])
        {
            dfs2(edgesT, visited, sv);
            count++;
        }
    }
        
    return count;
}