#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int ll;


ll countTriplets(ll arr[], int n, ll sum)
{
	ll count = 0;	                
	
    sort(arr, arr+n);
	                
    for(int i = 0; i < n; i++)
    {
	    int targetSum = sum-arr[i];
	    int j =  i+1, k = n-1;
	    while(j < k)
	    {
	        if(arr[j]+arr[k] < targetSum)
	        {
	            count += (k-j);
	            j++;
	        }
	        else
            {
	            k--;
            }
	    }
	}
    return count;
}