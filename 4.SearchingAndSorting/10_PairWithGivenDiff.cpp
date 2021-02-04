#include<iostream>
#include<algorithm>

using namespace std;

bool bSearch(int* arr, int si, int ei, int X)
{
    while(si <= ei)
    {
        int mid = (si+ei)/2;
        
        if(arr[mid] == X)
            return true;
            
        if(X <= arr[mid])
            ei = mid-1;
        else
            si = mid+1;
    }
    
    return false;
}

int search(int* arr, int n, int x)
{
    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++)
    {
        if(bSearch(arr, i+1, n-1, x+arr[i]))
            return 1;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << search(arr, n, x) << endl;
    }
	return 0;
}