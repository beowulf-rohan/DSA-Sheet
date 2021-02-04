#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void getSum(ll* arr, int si, int ei, vector<ll> &v)
{
	ll size = (ei-si+1);
	for(ll mask = 0; mask < (1<<size); mask++)
	{
		ll sum = 0;
		ll i = si;
		ll curr = mask;
		while(curr)
		{
			if(curr&1)
				sum += arr[i];
			i++;
			curr = curr>>1;
		}
		v.push_back(sum);
	}
}

int main()
{
	int n;
	ll a, b;
	cin >> n >> a >> b;
	
	ll arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	vector<ll> v1, v2;
	
	getSum(arr, 0, (n/2)-1, v1);
	getSum(arr, (n/2), n-1, v2);
	
	sort(v2.begin(), v2.end());
	
	ll count = 0;
	for(int i = 0; i < v1.size(); i++)
	{
		ll low = lower_bound(v2.begin(), v2.end(), a-v1[i]) - v2.begin();
		ll high = upper_bound(v2.begin(), v2.end(), b-v1[i]) - v2.begin();
		
		count += (high-low);
	}
	
	cout << count;
	
	return 0;
}