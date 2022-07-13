#include <iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
 
bool check(ll* arr, int n, ll m, ll ht)
{
	ll cutSum = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > ht)
			cutSum += (arr[i]-ht);
	}
		return (cutSum >= m);
}
 
int main()
{
	int n;
	ll m, low = INT64_MAX, high = INT64_MIN;
	cin >> n >> m;
	
	ll* arr = new ll[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	low = *min_element(arr, arr + n); 
	high = *max_element(arr, arr + n); 
	
	int ans = 0;
	
	while(low <= high)
	{
		ll mid = (low+high)/2;
		if(check(arr, n, m, mid))
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	
	cout << ans;
	
	delete [] arr;
	return 0;
} 