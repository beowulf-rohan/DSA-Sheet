#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[], int n)
{
    // Smallest Left.....
    stack<pair<int, int>> s1;
    int left[n];
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
    stack<pair<int, int>> s2;
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
    int ans = 0, width;
    for(int i = 0; i < n; i++)
    {
        width = right[i] - left[i] - 1;
        ans = max(ans, width*arr[i]);
    }
        
    return ans;
}
    
int maximalRectangle(vector<vector<char>>& matrix) 
{
    int n = matrix.size();
    if(n == 0)
        return 0;
    int m = matrix[0].size();
    int arr[201] = {0};
    int maxArea = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == '1')
                arr[j] += 1;
            else
                arr[j] = 0;
        }
        maxArea = max(maxArea, getMaxArea(arr, m));
    }
    return maxArea;
}