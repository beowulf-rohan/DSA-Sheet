#include<iostream>
#include<algorithm>
using namespace std;

int bSearch(int* arr, int si, int ei, int p)
{
	int ans = -1;
	while(si <= ei)
	{
		int mid = (si+ei)/2;
		if(arr[mid] <= p)
		{
			ans = mid;
			si = mid+1;
		}
		else
		{
			ei = mid-1;
		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;

	int arr[n], sum[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
    
    sort(arr, arr+n);
    
    int s = 0;
	for(int i = 0; i < n; i++)
    {
        s += arr[i];
        sum[i] = s;
    }

    int q;
	cin >> q;
	while(q--)
	{
		int p;
		cin >> p;

		int pos = bSearch(arr, 0, n-1, p);
		if(pos == -1)
			cout << "0 0";
		else
			cout << pos+1 << " " << sum[pos];
		cout << endl;
	}
}