#include<bits/stdc++.h>

using namespace std;

void getInorder(int* arr, int n, vector<int>&v, int treeIndex)
{
    if(treeIndex >= n)
        return;
    
    getInorder(arr, n, v, 2*treeIndex+1);
    v.push_back(arr[treeIndex]);
    getInorder(arr, n, v, 2*treeIndex+2);
}

int minSwaps(int* input, int n)
{
    vector<int> v;
    
    getInorder(input, n, v, 0);
    
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].first = v[i];
        arr[i].second = i;
    }
    
    sort(arr.begin(), arr.end());
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == arr[i].second)
            continue;
        
        swap(arr[i], arr[arr[i].second]);
        count++;
        i--;
    }
    
    return count;
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
    
    cout << minSwaps(arr, n) << endl;
    
    return 0;
}