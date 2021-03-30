#include<bits/stdc++.h>
using namespace std;

// less optimized....
long long getMaxArea(long long arr[], int n)
{
    // Smallest Left.....
    stack<pair<long long int, int>> s1;
    long long int left[n];
    for(int i = 0; i < n; i++)
    {
        while(s1.size() != 0 && s1.top().first >= arr[i])
            s1.pop();
            
        if(s1.size() == 0)
            left[i] = -1;
        else
            left[i] = s1.top().second;
            
        s1.push({arr[i], i});
    }
        
        
    // Smallest Right....
    stack<pair<long long int, int>> s2;
    long long int right[n];
    for(int i = n-1; i >= 0; i--)
    {
        while(s2.size() != 0 && s2.top().first >= arr[i])
            s2.pop();
        
        if(s2.size() == 0)
            right[i] = n;
        else
            right[i] = s2.top().second;
            
        s2.push({arr[i], i});
    }
        
    // Calcualte Answer....
    long long int ans = 0, width;
    for(int i = 0; i < n; i++)
    {
        width = right[i] - left[i] - 1;
        ans = max(ans, width*arr[i]);
    }
        
    return ans;
}

// more optimized....
long long getMaxArea(long long arr[], int n)
{
    // Smallest Left.....
    stack<int> s1;
    vector<long long int> left(n);
    for(int i = 0; i < n; i++)
    {
        while(s1.size() != 0 && arr[s1.top()] >= arr[i])
            s1.pop();
            
        if(s1.size() == 0)
            left[i] = -1;
        else
            left[i] = s1.top();
            
        s1.push(i);
    }
        
    // Smallest Right....
    stack<int> s2;
    vector<long long int> right(n);
    for(int i = n-1; i >= 0; i--)
    {
        while(s2.size() != 0 && arr[s2.top()] >= arr[i])
            s2.pop();
            
        if(s2.size() == 0)
            right[i] = n;
        else
            right[i] = s2.top();
            
        s2.push(i);
    }
        
    // Calcualte Answer....
    long long int ans = 0, width;
    for(int i = 0; i < n; i++)
    {
        width = right[i] - left[i] - 1;
        ans = max(ans, width*arr[i]);
    }
        
    return ans;
}