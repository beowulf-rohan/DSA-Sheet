#include<bits/stdc++.h>
using namespace std;

long long int minCost(int* x, int* y, int m, int n)
{
	sort(x, x+m, greater<int>());
	sort(y, y+n, greater<int>());
	
	long long int cost = 0;
	int i = 0, j = 0;
	int hor = 1, ver = 1;
	while(i < m && j < n)
	{
		if(x[i] > y[j])
		{
			cost += x[i]*ver;
			i++;	hor++;
		}
		else
		{
			cost += y[j]*hor;
			j++;	ver++;
		}
	}
	
	while(i < m)
	{
		cost += x[i]*ver;
		i++;
	}
	
	while(j < n)
	{
		cost += y[j]*hor;
		j++;
	}
	
	return cost;
}