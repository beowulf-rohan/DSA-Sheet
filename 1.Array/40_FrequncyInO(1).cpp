#include<bits/stdc++.h>

using namespace std;

// If arr[i] > n && you need count upto arr[i] = [1, n]...
void frequencyCount(vector<int>& arr,int N, int p)
{ 
    for (int i = 0; i < N ; i++) 
		arr[i] = arr[i]-1; 
    
    sort(arr.begin(), arr.end());
    int ind = N;
    for(int i = 0 ; i < N ; i++)
    {
    	if(arr[i] >= N)
       {
	       if(ind == N)
    	        ind = i;
    	    arr[i] = 0;
    	}
    }
    for (int i = 0; i < ind ; i++) 
    	arr[arr[i]%N] += + N; 
    
    for (int i = 0; i < N; i++) 
		arr[i] = arr[i]/N;        
}

// If arr[i] < n....
void frequencycount(vector<int>& arr,int n)
{ 
    vector<int> temp(n);
    
    for(int i = 0; i < n; i++)
    {
        temp[i] = arr[i]-1;
    }
    
    for(int i = 0; i < n; i++)
    {
        temp[temp[i]%n] += n;
    }
    
    for(int i = 0; i < n; i++)
    {
     arr[i] = temp[i]/n;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        frequencycount(arr, n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}