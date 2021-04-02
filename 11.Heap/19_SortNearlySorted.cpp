#include<bits/stdc++.h>
using namespace std;

// More Efficient....
void sortKsorted(int* arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(pq.size() == k)
        {
            if(pq.top() > arr[i])
                arr[idx++] = arr[i];
            else
            {
                arr[idx++] = pq.top();
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else
            pq.push(arr[i]);
    }
    
    while(pq.size() != 0)
    {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

// Less Efficient....
void sortKsorted(int* arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k)
        {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
    
    while(pq.size() != 0)
    {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    sortKsorted(arr, n, k);
	    
	    for(int i = 0; i < n; i++)
	    {
	        cout << arr[i] << " ";
	    }cout << endl;
	}
	return 0;
}