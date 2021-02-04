#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0 || n == 1)
        return;
        
    int k;
    for(k = n-2; k >= 0; k--)
    {
        if(nums[k] < nums[k+1])
            break;
    }
        
    if(k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        int l;
        for(l = n-1; l > k; l--)
        {
            if(nums[k] < nums[l])
                break;
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        nextPermutation(arr);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}