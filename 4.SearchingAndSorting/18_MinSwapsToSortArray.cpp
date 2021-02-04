#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minSwaps(int a[], int n)
{
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].first = a[i];
        arr[i].second = i;
    }
    
    sort(arr.begin(), arr.end());
    
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(i == arr[i].second)
            continue;
        
        count++;
        swap(arr[i], arr[arr[i].second]);
        i--;
    }
    return count;
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

        cout << minSwaps(arr, n) << endl;
    }
    return 0;
}