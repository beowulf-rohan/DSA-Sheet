#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

typedef long long int ll;

ll findSubarray(vector<ll> arr, int n )
{
    unordered_map<ll, ll> mp;
    
    ll sum = 0;
    ll count = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
            count++;
        
        if(mp[sum])
            count += mp[sum];
        
        mp[sum]++;
    }
    return count;
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << findSubarray(arr,n) << endl;
    }
	return 0;
}