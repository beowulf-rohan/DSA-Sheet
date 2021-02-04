#include<iostream>

using namespace std;

int maxRepeating(int *arr, int n, int k)
{
	for(int i = 0; i < n; i++)
    {
	    arr[arr[i]%k] += k;
	}
	    
	int max = arr[0], result = 0;
	for (int i = 1; i < n; i++) 
    { 
        if (arr[i] >= max) 
        { 
            max = arr[i]; 
            result = i; 
        } 
    } 
    
    for (int i = 0; i< n; i++) 
    {
        arr[i] = arr[i]%k;
    }
    return result;
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

        cout << maxRepeating(arr, n, k) << endl;
    }
    return 0;
}