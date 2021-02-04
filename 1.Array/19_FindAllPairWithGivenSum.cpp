//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int req = k - arr[i];
            if (mp[req] > 0)
            {
                count += mp[req];
                if (req == arr[i])
                    count--;
            }
        }
        return count / 2;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
} // } Driver Code Ends