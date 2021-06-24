#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int> x, vector<int> y)
{
	int n = x.size(), m = y.size();
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	int maxW = INT_MIN, maxH = INT_MIN;
	for(int i = 1; i < n; i++)
	{
		maxW = max(maxW, x[i]-x[i-1]-1);
	}
	for(int i = 0; i < m; i++)
	{
		maxH = max(maxH, y[i]-y[i-1]-1);
	}
	
	return (maxW*maxH);
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, c;
		cin >> n >> m >> c;
		
		vector<int> x, y;
		x.push_back(0);		y.push_back(0);
		for(int i = 0; i < c; i++)
		{
			int a, b;
			cin >> a >> b;
			x.push_back(a);		y.push_back(b);
		}
		x.push_back(n+1);	y.push_back(m+1);
		
		cout << solve(x, y) << endl;
	}
	return 0;
}