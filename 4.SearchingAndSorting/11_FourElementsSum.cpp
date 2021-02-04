#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k) 
{
    vector<vector<int>> nums;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size()-2; i++)
    {
        for(int j = i+1; j < arr.size()-1; j++)
        {
            int l = j+1, r = arr.size()-1;
            while(l < r)
            {
                int sum = arr[i] + arr[j] + arr[l] + arr[r];
                if(sum == k)
                {
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(arr[l]);
                    v.push_back(arr[r]);
                    
                    nums.push_back(v);
                    
                    
                    while(arr[l] == v[2] && l < r) l++;
                    while(arr[r] == v[3] && l < r) r--;
                }
                else if(sum < k)
                    l++;
                else
                    r--;
            }
            while(j+1 < arr.size()-1 && arr[j+1] == arr[j]) j++;
        }
        while(i+1 < arr.size() && arr[i+1] == arr[i]) i++;
    }
    
    return nums;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<vector<int>> ans = fourSum(arr, k);

        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i][0] << " " << ans[i][1] << " "  << ans[i][2] << " "  << ans[i][3] << endl;
        }
    }
    return 0;
}