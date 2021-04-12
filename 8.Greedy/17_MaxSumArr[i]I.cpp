#include<bits/stdc++.h>
#define mod 1000000007;

using namespace std;

int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    sort(arr, arr+n);
	    
	    long long int sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        sum += i*arr[i];
	        sum %= mod;
	    }
	    
	    cout << sum << '\n';
	}
	return 0;
}