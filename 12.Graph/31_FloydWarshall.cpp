#include<bits/stdc++.h>
using namespace std;


// TC - O(V3).... SC - O(1).... {In Place}
void shortest_distance(vector<vector<int>> &matrix)
{
	int V = matrix.size();
    		
	for (int k = 0; k < V; k++)
	{
	    for (int i = 0; i < V; i++)
	    {
		    for (int j = 0; j < V; j++) 
		    {
		        if (matrix[i][k] != -1 and matrix[k][j] != -1 and matrix[i][j] != -1)
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); 
	        }
		}
	}
}