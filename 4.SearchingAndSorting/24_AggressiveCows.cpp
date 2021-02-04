#include <iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

bool check(ll* pos, int c, int n, ll X)
{
	ll lastPos = pos[0];
	int count = 1;
	for(int i = 1; i < n; i++)
	{
		if(pos[i]-lastPos >= X)
		{
			count++;
			lastPos = pos[i];
		}
		if(count == c)
			return true;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, c;
		cin >> n >> c;
		
		ll pos[n];
		for(int i = 0; i < n; i++)
		{
			cin >> pos[i];
		}
	
		sort(pos, pos+n);
		
		ll si = 0, ei = pos[n-1]-pos[0];
		int ans = -1;
	
		while(si <= ei)
		{
			ll mid = (si+ei)/2;
			if(check(pos, c, n, mid))
			{
				ans = mid;
				si = mid+1;
			}
			else
			{
				ei = mid-1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}