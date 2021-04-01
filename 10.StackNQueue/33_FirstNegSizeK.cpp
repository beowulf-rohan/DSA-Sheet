#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int* arr, int n, int k)
{
    deque<int> dq;
    vector<int> v;
    
    for(int i = 0; i < k; i++)
    {
        if(arr[i] < 0)
            dq.push_back(i);
    }
    
    if(dq.size() == 0)
        v.push_back(0);
    else
        v.push_back(arr[dq.front()]);
    
    for(int i = k; i < n; i++)
    {
        while(dq.size() != 0 && dq.front() <= i-k)
            dq.pop_front();

        if(arr[i] < 0)
            dq.push_back(i);
            
        if(dq.size() == 0)
            v.push_back(0);
        else
            v.push_back(arr[dq.front()]);
    }
    
    return v;
}


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
	    
	    int k;
	    cin >> k;
	    
	    vector<int> v = firstNegative(arr, n, k);
	    for(int i = 0; i < v.size(); i++)
	    {
	        cout << v[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}