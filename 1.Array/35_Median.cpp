#include<bits/stdc++.h>

using namespace std;

int find_median(vector<int> v)
{
	sort(v.begin(), v.end());
	int val;
	if(v.size()%2 == 0)
    {
		int i1 = v.size()/2;
        int i2 = i1-1;
		val = (v[i1]+v[i2])/2;
	}
	else
	{
        int i1 = (v.size())/2;
		val = v[i1];
	}
	return val;
}