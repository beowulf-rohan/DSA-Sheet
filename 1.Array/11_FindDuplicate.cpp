#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int findDuplicate(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int idx = abs(nums[i]);
        if(nums[idx] < 0)
            return idx;
        nums[idx] = -nums[idx];
    }
    return -1;
}
