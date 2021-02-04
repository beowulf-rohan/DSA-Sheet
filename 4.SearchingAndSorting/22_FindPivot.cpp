#include<iostream>

using namespace std;


int pivot(int arr[], int n)
{
    int si = 0, ei = n-1;
        
    while(si < ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid] > arr[ei])
            si = mid+1;
        else if(arr[mid] < arr[ei])
            ei = mid;
        else
            ei--;
    }
    return arr[si];
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

        cout << pivot(arr, n) << endl;
    }
    return 0;
}