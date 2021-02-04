#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
	public:
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
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}