#include<bits/stdc++.h>
using namespace std;

int maxSumAbsDiff(int* arr, int n)
{
    sort(arr, arr+n);

    vector<int> v;
    for(int i = 0; i < n/2; i++)
    {
        v.push_back(arr[i]);
        v.push_back(arr[n-i-1]);
    }

    if(n%2 != 0)
        v.push_back(arr[n/2]);
    
    int sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        sum += abs(v[i]-v[i+1]);
    }
    
    sum += abs(v[0]-v[n-1]);
    
    return sum;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxSumAbsDiff(arr, n) << endl;

    return 0;
}