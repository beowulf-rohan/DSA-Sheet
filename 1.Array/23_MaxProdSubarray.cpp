#include<iostream>
#include<vector>

using namespace std;

int maxProduct(vector<int>& nums)
{
    int maxP = nums[0];
    int minP = nums[0];
    int maxOverall = nums[0];
        
    for(int i = 1; i < nums.size(); i++)
    {
        int x = nums[i];
        if(x < 0)
            swap(maxP, minP);
        maxP = max(x, x*maxP);
        minP = min(x, x*minP);
            
        maxOverall = max(maxP, maxOverall);
    }
    return maxOverall;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << maxProduct(nums) << endl;
    }
    return 0;
}