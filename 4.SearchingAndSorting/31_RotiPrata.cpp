#include <iostream>
using namespace std;

bool check(int* arr, int n, int mid, int targetRoti)
{
	int roti = 0;
	for(int i = 0; i < n; i++)
	{
		int time = arr[i];
		int j = 2;
		while(time <= mid)
		{
			roti++;
			time += (arr[i]*j);
			j++;
		}
		if(roti >= targetRoti)
			return 1;
	}
	return 0;
}

int rotiPrata(int* arr, int n, int roti)
{
	int low = 0, high = 1e8;
	int ans = -1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(check(arr, n, mid, roti))
		{
			ans = mid;
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int roti, n;
		cin >> roti >> n;
		
		int arr[n];
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		cout << rotiPrata(arr, n, roti) << endl;
	}
	return 0;
}