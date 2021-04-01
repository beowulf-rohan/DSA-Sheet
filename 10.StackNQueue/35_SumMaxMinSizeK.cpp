#include<bits/stdc++.h>
using namespace std;

// 7 3 2 5 -1 7 -3 -1 -2

int sumOfKSubArray(int* arr, int n, int k)
{
    int sum = 0;
    deque<int> S(k), G(k);
    for(int i = 0; i < k; i++)
    {
        while(S.size() != 0 && arr[S.back()] >= arr[i])
            S.pop_back();
        while(G.size() != 0 && arr[G.back()] <= arr[i])
            G.pop_back();
        
        S.push_back(i);
        G.push_back(i);
    }

    sum += arr[S.front()] + arr[G.front()];

    for(int i = k; i < n; i++)
    {
        while(S.size() != 0 && S.front() <= i-k)
            S.pop_front();
        while(G.size() != 0 && G.front() <= i-k)
            G.pop_front();
        
        while(S.size() != 0 && arr[S.back()] >= arr[i])
            S.pop_back();
        while(G.size() != 0 && arr[G.back()] <= arr[i])
            G.pop_back();
        
        S.push_back(i);
        G.push_back(i);
        sum += arr[S.front()] + arr[G.front()];
    }
    return sum;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << sumOfKSubArray(arr, n, k);

    return 0;
}