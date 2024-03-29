#include<iostream>
#include<vector>

using namespace std;

int bSearch(vector<int>nums, int l, int r, int X)
{
    if(l > r)
        return -1;
    
    int mid = (l+r)/2;
    
    if(nums[mid] == X)
        return mid;
    
    if(nums[l] <= nums[mid])
    {
        if(X >= nums[l] && X <= nums[mid])
            return bSearch(nums, l, mid-1, X);
        else
            return bSearch(nums, mid+1, r, X);
    }
    else
    {
        if(X >= nums[mid] && X <= nums[r])
            return bSearch(nums, mid+1, r, X);
        else
            return bSearch(nums, l, mid-1, X);
    }
}