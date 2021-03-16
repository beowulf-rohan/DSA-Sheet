#include<bits/stdc++.h>
using namespace std;


// TC - O(32*rlogc).... SC - O(1)....
int findMedian(vector<vector<int>> &arr)
{
    int r = arr.size();
    int c = arr[0].size();
    
    int minE = INT_MAX, maxE = INT_MIN;
    for(int i = 0; i < r; i++)
    {
        minE = min(minE, arr[i][0]);
        maxE = max(maxE, arr[i][c-1]);
    }
    
    int desired = (r*c+1)/2;
    while(minE < maxE)
    {
        int mid = minE + (maxE-minE)/2;
        int place = 0;
        for(int i = 0; i < r; i++)
        {
            place += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }
        
        if(place < desired)
            minE = mid+1;
        else
            maxE = mid;
    }
    return minE;
}