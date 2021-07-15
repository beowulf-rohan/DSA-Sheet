#include<iostream>
#include<vector>

using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
	    if(i+1 == arr[i])
	        ans.push_back(arr[i]);
	}
	return ans;
}